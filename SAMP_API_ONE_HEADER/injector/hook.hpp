#ifndef HOOK_HPP_
#define HOOK_HPP_

namespace injector
{
	namespace detail
	{
		template<typename Out, typename In>
		static constexpr Out force_cast(In in)
		{
			union
			{
				In  in;
				Out out;
			}
			u = { in };

			return u.out;
		};
	} // !namespace detail

	class Hook
	{
	protected:
		detail::Pointer mSource;
		detail::Pointer mTarget;
		detail::Pointer mCallback;

		std::uint8_t mSize;
		std::uint8_t* mTrampoline;

		std::unique_ptr<std::uint8_t[]> mOriginal;

		bool mInstalled;
		bool mUseCallback;
	public:
		template<typename SourceType, typename TargetType>
		Hook(SourceType aSource, TargetType aTarget) :
			mSource(reinterpret_cast<void*>(aSource)),
			mTarget(detail::force_cast<void*>(aTarget)),
			mCallback(0),
			mSize(disassembler::GetInstructionsSize(mSource)),
			mOriginal(nullptr),
			mTrampoline(nullptr),
			mInstalled(false),
			mUseCallback(false)
		{}

		~Hook()
		{
			Remove();
		}

		void Install()
		{
			if (mInstalled)
				return;
			else
				mInstalled = true;

			if (!mOriginal)
			{
				mOriginal = std::make_unique<std::uint8_t[]>(mSize);
			
				CopyMemoryRaw(mOriginal.get(), mSource, mSize);
			}

			if (ReadMemory<std::uint8_t>(mSource) == 0xE8)
			{
				mUseCallback = true;
				mCallback = disassembler::GetAbsoluteOffset(mSource);
			}

			if (!mTrampoline)
			{
				std::uintptr_t trampoline;

				// Creating trampoline...
				mTrampoline = reinterpret_cast<std::uint8_t*>(VirtualAlloc(NULL, mUseCallback ? 5 : (mSize + 10), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE));

				trampoline = reinterpret_cast<std::uintptr_t>(mTrampoline);

				WriteMemory<std::uint8_t>(mTrampoline, 0xE9);
				WriteMemory<std::uintptr_t>(mTrampoline + 1, (mTarget - trampoline - 5).Get());

				if (!mUseCallback)
				{
					CopyMemoryRaw(mTrampoline + 5, mOriginal.get(), mSize);

					WriteMemory<std::uint8_t>(mTrampoline + mSize + 5, 0xE9);
					WriteMemory<std::uintptr_t>(mTrampoline + mSize + 6, (mSource - trampoline - 10).Get());

					PatchInstructions();

					// Installing jump to our trampoline...
					WriteMemory<std::uint8_t>(mSource, 0xE9);
				}

				WriteMemory<std::uintptr_t>(mSource + 1, (trampoline - mSource.Get() - 5));

				if (mSize > 5)
					FillMemoryRaw(mSource + 5, 0x90, mSize - 5);
			}
			else
			{
				auto trampoline = reinterpret_cast<std::uintptr_t>(mTrampoline);

				WriteMemory<std::uint8_t>(mTrampoline, 0xE9);
				WriteMemory<std::uintptr_t>(mTrampoline + 1, (mTarget - trampoline - 5).Get());
			}
		}

		void Remove()
		{
			if (!mInstalled)
				return;
			else
				mInstalled = false;

			if (disassembler::IsRelativeInstruction(mSource))
			{
				detail::Pointer target = disassembler::GetAbsoluteOffset(mSource);

				if (target == mTrampoline)
				{
					CopyMemoryRaw(mSource, mOriginal.get(), mSize);
					Free();
				}
				else
				{
					if (!mUseCallback)
						FillMemoryRaw(mTrampoline, 0x90, 5);
					else
					{
						auto trampoline = reinterpret_cast<std::uintptr_t>(mTrampoline);
						auto callback	= mCallback.Get();

						WriteMemory<std::uintptr_t>(mTrampoline + 1, callback - trampoline - 5);
					}
				
					Free(false);
				}
			}
			else
				Free();
		}

		template<typename ReturnType = void, EConvention Convention = kCdeclcall, typename ... Arguments>
		ReturnType Call(Arguments... args)
		{
			return CallFunction<ReturnType, Convention>(mUseCallback ? mCallback : (mTrampoline + 5), args...);
		}
	private:
		void PatchInstructions()
		{
			std::uintptr_t trampoline = reinterpret_cast<std::uintptr_t>(mTrampoline);
			
			for (int index = 5; index < mSize + 5; index++)
			{
				if (disassembler::IsRelativeInstruction(mTrampoline + index))
				{
					std::uintptr_t dest = disassembler::GetAbsoluteOffsetFrom(mTrampoline + index, mSource);
					std::uint8_t size = disassembler::GetInstructionSize(mTrampoline + index);
					std::uint8_t offset = size - 4;

					WriteMemory<std::uintptr_t>(trampoline + index + offset, (dest - trampoline - index - size));

					index += size;
				}
			}
		}

		void Free(bool aUnload = true)
		{
			if (mTrampoline && aUnload) { VirtualFree(mTrampoline, 0, MEM_RELEASE); mTrampoline = nullptr; mUseCallback = false; }
			if (mOriginal)				{ mOriginal.reset(); }
		}
	};

} // !namespace injector

#endif // !HOOK_HPP_
