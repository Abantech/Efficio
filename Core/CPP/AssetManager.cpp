#include "AssetManager.h"

int Efficio::AssetManager::AddAsset(std::shared_ptr<Efficio::Asset> asset)
{
	if (asset->ID == 0)
	{
		// Generate ID and assign it to the asset
	}

	assets.emplace(asset->ID, asset);

	return asset->ID;
}

void Efficio::AssetManager::RemoveAsset(int id)
{
	assets.erase(id);
}

void Efficio::AssetManager::RemoveAsset(std::shared_ptr<Efficio::Asset> asset)
{
	RemoveAsset(asset->ID);
}

std::shared_ptr<Efficio::Asset> Efficio::AssetManager::GetAsset(int id)
{
	return assets.at(id);
}
