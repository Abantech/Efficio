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

			Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
			{
			}

			Vector3::~Vector3()
			{
			}
		}
	}
}