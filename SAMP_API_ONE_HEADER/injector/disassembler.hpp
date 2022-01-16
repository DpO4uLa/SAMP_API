#ifndef DISASSEMBLER_HPP_
#define DISASSEMBLER_HPP_

namespace injector
{
	namespace disassembler
	{
		static inline std::uint8_t GetInstructionsSize(const detail::Pointer& aTarget, 
			const std::uint8_t aMinSize = 5)
		{
			hde32s hs;

			std::uint8_t size{ 0 };
			std::uint8_t* target{ aTarget };

			while (size < aMinSize)
			{
				hde32_disasm(target, &hs);

				size += hs.len;
				target += hs.len;
			}

			return size;
		}

		static inline std::uintptr_t RestoreAbsoluteOffset(const detail::Pointer& aRelative, 
			const detail::Pointer& aSource, const std::uint32_t aSize = 5u)
		{
			auto relative = aRelative.Get();
			auto source = aSource.Get();

			return (relative + source + aSize);
		}

		static inline std::uintptr_t GetRelativeOffset(const detail::Pointer& aTarget, 
			const detail::Pointer& aOrigin, const std::uint32_t aSize = 5u)
		{
			auto target = aTarget.Get();
			auto origin = aOrigin.Get();

			return target - (origin + aSize);
		}
	} // !namespace disassembler

} // !namespace injector

#endif // !DISASSEMBLER_HPP_
