#include "AssetManager.h"

namespace Efficio
{
	std::shared_ptr<AssetManager> AssetManager::Current()
	{
		static std::shared_ptr<AssetManager> instance = std::shared_ptr<AssetManager>(new AssetManager());
		return instance;
	}

	void AssetManager::AddAsset(std::shared_ptr<Efficio::Asset> asset) { this->assets.push_back(asset); }

	std::vector<std::shared_ptr<Efficio::Asset>> AssetManager::GetAssets() { return this->assets; }
}