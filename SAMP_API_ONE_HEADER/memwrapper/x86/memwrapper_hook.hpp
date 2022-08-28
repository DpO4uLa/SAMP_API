#ifndef MEMWRAPPER_HOOK_HPP_
#define MEMWRAPPER_HOOK_HPP_
#include <memory>
namespace memwrapper {
namespace detail {
struct memhook_context {
    uintptr_t return_address;
};   // struct memhook_context;
}   // namespace detail

template<typename Function>
class memhook {
  protected:
    using memhook_original_code_t = std::unique_ptr<uint8_t[]>;
    using memhook_code_gen_t      = std::unique_ptr<asm_allocator>;

    using function_info = detail::function_analyzer<Function>;
    using return_type   = typename function_info::return_type;

    memory_pointer m_address;
    memory_pointer m_callback;

    size_t m_size;

    memhook_original_code_t m_original_code;
    memhook_code_gen_t      m_code;

    bool m_installed;
    bool m_listing_broken;
    bool m_is_call_instruction;

    uint32_t m_call_abs_address;

  public:
    memhook(const memory_pointer& address, const memory_pointer& callback)
        : m_address(address)
        , m_callback(callback)
        , m_call_abs_address(0)
        , m_size(0)
        , m_original_code(nullptr)
        , m_code(nullptr)
        , m_installed(false)
        , m_listing_broken(false)
        , m_is_call_instruction(false) {
        auto cursor = m_address.get<uint8_t*>();

        while (m_size < 5) {
            hde32s hs;
            hde32_disasm(cursor, &hs);

            m_listing_broken = (hs.flags & F_ERROR);
            if (m_listing_broken)
                break;

            cursor += hs.len;
            m_size += hs.len;
        }
    }

    ~memhook() { remove(); }

    void install() {
        if (m_listing_broken)
            return;

        if (m_installed)
            return;

        if (!is_executable(m_address))
            return;

        if (m_code) {
            // installing jmp to callback again
            m_code->set_offset(0xB);
            m_code->jmp(m_callback);

            // flushing memory
            m_code->ready();

            // marking as installed
            m_installed = true;
            return;
        } else {
            hde32s hs;
            hde32_disasm(m_address, &hs);

            if (hs.opcode == 0xE8) {
                m_is_call_instruction = true;
                m_call_abs_address =
                    detail::restore_absolute_address(hs.imm.imm32, m_address);
            }
        }

        // creating original code and trampoline code instances
        m_original_code = std::make_unique<uint8_t[]>(m_size);
        m_code          = std::make_unique<asm_allocator>();

        // copying original instructions from the target address
        copy_memory(m_original_code.get(), m_address, m_size);

        // generating trampoline

        // storing eax, cuz he doesn't have to be always zero
        m_code->push(Registers::Eax);
        // mov eax, dword ptr[esp + 4]; + 4 because we pushed eax into the stack
        m_code->mov(Registers::Eax, Registers::Esp, sizeof(uint32_t));
        // mov dword ptr[ctx.return_address], eax; moving return address
        // into our context
        m_code->mov(&ctx.return_address, Registers::Eax);
        // restoring eax from the stack
        m_code->pop(Registers::Eax);

        // jumping to 'hook-function'
        m_code->jmp(m_callback);

        if (!m_is_call_instruction)
            generate_trampoline();

        m_code->ready();

        // installing patch
        auto address = m_address.get_int();
        auto rel32   = detail::get_relative_address(m_code->begin(), address);
        if (!m_is_call_instruction)
            write_memory<uint8_t>(address, 0xE9);

        write_memory<uint32_t>(address + 1, rel32);

        if (m_size > 5)
            fill_memory(address + 5, 0x90, m_size - 5);

        // mark as installed
        m_installed = true;
    }

