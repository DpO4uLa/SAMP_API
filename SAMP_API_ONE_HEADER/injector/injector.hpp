#ifndef INJECTOR_HPP_
#define INJECTOR_HPP_

namespace injector
{
	namespace detail
	{
		union Pointer
		{
		protected:
			void* mPointer;
			std::uintptr_t mAddress;
		public:
			Pointer() : mPointer(nullptr) {}
			Pointer(std::nullptr_t) : mPointer(nullptr) {}
			Pointer(std::uintptr_t aAddress) : mAddress(aAddress) {}
			Pointer(void* aPointer) : mPointer(aPointer) {}
			Pointer(const Pointer& aPointer) : mPointer(aPointer.mPointer) {}

			template<typename PointerType>
			Pointer(PointerType aValue) : mPointer( (void*)aValue ) {}

			template<typename ReturnType>
			inline ReturnType GetRaw() const { return reinterpret_cast<ReturnType>(mPointer); }

			inline void* GetRaw() const { return mPointer; }
			inline std::uintptr_t Get() const { return mAddress; }

			/* Casts */
			template<class ObjectType>
			operator ObjectType*() const { return reinterpret_cast<ObjectType*>(mPointer); }

			// Taken from https://github.com/DK22Pac/plugin-sdk/blob/master/injector/injector.hpp#L86
#if __cplusplus >= 201103L || _MSC_VER >= 1800
			explicit operator bool() const { return mPointer != nullptr; }
#endif

			/* Math */
			Pointer operator+(const Pointer& rhs) const { return (mAddress + rhs.mAddress); }
			Pointer operator-(const Pointer& rhs) const { return (mAddress - rhs.mAddress); }
			Pointer operator/(const Pointer& rhs) const { return (mAddress / rhs.mAddress); }
			Pointer operator*(const Pointer& rhs) const { return (mAddress * rhs.mAddress); }
		};

		class Guard
		{
		protected:
			Pointer mPointer;
			std::size_t mSize;
			DWORD mProtection;
		public:
			Guard(Pointer aPointer, std::size_t aSize, DWORD aProtection = PAGE_EXECUTE_READWRITE) :
				mPointer(aPointer),
				mSize(aSize)
			{
				VirtualProtect(mPointer, mSize, aProtection, &mProtection);
			}

			~Guard()
			{
				VirtualProtect(mPointer, mSize, mProtection, &mProtection);
			}
		};

	} // !namespace detail

	static inline bool FlushMemory(detail::Pointer aTarget, std::size_t aSize)
	{
		// https://devblogs.microsoft.com/oldnewthing/20190902-00/?p=102828
		// just call the Flush­Instruction­Cache function and let the operating system figure out whether flushing will actually need to “do anything”.
		return FlushInstructionCache(GetCurrentProcess(), aTarget, aSize) != 0;
	}

	template<typename ReturnType>
	static inline ReturnType ReadMemory(detail::Pointer aTarget)
	{
		detail::Guard guard{ aTarget, sizeof(ReturnType) };
		return *aTarget.GetRaw<ReturnType*>();
	}

	template<typename ValueType>
	static inline void WriteMemory(detail::Pointer aTarget, ValueType aValue)
	{
		detail::Guard guard{ aTarget, sizeof(ValueType) };
		*aTarget.GetRaw<ValueType*>() = aValue;

		FlushMemory(aTarget, sizeof(ValueType));
	}

	static inline void CopyMemoryRaw(detail::Pointer aTarget, detail::Pointer aOrigin, std::size_t aSize)
	{
		detail::Guard guard{ aTarget, aSize };
		detail::Guard guard1{ aOrigin, aSize };
		std::memcpy(aTarget, aOrigin, aSize);

		FlushMemory(aTarget, aSize);
	}

	static inline void FillMemoryRaw(detail::Pointer aTarget, int aValue, std::size_t aSize)
	{
		detail::Guard guard{ aTarget, aSize };
		std::memset(aTarget, aValue, aSize);

		FlushMemory(aTarget, aSize);
	}

	static inline int CompareMemory(detail::Pointer aBuffer1, detail::Pointer aBuffer2, std::size_t aSize)
	{
		detail::Guard guard{ aBuffer1, aSize };
		detail::Guard guard1{ aBuffer2, aSize };
		return std::memcmp(aBuffer1, aBuffer2, aSize);
	}
} // !namespace injector

#endif // !INJECTOR_HPP_
