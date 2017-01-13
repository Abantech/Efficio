#include "Asset.h"

Efficio::Asset::Asset(std::string name) : name(name)
{
}

Efficio::Asset::~Asset()
{
}

std::string Efficio::Asset::GetName()
{
	return name;
}