    void remove() {
        if (!m_installed)
            return;

        auto unload = [this]() {
            // trying to restore listing/original code
            copy_memory(m_address, m_original_code.get(), m_size);

            // unloading memory block
            m_code->free();

            // reseting smart pointers
            m_original_code.reset();
            m_code.reset();

            // marking as uninstalled
            m_installed           = false;
            m_is_call_instruction = false;
        };

        auto patch_trampoline = [this]() {
            if (m_is_call_instruction) {
                // Redirecting jmp to hooked function
                m_code->set_offset(0xB);
                m_code->jmp(m_call_abs_address);
            } else {
                // Removing jmp to avoid crash/calling detour
                fill_memory(m_code->get(0xB), 0x90, 0x5);
            }

            // flushing memory
            m_code->ready();

            // marking as uninstalled
            m_installed = false;
        };

        hde32s hs;
        hde32_disasm(m_address, &hs);

        // listing broken, or not a rel32 (jmp, call, etc...) instruction
        if ((hs.flags & F_ERROR) || !(hs.flags & F_RELATIVE) ||
            !(hs.flags & F_IMM32))
            return unload();

        uintptr_t destination =
            detail::restore_absolute_address(hs.imm.imm32, m_address, hs.len);
        uintptr_t code = m_code->get<uintptr_t>();

        // if operand is our trampoline code or original absolute call address
        if ((destination == code) || (destination == m_call_abs_address))
            unload();
        else
            patch_trampoline();
    }

    template<typename... Args>
    return_type call(Args... args) {
        return call_function<return_type, function_info::call_convention,
                             Args...>(get_trampoline(), args...);
    }

    uintptr_t get_trampoline() {
        uintptr_t code = m_code->get<uintptr_t>(0x10);
        return (m_is_call_instruction) ? (m_call_abs_address) : (code);
    }

  private:
    void generate_trampoline() {
        detail::call_relative call = { 0xE8, 0x00000000 };
        detail::jmp_relative  jmp  = { 0xE9, 0x00000000 };
        detail::jcc_relative  jcc  = { 0x0F, 0x80, 0x00000000 };

        uint8_t* now  = m_address;
        uint32_t step = 0;

        bool finished = false;
        while (!finished) {
            if (step >= m_size) {
                m_code->jmp(now);
                break;
            }

            void*    opcode;
            uint32_t oplen;

            hde32s   hs;
            uint32_t len = hde32_disasm(now, &hs);

            if (hs.flags & F_ERROR)
                break;

            if (hs.opcode == 0xE8) {
                uintptr_t destination =
                    detail::restore_absolute_address(hs.imm.imm32, now);

                call.operand =
                    detail::get_relative_address(destination, m_code->now());

                opcode = &call;
                oplen  = sizeof(call);
            } else if ((hs.opcode & 0xFD) == 0xE9) {
                uintptr_t destination =
                    reinterpret_cast<uintptr_t>(now + hs.len);
                if (hs.opcode == 0xEB)
                    destination += hs.imm.imm8;
                else
                    destination += hs.imm.imm32;

                jmp.operand =
                    detail::get_relative_address(destination, m_code->now());

                opcode = &jmp;
                oplen  = sizeof(jmp);
            } else if ((hs.opcode & 0xF0) == 0x70 ||
                       (hs.opcode2 & 0xF0) == 0x80) {
                uintptr_t destination =
                    reinterpret_cast<uint32_t>(now + hs.len);
                if ((hs.opcode & 0xF0) == 0x70)
                    destination += hs.imm.imm8;
                else
                    destination += hs.imm.imm32;

                uint8_t cond =
                    ((hs.opcode != 0x0F ? hs.opcode : hs.opcode2) & 0x0F);

                jcc.opcode2 = (0x80 | cond);
                jcc.operand = detail::get_relative_address(
                    destination, m_code->now(), sizeof(jcc));

                opcode = &jcc;
                oplen  = sizeof(jcc);
            } else {
                opcode = now;
                oplen  = len;
            }

            // adding instruction to list
            m_code->db(opcode, oplen);

            // shifting cursor
            step += oplen;
            now += len;
        }
    }

  public:
    detail::memhook_context ctx;
};   // !class memhook<Function>

}   // namespace memwrapper

#endif   // !MEMWRAPPER_HOOK_HPP_
