#ifndef MEMWRAPPER_LLMO_HPP_
#define MEMWRAPPER_LLMO_HPP_

namespace memwrapper {
enum class MemoryProt {
    None             = (0),
    NoAccess         = (1 << 1),
    ReadOnly         = (1 << 2),
    ReadWrite        = (1 << 3),
    WriteCopy        = (1 << 4),
    Execute          = (1 << 5),
    ExecuteRead      = (1 << 6),
    ExecuteReadWrite = (1 << 7),
    ExecuteWriteCopy = (1 << 8)
};

namespace detail {
static uint32_t convert_memory_protection_constant(MemoryProt prot) {
    switch (prot) {
    case MemoryProt::NoAccess: return PAGE_NOACCESS;
    case MemoryProt::ReadOnly: return PAGE_READONLY;
    case MemoryProt::ReadWrite: return PAGE_READWRITE;
    case MemoryProt::WriteCopy: return PAGE_WRITECOPY;
    case MemoryProt::Execute: return PAGE_EXECUTE;
    case MemoryProt::ExecuteRead: return PAGE_EXECUTE_READ;
    case MemoryProt::ExecuteReadWrite: return PAGE_EXECUTE_READWRITE;
    case MemoryProt::ExecuteWriteCopy: return PAGE_EXECUTE_WRITECOPY;

    default: return 0;
    }
}
}   // namespace detail

class scoped_unprotect {
  protected:
    void*  m_pointer;
    size_t m_size;
    DWORD  m_protection;
    bool   m_result;

  public:
    scoped_unprotect(const memory_pointer& pointer, size_t size,
                     MemoryProt prot = MemoryProt::ExecuteReadWrite)
        : m_pointer(pointer)
        , m_size(size) {
        auto new_protect = detail::convert_memory_protection_constant(prot);

        m_result = (VirtualProtect(m_pointer, m_size, new_protect,
                                   &m_protection) != 0);
    }

    ~scoped_unprotect() {
        if (good())
            VirtualProtect(m_pointer, m_size, m_protection, &m_protection);
    }

    bool good() { return m_result; }
};   // !class scoped_unprotect

// LLM operations
inline bool flush_memory(const memory_pointer& at, size_t size) {
    return (FlushInstructionCache(GetCurrentProcess(), at, size) != 0);
}

template<typename T>
inline T read_memory(const memory_pointer& at) {
    scoped_unprotect unprotect(at, sizeof(T));
    return *at.get<T*>();
}

template<typename T>
inline void write_memory(const memory_pointer& at, T value) {
    scoped_unprotect unprotect(at, sizeof(T));
    *at.get<T*>() = value;

    flush_memory(at, sizeof(T));
}

inline void fill_memory(const memory_pointer& dst, int value, size_t size) {
    scoped_unprotect unprotect(dst, size);
    std::memset(dst, value, size);
    flush_memory(dst, size);
}

inline void copy_memory(const memory_pointer& dst, const memory_pointer& src,
                        size_t size) {
    scoped_unprotect unprotect(dst, size);
    std::memcpy(dst, src, size);
    flush_memory(dst, size);
}

inline int compare_memory(const memory_pointer& buff1,
                          const memory_pointer& buff2, size_t size) {
    scoped_unprotect unprotect(buff1, size);
    scoped_unprotect unprotect0(buff2, size);
    return std::memcmp(buff1, buff2, size);
}

inline bool is_executable(const memory_pointer& code) {
    constexpr auto flags = (PAGE_EXECUTE | PAGE_EXECUTE_READ |
                            PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY);

    MEMORY_BASIC_INFORMATION mbi{ 0 };
    VirtualQuery(code, &mbi, sizeof(mbi));
    return (mbi.State == MEM_COMMIT) && (mbi.Protect & flags);
}

static uintptr_t search_memory_pattern(std::string_view mod,
                                       std::string_view pattern,
                                       std::string_view mask) {
    memory_pointer handle =
        reinterpret_cast<uint32_t>(GetModuleHandle(mod.data()));

    if (!handle)
        return 0;

    MEMORY_BASIC_INFORMATION mbi{ 0 };
    if (!VirtualQuery(handle, &mbi, sizeof(mbi)))
        return 0;

    auto dos = reinterpret_cast<IMAGE_DOS_HEADER*>(mbi.AllocationBase);
    auto pe  = reinterpret_cast<IMAGE_NT_HEADERS*>(
        reinterpret_cast<uint32_t>(dos) + dos->e_lfanew);

    if (pe->Signature != IMAGE_NT_SIGNATURE)
        return 0;

    auto now = reinterpret_cast<uint8_t*>(mbi.AllocationBase);
    auto end = now + pe->OptionalHeader.SizeOfImage;

    size_t i{ 0 };
    while (now < end) {
        for (i = 0; i < mask.size(); i++) {
            if (&now[i] >= end)
                break;

            auto character = mask[i];
            auto byte      = static_cast<uint8_t>(pattern[i]);

            if (character == '?')
                continue;

            if (now[i] != byte)
                break;
        }

        if (!mask[i])
            return reinterpret_cast<uintptr_t>(now);

        ++now;
    }
    return 0;
}

// RAII LLM operations
template<typename T>
class scoped_write {
  protected:
    void* m_pointer;
    bool  m_initialized;

    T m_data;

  public:
    scoped_write()                    = default;
    scoped_write(const scoped_write&) = delete;
    scoped_write(scoped_write&&)      = delete;

