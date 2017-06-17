#include "vector.hpp"
#include <array>

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			class Vector2
			{
				Vector2();
				Vector2(float x, float y);
				~Vector2();

				float x();
				float y();

				std::array<float, 2> ToArray();

			private:
				vmml::vector<2> vector;
			};
		}
	}
}