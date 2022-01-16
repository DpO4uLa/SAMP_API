#ifndef PATCH_HPP_
#define PATCH_HPP_

namespace injector
{
	class Patch
	{
		using string_const = std::string_view;

		using byte_vector = std::vector<std::uint8_t>;
		using byte_vector_const = const std::vector<std::uint8_t>&;

		struct Chunk
		{
			std::uintptr_t mTarget;

			byte_vector mReplacement;
			byte_vector mOriginal;
		
			Chunk(string_const aModuleName,
				std::uintptr_t aTarget,
				byte_vector_const aReplacement,
				byte_vector_const aOriginal)
			{
				auto handle = reinterpret_cast<std::uintptr_t>(GetModuleHandle(aModuleName.data()));
	
				mTarget = handle + aTarget;
				mReplacement = aReplacement;

				if (aOriginal.empty())
				{
					mOriginal.resize(mReplacement.size());

					CopyMemoryRaw(mOriginal.data(), mTarget, mReplacement.size());
				}
				else
					mOriginal = aOriginal;
			}
		};

		std::vector<Chunk> mChunks;
		bool mInstalled;
	public:
		~Patch() { Remove(); }

		void Install()
		{
			if (mInstalled || mChunks.empty())
				return;
			else
				mInstalled = true;

			for (auto& item : mChunks)
				CopyMemoryRaw(item.mTarget, item.mReplacement.data(), item.mReplacement.size());
		}

		void Remove()
		{
			if (!mInstalled)
				return;
			else
				mInstalled = false;

			for (auto& item : mChunks)
				CopyMemoryRaw(item.mTarget, item.mOriginal.data(), item.mOriginal.size());
		}

		inline void Add(string_const aModuleName, std::uintptr_t aAddress,
			byte_vector_const aReplacement, byte_vector_const aOriginal)
		{
			mChunks.emplace_back<Chunk>({ aModuleName, aAddress, aReplacement, aOriginal });
		}

		inline void Add(string_const aModuleName, std::uintptr_t aAddress,
			byte_vector_const aReplacement)
		{
			Add(aModuleName, aAddress, aReplacement, {});
		}

		inline void Add(std::uintptr_t aAddress,
			byte_vector_const aReplacement)
		{
			Add("", aAddress, aReplacement, {});
		}

		inline void Add(std::uintptr_t aAddress,
			byte_vector_const aReplacement, byte_vector_const aOriginal)
		{
			Add("", aAddress, aReplacement, aOriginal);
		}
	};
} // !namespace injector

#endif // !PATCH_HPP_
