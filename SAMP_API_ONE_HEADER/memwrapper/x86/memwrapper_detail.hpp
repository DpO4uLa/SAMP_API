#ifndef MEMWRAPPER_DETAIL_HPP_
#define MEMWRAPPER_DETAIL_HPP_

namespace memwrapper {
namespace detail {
template<typename T>
union byteof {
    T       value;
    uint8_t bytes[sizeof(T)];

    byteof(T value)
        : value(value) {}
};

enum class CallingConvention { Cdecl, Stdcall, Thiscall, Fastcall };

template<typename Function>
struct function_analyzer;

template<typename Ret, typename... Args>
struct function_analyzer<Ret(__cdecl*)(Args...)> {
    using return_type = Ret;

    static constexpr auto args_count      = sizeof...(Args);
    static constexpr auto call_convention = CallingConvention::Cdecl;
};   // !struct function_analyzer<Ret(__cdecl*)(Args...)>

template<typename Ret, typename... Args>
struct function_analyzer<Ret(__stdcall*)(Args...)> {
    using return_type = Ret;

    static constexpr auto args_count      = sizeof...(Args);
    static constexpr auto call_convention = CallingConvention::Stdcall;
};   // !struct function_analyzer<Ret(__stdcall*)(Args...)>

template<typename Ret, typename... Args>
struct function_analyzer<Ret(__thiscall*)(Args...)> {
    using return_type = Ret;

    static constexpr auto args_count      = sizeof...(Args) - 1;   // ecx/rcx
    static constexpr auto call_convention = CallingConvention::Thiscall;
};   // !struct function_analyzer<Ret(__thiscall*)(Args...)>

template<typename Ret, typename... Args>
struct function_analyzer<Ret(__fastcall*)(Args...)> {
    using return_type = Ret;

    static constexpr auto args_count =
        sizeof...(Args) - 2;   // ecx/rcx, edx/rdx
    static constexpr auto call_convention = CallingConvention::Fastcall;
};   // !struct function_analyzer<Ret(__fastcall*)(Args...)>

template<typename Ret, typename Class, typename... Args>
struct function_analyzer<Ret (Class::*)(Args...)> {
    using return_type = Ret;

    static constexpr auto args_count      = sizeof...(Args);
    static constexpr auto call_convention = CallingConvention::Thiscall;
};   // !struct function_analyzer<Ret(Class::*)(Args...)>

template<CallingConvention>
struct function_caller;

template<>
struct function_caller<CallingConvention::Cdecl> {
    template<typename Ret, typename... Args>
    static inline Ret call(const memory_pointer& fn, Args... args) {
        return fn.get<Ret(__cdecl*)(Args...)>()(args...);
    }
};   // !struct function_caller<CallingConvention::Cdecl>

template<>
struct function_caller<CallingConvention::Stdcall> {
    template<typename Ret, typename... Args>
    static inline Ret call(const memory_pointer& fn, Args... args) {
        return fn.get<Ret(__stdcall*)(Args...)>()(args...);
    }
};   // !struct function_caller<CallingConvention::Stdcall>

template<>
struct function_caller<CallingConvention::Thiscall> {
    template<typename Ret, typename... Args>
    static inline Ret call(const memory_pointer& fn, Args... args) {
        return fn.get<Ret(__thiscall*)(Args...)>()(args...);
    }
};   // !struct function_caller<CallingConvention::Thiscall>

template<>
struct function_caller<CallingConvention::Fastcall> {
    template<typename Ret, typename... Args>
    static inline Ret call(const memory_pointer& fn, Args... args) {
        return fn.get<Ret(__fastcall*)(Args...)>()(args...);
    }
};   // !struct function_caller<CallingConvention::Fastcall>

inline uint32_t get_relative_address(const memory_pointer& to,
                                     const memory_pointer& from,
                                     size_t                oplen = 5) {
    return (to.get_int() - from.get_int() - oplen);
}

inline uint32_t restore_absolute_address(const memory_pointer& imm,
                                         const memory_pointer& from,
                                         size_t                oplen = 5) {
    return (imm.get_int() + from.get_int() + oplen);
}

inline uint32_t align_value(uint32_t value, uint32_t alignment) {
    const uint32_t remainder = (value % alignment);
    return (remainder == 0) ? (value) : (value - remainder + alignment);
}

#pragma pack(push, 1)
struct jmp_relative {
    uint8_t  opcode;
    uint32_t operand;
};
struct call_relative : public jmp_relative {};
struct jcc_relative {
    uint8_t opcode;
    uint8_t opcode2;
    uint32_t operand;
};
#pragma pack(pop)
}   // namespace detail

template<typename Ret, detail::CallingConvention Convention, typename... Args>
inline Ret call_function(const memory_pointer& fn, Args... args) {
    return detail::function_caller<Convention>::template call<Ret, Args...>(
        fn, args...);
}

template<typename Ret, typename... Args>
inline Ret call_cdecl(const memory_pointer& fn, Args... args) {
    return call_function<Ret, detail::CallingConvention::Cdecl, Args...>(
        fn, args...);
}

template<typename Ret, typename... Args>
inline Ret call_winapi(const memory_pointer& fn, Args... args) {
    return call_function<Ret, detail::CallingConvention::Stdcall, Args...>(
        fn, args...);
}

template<typename Ret, typename... Args>
inline Ret call_method(const memory_pointer& fn, Args... args) {
    return call_function<Ret, detail::CallingConvention::Thiscall, Args...>(
        fn, args...);
}

template<typename Ret, typename... Args>
inline Ret call_fast(const memory_pointer& fn, Args... args) {
    return call_function<Ret, detail::CallingConvention::Fastcall, Args...>(
        fn, args...);
}
}   // namespace memwrapper

#endif   // !MEMWRAPPER_DETAIL_HPP_
