#include "Vector2.h"

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			Vector2::Vector2() : Vector2(0, 0)
			{
			}

			Vector2::Vector2(float x, float y) : vector(x, y)
			{
			}

			Vector2::~Vector2()
			{
			}

			float Vector2::x()
			{
				return vector.x();
			}

			float Vector2::y()
			{
				return vector.y();
			}

			std::array<float, 2> Vector2::ToArray()
			{
				std::array<float, 2> ar = { vector.x(), vector.y()};
				return ar;
			}

			float Vector2::DistanceTo(Vector2 v)
			{
				return vector.distance(v.vector);
			}
		}
	}
}