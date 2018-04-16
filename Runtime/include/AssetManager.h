#pragma once

#include <memory>
#include "Asset.h"

namespace Efficio
{
	class AssetManager
	{
	public:
		~AssetManager() {};

		void AddAsset(std::shared_ptr<Efficio::Asset> asset);

		std::vector<std::shared_ptr<Efficio::Asset>> GetAssets();

		static std::shared_ptr<Efficio::AssetManager> Current();

	private:
		AssetManager() {};
		AssetManager(AssetManager const&) = delete;
		void operator=(AssetManager const&) = delete;

		std::vector<std::shared_ptr<Efficio::Asset>> assets;
	};
}