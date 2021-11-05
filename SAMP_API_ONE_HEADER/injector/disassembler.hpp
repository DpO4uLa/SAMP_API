#ifndef DISASSEMBLER_HPP_
#define DISASSEMBLER_HPP_

namespace injector
{
	namespace disassembler
	{
		static inline std::uint8_t GetInstructionSize(detail::Pointer aTarget)
		{
			hde32s hs;
			hde32_disasm(aTarget, &hs);
			return (hs.len);
		}

		static inline std::uint8_t GetInstructionsSize(detail::Pointer aTarget, std::uint8_t aMinSize = 5)
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

		static inline bool IsRelativeInstruction(detail::Pointer aTarget)
		{
			hde32s hs;
			hde32_disasm(aTarget, &hs);
			return ((hs.flags & F_RELATIVE) && (hs.flags & F_IMM32));
		}

		static inline std::uintptr_t GetAbsoluteOffsetFrom(detail::Pointer aTarget, detail::Pointer aSource)
		{
			hde32s hs;
			hde32_disasm(aTarget, &hs);
			return (hs.imm.imm32 + aSource.Get() + hs.len);
		}

		static inline std::uintptr_t GetAbsoluteOffset(detail::Pointer aTarget)
		{
			hde32s hs;
			hde32_disasm(aTarget, &hs);
			return (hs.imm.imm32 + aTarget.Get() + hs.len);
		}

	} // !namespace disassembler

} // !namespace injector

#endif // !DISASSEMBLER_HPP_