    scoped_write(const memory_pointer& at, T value)
        : m_pointer(at) {
        m_data        = read_memory<T>(at);
        m_initialized = true;

        write_memory<T>(at, value);
    }

    ~scoped_write() { restore(); }

    void install(const memory_pointer& at, T value) {
        m_pointer     = at;
        m_data        = read_memory<T>(at, value);
        m_initialized = true;

        write_memory<T>(at, value);
    }

    void restore() {
        if (m_initialized)
            write_memory<T>(m_pointer, m_data);

        m_initialized = false;
    }
};   // !class scoped_write<T>

template<size_t bufsize>
class scoped_copy {
  protected:
    void* m_pointer;
    bool  m_initialized;

    uint8_t m_buf[bufsize];

  public:
    scoped_copy()                   = default;
    scoped_copy(const scoped_copy&) = delete;
    scoped_copy(scoped_copy&&)      = delete;

    scoped_copy(const memory_pointer& at, const memory_pointer& data)
        : m_pointer(at) {
        copy_memory(m_buf, at, bufsize);
        copy_memory(at, data, bufsize);

        m_initialized = true;
    }

    ~scoped_copy() { restore(); }

    void install(const memory_pointer& at, const memory_pointer& data) {
        m_pointer = at;

        copy_memory(m_buf, at, bufsize);
        copy_memory(at, data, bufsize);

        m_initialized = true;
    }

    void restore() {
        if (m_initialized)
            copy_memory(m_pointer, m_buf, bufsize);

        m_initialized = false;
    }
};   // !class scoped_copy<bufsize>

template<size_t bufsize>
class scoped_fill {
  protected:
    void* m_pointer;
    bool  m_initialized;

    uint8_t m_buf[bufsize];

  public:
    scoped_fill()                   = default;
    scoped_fill(const scoped_fill&) = delete;
    scoped_fill(scoped_fill&&)      = delete;

    scoped_fill(const memory_pointer& at, int value)
        : m_pointer(at) {
        copy_memory(m_buf, at, bufsize);
        fill_memory(at, value, bufsize);

        m_initialized = true;
    }

    ~scoped_fill() { restore(); }

    void install(const memory_pointer& at, int value) {
        m_pointer = at;

        copy_memory(m_buf, at, bufsize);
        fill_memory(at, value, bufsize);

        m_initialized = true;
    }

    void restore() {
        if (m_initialized)
            copy_memory(m_pointer, m_buf, bufsize);

        m_initialized = false;
    }
};   // !class scoped_fill<bufsize>

struct scoped_patch_unit {
    using byte_vector    = std::vector<uint8_t>;
    using string_vector  = std::vector<std::string_view>;
    using address_vector = std::vector<memory_pointer>;

    memory_pointer m_address;
    byte_vector    m_replacement;
    byte_vector    m_original;

  public:
    scoped_patch_unit()                         = delete;
    scoped_patch_unit(const scoped_patch_unit&) = default;
    scoped_patch_unit(scoped_patch_unit&&)      = default;

    scoped_patch_unit(std::string_view mod, const memory_pointer& offset,
                      const byte_vector& replacement,
                      const byte_vector& original)
        : m_replacement(replacement)
        , m_original(original) {
        auto handle = reinterpret_cast<uint32_t>(GetModuleHandle(mod.data()));

        m_address = handle + offset.get_int();
    }

    scoped_patch_unit(std::string_view mod, const memory_pointer& offset,
                      const byte_vector& replacement)
        : m_replacement(replacement) {
        auto handle = reinterpret_cast<uint32_t>(GetModuleHandle(mod.data()));

        m_address = handle + offset.get_int();
        m_original.resize(replacement.size());

        copy_memory(m_original.data(), m_address, m_original.size());
    }

    scoped_patch_unit(const memory_pointer& address,
                      const byte_vector&    replacement,
                      const byte_vector&    original)
        : m_address(address)
        , m_replacement(replacement)
        , m_original(original) {}

    scoped_patch_unit(const memory_pointer& address,
                      const byte_vector&    replacement)
        : m_address(address)
        , m_replacement(replacement) {
        m_original.resize(replacement.size());

        copy_memory(m_original.data(), m_address, m_original.size());
    }

    void install() {
        copy_memory(m_address, m_replacement.data(), m_replacement.size());
    }

    void restore() {
        copy_memory(m_address, m_original.data(), m_original.size());
    }
};   // !class scoped_patch_unit

class scoped_patch {
    std::vector<scoped_patch_unit> m_units;

  public:
    scoped_patch()                    = default;
    scoped_patch(const scoped_patch&) = delete;
    scoped_patch(scoped_patch&&)      = delete;

    scoped_patch(const std::vector<scoped_patch_unit>& units)
        : m_units(units) {}

    ~scoped_patch() { remove(); }

    void install() {
        if (m_units.empty())
            return;

        for (auto& unit : m_units)
            unit.install();
    }

    void remove() {
        if (m_units.empty())
            return;

        for (auto& unit : m_units)
            unit.restore();
    }

    void toggle(bool status) {
        if (status)
            install();
        else
            remove();
    }

    void add(const scoped_patch_unit& unit) { m_units.push_back(unit); }
};   // !class scoped_patch

}   // namespace memwrapper

#endif   // !MEMWRAPPER_LLMO_HPP_
