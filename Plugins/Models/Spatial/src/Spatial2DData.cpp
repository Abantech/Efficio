#include "Spatial2DData.h"

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			Spatial2DData::Spatial2DData() { }

			Spatial2DData::~Spatial2DData() { }

			std::string Spatial2DData::GetDataType()
			{
				return "Spatial2D";
			}
		}
	}
}