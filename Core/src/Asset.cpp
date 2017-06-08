#include "Asset.h"

namespace Efficio 
{
	Asset::Asset()
	{
	}

	Asset::~Asset()
	{
	}
	
	std::vector<Sensor> Asset::GetSensors()
	{
		return sensors;
	}
}