#include "Vector3.h"

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			Vector3::Vector3() : Vector3(0, 0, 0)
			{
			}

			Vector3::Vector3(float x, float y, float z) : vector(x, y, z)
			{
			}

			Vector3::~Vector3()
			{
			}

			float Vector3::x()
			{
				return vector.x();
			}

			float Vector3::y()
			{
				return vector.y();
			}

			float Vector3::z() {
				return vector.z();
			}

			std::array<float, 3> Vector3::ToArray()
			{
				std::array<float, 3> ar = { vector.x(), vector.y(), vector.z() };
				return ar;
			}
			
			float Vector3::DistanceTo(Vector3 v)
			{
				return vector.distance(v.vector);
			}

			float Vector3::Dot(Vector3 v)
			{
				return vector.dot(v.vector);
			}

			float Vector3::Length()
			{
				return vector.length();
			}
		}
	}
}