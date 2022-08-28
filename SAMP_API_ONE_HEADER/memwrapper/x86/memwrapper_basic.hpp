#ifndef MEMWRAPPER_BASIC_HPP_
#define MEMWRAPPER_BASIC_HPP_

namespace memwrapper {
union memory_pointer {
  protected:
    uintptr_t m_address;
    void*     m_ptr;

  public:
    memory_pointer()                      = default;
    memory_pointer(const memory_pointer&) = default;
    memory_pointer(memory_pointer&&)      = default;

    memory_pointer(uintptr_t address)
        : m_address(address) {}
    memory_pointer(void* ptr)
        : m_ptr(ptr) {}

    template<typename T>
    memory_pointer(T integral)
        : m_address(static_cast<uintptr_t>(integral)) {}

    template<typename T>
    memory_pointer(T* object)
        : m_ptr(reinterpret_cast<void*>(object)) {}

    // The 'm_ptr' will be read-only.
    template<typename T>
    memory_pointer(const T* object)
        : m_ptr(reinterpret_cast<void*>(const_cast<T*>(object))) {}

    void*     get() const { return m_ptr; }
    uintptr_t get_int() const { return m_address; }

    template<typename T>
    T get() const {
        return reinterpret_cast<T>(m_ptr);
    }

    // Assignment operators
    memory_pointer& operator=(const memory_pointer& lvalue) {
        return m_ptr = lvalue.m_ptr, *this;
    }
    memory_pointer& operator=(uintptr_t address) {
        return m_address = address, *this;
    }
    memory_pointer& operator=(void* ptr) { return m_ptr = ptr, *this; }

    // Arithmetic operators
    memory_pointer operator+(const memory_pointer& lvalue) const {
        return memory_pointer(m_address + lvalue.m_address);
    }

    memory_pointer operator-(const memory_pointer& lvalue) const {
        return memory_pointer(m_address - lvalue.m_address);
    }

    // Cast operators
    template<typename T>
    operator T*() const {
        return get<T*>();
    }

    // Logical operators
    operator bool() const { return (m_ptr != nullptr); }
};   // !class memory_pointer

}   // namespace memwrapper

#endif   // !MEMWRAPPER_BASIC_HPP_
