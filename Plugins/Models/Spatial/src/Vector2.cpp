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

			Vector2::Vector2(float x, float y) : x(x), y(y)
			{
			}

			Vector2::~Vector2()
			{
			}
		}
	}
}