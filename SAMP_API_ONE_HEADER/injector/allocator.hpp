#ifndef ALLOCATOR_HPP_
#define ALLOCATOR_HPP_

namespace injector
{
	namespace detail
	{
		template<typename ValueType>
		union byteof
		{
			ValueType value;
			std::uint8_t bytes[sizeof(ValueType)];

			explicit byteof(ValueType aValue) : value(aValue) {}
		};

		static inline std::size_t aligned_size(const std::size_t aSize, const std::size_t aAlignment)
		{ 
			const auto remainder = aSize % aAlignment;
			return ((remainder == 0) ? (aSize) : (aSize - remainder + aAlignment)); 
		}
	} // !namespace detail

	class Allocator
	{
		static constexpr auto MEMORY_ALIGNMENT = 4096u;
	
		std::uint8_t* mCode;
		std::uint32_t mOffset;
		std::size_t mSize;
	public:
		explicit Allocator(const std::size_t aSize) :
			mCode(nullptr),
			mOffset(0)
		{
			static_assert(MEMORY_ALIGNMENT % 2u == 0u, "Memory alignment should be multiple of 2");

			mCode = static_cast<std::uint8_t*>(_aligned_malloc(aSize, MEMORY_ALIGNMENT));
			mSize = detail::aligned_size(aSize, MEMORY_ALIGNMENT);
		}

		void db(const std::uint8_t aByte)
		{
			const auto totalSize = mOffset + sizeof(std::uint8_t);
			if (totalSize > mSize)
				Realloc(mSize * 2);

			mCode[mOffset++] = aByte;
		}

		template<typename ValueType>
		void db(ValueType* aObject, const std::size_t aSize)
		{
			std::uint8_t* object{ reinterpret_cast<std::uint8_t*>(aObject) };

			for (auto i = 0u; i < aSize; i++)
				db(object[i]);
		}

		template<typename ValueType>
		void db(ValueType aValue)
		{
			if constexpr (sizeof(ValueType) > 1)
			{
				detail::byteof<ValueType> value { aValue };

				for (auto i = 0u; i < sizeof(ValueType); i++)
					db(value.bytes[i]);
			}
			else
				db(static_cast<std::uint8_t>(aValue));
		}

		template<typename ValueType, typename ... Arguments>
		void insert(const ValueType aValue, Arguments... args)
		{
			db(aValue);

			if constexpr (sizeof...(Arguments) > 1)
				insert(args...);
			else
				db(args...);
		}

		void fill(const std::uint8_t aValue, const std::size_t aSize)
		{
			for (auto i = 0u; i < aSize; i++)
				mCode[mOffset + i] = aValue;
		}

		// Helper functions
		inline void Ready()
		{ FlushMemory(mCode, mSize); }

		inline void SetOffset(const std::uint32_t aOffset)
		{ mOffset = aOffset; }

		inline std::uint8_t* GetCode(const std::uint32_t aOffset = 0) const
		{ return &mCode[aOffset]; }

		inline std::uintptr_t GetRelative(const detail::Pointer& aTarget, const std::size_t aSize = 5u) const
		{ return disassembler::GetRelativeOffset(aTarget, GetCode(mOffset), aSize); }

		inline void Release()
		{ if (mCode) _aligned_free(mCode); }
	private:
		void Realloc(const std::size_t aNewSize)
		{
			// Allocating new code pointer with updated size
			auto code = static_cast<std::uint8_t*>(
				_aligned_malloc(aNewSize, MEMORY_ALIGNMENT)
			);

			auto old = mCode;
			
			auto newSize = detail::aligned_size(aNewSize, MEMORY_ALIGNMENT);
			auto dataSize = std::min(aNewSize, mSize);

			// Copying data from old pointer
			std::memcpy(&code, &old, dataSize);

			// Updating pointer and size
			mCode = code;
			mSize = newSize;

			// Recalculating relative addresses if was
			for (auto i = 0u; i < dataSize;)
			{
				hde32s hs;
				hde32_disasm(code + i, &hs);

				if (hs.flags & F_ERROR)
					break;

				// Only for rel32...
				if ((hs.flags & F_RELATIVE) &&
					(hs.flags & F_IMM32))
				{
					auto destination = disassembler::RestoreAbsoluteOffset(hs.imm.imm32, old + i, hs.len);
					auto relative = disassembler::GetRelativeOffset(destination, code + i, hs.len);

					WriteMemory<std::uintptr_t>(mCode + i + (hs.len - 4), relative);
				}

				i += hs.len;
			}

			// Deleting old pointer to avoid a memory leak
			_aligned_free(old);
		}
	};
} // !namespace injector

#endif // !ALLOCATOR_HPP_
