#pragma once

#include <map>
#include <string>
#include <memory>

#include "Asset.h"


#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	/// Holds all of the assets in the Efficio system
	extern class DLLEXPORT AssetManager
	{
	public:
		AssetManager() {};
		~AssetManager() {};

		int AddAsset(std::shared_ptr<Efficio::Asset> asset);
		void RemoveAsset(int id);
		void RemoveAsset(std::shared_ptr<Efficio::Asset> asset);
		std::shared_ptr<Efficio::Asset> GetAsset(int id);

	private:
		std::map<int, std::shared_ptr<Efficio::Asset>> assets;
	};
}