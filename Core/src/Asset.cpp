#include "Asset.h"

namespace Efficio
{
	Asset::Asset() { }
	Asset::~Asset() { }

	std::vector<std::shared_ptr<Sensor>>  Asset::GetSensors() { return sensors; }
}