#include "Spatial2DData.h"

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			Spatial2DData::Spatial2DData() : position() { }
			Spatial2DData::Spatial2DData(float x, float y) : position(x, y) { }
			Spatial2DData::Spatial2DData(Vector2 vector) : position(vector) { }

			Spatial2DData::~Spatial2DData() { }

			Vector2 Spatial2DData::Position() { return this->position; }

			std::string Spatial2DData::GetDataType() { return "Spatial2D"; }
		}
	}
}