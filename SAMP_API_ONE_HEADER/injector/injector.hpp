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
			Pointer() = default;

			Pointer(std::uintptr_t aAddress) : mAddress(aAddress) {}
			Pointer(void* aPointer) : mPointer(aPointer) {}
			
			Pointer(const Pointer& aPointer) : mPointer(aPointer.mPointer) {}

			template<typename PointerType>
			Pointer(PointerType aValue) : mPointer( reinterpret_cast<void*>(aValue) ) {}

			/* NOTE:
				This variant is really working (removes const), but => 
				"any attempt to modify a const
				object during its lifetime (6.6.3) results in undefined behavior."
				So, this object will be read-only
			*/
			template<typename PointerType>
			Pointer(const PointerType* aValue) :
				mPointer(reinterpret_cast<void*>(const_cast<PointerType*>(aValue)))
			{}

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
#endif // !__cplusplus >= 201103L || _MSC_VER >= 1800

			/* Arithmetic */
			Pointer operator+(const Pointer& rhs) const { return (mAddress + rhs.mAddress); }
			Pointer operator-(const Pointer& rhs) const { return (mAddress - rhs.mAddress); }
			Pointer operator/(const Pointer& rhs) const { return (mAddress / rhs.mAddress); }
			Pointer operator*(const Pointer& rhs) const { return (mAddress * rhs.mAddress); }
			/*            */

			bool operator ==(const Pointer& rhs) const { return (rhs.mAddress == mAddress); }
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

	static inline bool FlushMemory(const detail::Pointer& aTarget, const std::size_t aSize)
	{
		// https://devblogs.microsoft.com/oldnewthing/20190902-00/?p=102828
		// just call the Flush­Instruction­Cache function and let the operating system figure out whether flushing will actually need to “do anything”.
		return FlushInstructionCache(GetCurrentProcess(), aTarget, aSize) != 0;
	}

	template<typename ReturnType>
	static inline ReturnType ReadMemory(const detail::Pointer& aTarget)
	{
		detail::Guard guard{ aTarget, sizeof(ReturnType) };
		return *aTarget.GetRaw<ReturnType*>();
	}

	template<typename ValueType>
	static inline void WriteMemory(const detail::Pointer& aTarget, const ValueType aValue)
	{
		detail::Guard guard{ aTarget, sizeof(ValueType) };
		*aTarget.GetRaw<ValueType*>() = aValue;

		FlushMemory(aTarget, sizeof(ValueType));
	}

	static inline void CopyMemoryRaw(const detail::Pointer& aTarget, const detail::Pointer& aOrigin,
		const std::size_t aSize)
	{
		detail::Guard guard{ aTarget, aSize };
		detail::Guard guard1{ aOrigin, aSize };
		std::memcpy(aTarget, aOrigin, aSize);

		FlushMemory(aTarget, aSize);
	}

	static inline void FillMemoryRaw(const detail::Pointer& aTarget, const int aValue, const std::size_t aSize)
	{
		detail::Guard guard{ aTarget, aSize };
		std::memset(aTarget, aValue, aSize);

		FlushMemory(aTarget, aSize);
	}

	static inline int CompareMemory(const detail::Pointer& aBuffer1, const detail::Pointer& aBuffer2, 
		const std::size_t aSize)
	{
		detail::Guard guard{ aBuffer1, aSize };
		detail::Guard guard1{ aBuffer2, aSize };
		return std::memcmp(aBuffer1, aBuffer2, aSize);
	}

	static std::uintptr_t SearchPattern(std::string_view aModuleName,
		std::string_view aPattern, std::string_view aMask)
	{
		detail::Pointer handle{ GetModuleHandle(aModuleName.data()) };

		if (!handle)
			return 0u;

		MEMORY_BASIC_INFORMATION mbi{ 0 };
		if (!VirtualQuery(handle, &mbi, sizeof(mbi)))
			return 0u;

		auto dos = reinterpret_cast<IMAGE_DOS_HEADER*>(mbi.AllocationBase);
		auto pe = reinterpret_cast<IMAGE_NT_HEADERS*>(
			reinterpret_cast<std::uintptr_t>(dos) + dos->e_lfanew);

		if (pe->Signature != IMAGE_NT_SIGNATURE)
			return 0u;

		auto current = reinterpret_cast<std::uint8_t*>(mbi.AllocationBase);
		auto end = current + pe->OptionalHeader.SizeOfImage;

		std::size_t i{};
		while (current < end) 
		{
			for (i = 0; i < aMask.size(); i++)
			{
				if (&current[i] >= end)
					break;

				auto mask = aMask[i];
				auto pattern = static_cast<std::uint8_t>(aPattern[i]);
				if ((mask != '?') && pattern != current[i])
					break;
			}

			if (!aMask[i])
				return reinterpret_cast<std::uintptr_t>(current);

			++current;
		}
		return 0u;
	}
} // !namespace injector

#endif // !INJECTOR_HPP_
