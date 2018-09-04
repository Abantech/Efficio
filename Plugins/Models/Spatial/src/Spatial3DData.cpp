#include "Spatial3DData.h"

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			Spatial3DData::Spatial3DData() : position() { }
			Spatial3DData::Spatial3DData(float x, float y, float z) : position(x, y, z) { }
			Spatial3DData::Spatial3DData(Vector3 v) : position(v) { }

			Spatial3DData::~Spatial3DData() { }

			Vector3 Spatial3DData::Position() { return this->position; }

			std::string Spatial3DData::GetDataType() { return "Spatial3D"; }
		}
	}
}