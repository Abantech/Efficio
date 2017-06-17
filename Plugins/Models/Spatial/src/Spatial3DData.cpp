#include "Spatial3DData.h"

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			Spatial3DData::Spatial3DData() { }

			Spatial3DData::Spatial3DData(Vector3 v) : position(&v) { }

			Spatial3DData::~Spatial3DData() { }

			bool Spatial3DData::HasPosition() 
			{
				if (position)
					return true;
				
				return false;
			}

			Vector3 Spatial3DData::GetPosition()
			{
				return *position;
			}

			std::string Spatial3DData::GetDataType()
			{
				return "Spatial3D";
			}
		}
	}
}