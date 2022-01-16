#ifndef HOOK_HPP_
#define HOOK_HPP_

namespace injector
{
	namespace detail
	{
		template<typename Out, typename In>
		static constexpr Out force_cast(In in)
		{
			static_assert(sizeof(In) == sizeof(Out));

			Out out;
			std::memcpy(&out, &in, sizeof(Out));

			return out;
		};
	} // !namespace detail

	class Hook
	{
	protected:
		detail::Pointer mSource;
		detail::Pointer mTarget;
		detail::Pointer mCallback;

		std::uint8_t mSize;

		std::unique_ptr<Allocator> mTrampoline;
		std::unique_ptr<std::uint8_t[]> mOriginal;

		bool mInstalled;
		bool mUseCallback;
	public:
		template<typename SourceType, typename TargetType>
		Hook(SourceType aSource, TargetType aTarget) :
			mSource(reinterpret_cast<void*>(aSource)),
			mTarget(detail::force_cast<void*>(aTarget)),
			mCallback(0u),
			mSize(disassembler::GetInstructionsSize(mSource)),
			mOriginal(nullptr),
			mTrampoline(nullptr),
			mInstalled(false),
			mUseCallback(false)
		{}

		~Hook()
		{ Remove(); }

		void Install()
		{
			using disassembler::GetRelativeOffset;

			if (mInstalled)
				return;
			else
				mInstalled = true;

			if (!mOriginal)
			{
				mOriginal = std::make_unique<std::uint8_t[]>(mSize);
			
				CopyMemoryRaw(mOriginal.get(), mSource, mSize);
			}

			hde32s hs;
			hde32_disasm(mSource, &hs);
			if (hs.opcode == 0xE8)
			{
				mUseCallback = true;
				mCallback = disassembler::RestoreAbsoluteOffset(hs.imm.imm32, mSource);
			}

			if (!mTrampoline)
			{
				const auto estimatedSize = mUseCallback ? 5u : (mSize + 10u);

				// Creating trampoline...
				mTrampoline = std::make_unique<Allocator>(estimatedSize);
				mTrampoline->insert<std::uint8_t>(0xE9, mTrampoline->GetRelative(mTarget));

				if (!mUseCallback)
					CreateTrampoline();

				mTrampoline->Ready();
				
				if (!mUseCallback)
					WriteMemory<std::uint8_t>(mSource, 0xE9);
					
				WriteMemory<std::uintptr_t>(mSource + 1, GetRelativeOffset(
					mTrampoline->GetCode(),
					mSource
				));

				if (mSize > 5u)
					FillMemoryRaw(mSource + 5u, 0x90, mSize - 5u);
			}
			else
			{
				mTrampoline->SetOffset(0u);
				mTrampoline->insert<std::uint8_t>(0xE9, mTrampoline->GetRelative(mTarget));
			}
		}

		void Remove()
		{
			using namespace disassembler;

			if (!mInstalled)
				return;
			else
				mInstalled = false;

			hde32s hs;
			hde32_disasm(mSource, &hs);

			if ((hs.flags & F_ERROR) ||
				!(hs.flags & F_IMM32) ||
				!(hs.flags & F_RELATIVE))
				return Free();

			auto destination = RestoreAbsoluteOffset(hs.imm.imm32, mSource, hs.len);
			auto trampoline = detail::Pointer{ mTrampoline->GetCode() };

			if (trampoline == destination || mCallback == destination)
			{
				CopyMemoryRaw(mSource, mOriginal.get(), mSize);
				return Free();
			}
			
			mTrampoline->SetOffset(0u);

			if (!mUseCallback)
				mTrampoline->fill(0x90, 5);
			else
				mTrampoline->insert<std::uint8_t>(0xE9, mTrampoline->GetRelative(mCallback));

			Free(false);
		}

		template<typename ReturnType = void, CallingConventions Convention = CallingConventions::Cdecl, typename ... Arguments>
		ReturnType Call(Arguments... args)
		{
			return CallFunction<ReturnType, Convention>(mUseCallback ? mCallback : mTrampoline->GetCode(5u), args...);
		}
	private:
		void CreateTrampoline()
		{
			void* opcode;
			auto opcodeSize	{ 0u };
			auto step		{ 0u };
			auto source		{ mSource.GetRaw<std::uint8_t*>() };
			auto finished	{ false };

#pragma pack(push, 1)
			struct
			{
				std::uint8_t opcode;
				std::uint32_t operand;
			} call, jmp;

			struct
			{
				std::uint8_t opcode;
				std::uint8_t opcode1;
				std::uint32_t operand;
			} jcc;
#pragma pack(pop)

			while (!finished)
			{
				hde32s hs;
				opcodeSize = hde32_disasm(source, &hs);
			
				if (hs.flags & F_ERROR)
					break;

				/*
					TODO:

					* Arguments copy,
					* Stack clearing...
				
					What it gives to us?:

					* Removes freaking mCallback and mUseCallback fields
				*/
				if (hs.opcode == 0xE8) // This code does nothing now...
				{
					auto destination = disassembler::RestoreAbsoluteOffset(hs.imm.imm32, source, sizeof(call));

					call.opcode = 0xE8;
					call.operand = mTrampoline->GetRelative(destination, sizeof(call));

					opcode = &call;
					opcodeSize = sizeof(call);
				}
				if ((hs.opcode & 0xFD) == 0xE9)
				{
					auto destination = reinterpret_cast<std::uintptr_t>(source) + hs.len;

					if (hs.flags & F_IMM8) // short jump
						destination += hs.imm.imm8;
					else
						destination += hs.imm.imm32;

					jmp.opcode = 0xE9;
					jmp.operand = mTrampoline->GetRelative(destination, sizeof(jmp));

					opcode = &jmp;
					opcodeSize = sizeof(jmp);

					finished = true; // Cuz we already jumped from trampoline
				}
				else if ((hs.opcode == 0x0F) &&
					(hs.flags & F_RELATIVE)) // Any conditional jump
				{
					auto destination = reinterpret_cast<std::uintptr_t>(source) + hs.len;

					if (hs.flags & F_IMM8)
						destination += hs.imm.imm8;
					else
						destination += hs.imm.imm32;

					jcc.opcode = 0x0F;
					jcc.opcode1 = hs.opcode2;
					jcc.operand = mTrampoline->GetRelative(destination, sizeof(jcc));

					opcode = &jcc;
					opcodeSize = sizeof(jcc);

					finished = true;
				}
				else
					opcode = source;

				mTrampoline->db(opcode, opcodeSize);

				source += hs.len;
				step += opcodeSize;
				finished = finished || (step >= mSize);
			}

			mTrampoline->insert<std::uint8_t>(0xE9, mTrampoline->GetRelative(mSource + mSize));
		}

		void Free(bool aUnload = true)
		{
			if (mTrampoline && aUnload) { mTrampoline->Release(); mTrampoline.reset(); mUseCallback = false; }
			if (mOriginal)				{ mOriginal.reset(); }
		}
	};

} // !namespace injector

#endif // !HOOK_HPP_
