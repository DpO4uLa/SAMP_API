#ifndef PATCH_HPP_
#define PATCH_HPP_

namespace injector
{
	class Patch
	{
		struct Chunk
		{
			std::string mModuleName;
			std::uintptr_t mBaseAddress;
			std::uintptr_t mModuleAddress;
			std::vector<uint8_t> mReplacement;
			std::vector<uint8_t> mOriginal;
			bool mFilled;
		};
	public:
		using List = std::vector<Chunk>;
	protected:
		List mList;
		bool mInstalled;
	public:
		Patch() : mInstalled(false) {}

		void Install()
		{
			if (mInstalled)
				return;
			else
				mInstalled = true;

			std::uintptr_t mModuleAddress;

			for (auto& item : mList)
			{
				if (!item.mModuleAddress && !item.mModuleName.empty()) 
				{
					item.mModuleAddress = reinterpret_cast<std::uintptr_t>(GetModuleHandle(item.mModuleName.data())) + item.mBaseAddress;
				}


			}
		}
	};
} // !namespace injector

#endif // !PATCH_HPP_
