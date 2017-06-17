#include "vector.hpp"
#include <array>

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			class Vector3
			{
				Vector3();
				Vector3(float x, float y, float z);
				~Vector3();

				float x();
				float y();
				float z();

				std::array<float, 3> ToArray();

				float DistanceTo(Vector3 v);

			private:
				vmml::vector<3> vector;
			};
		}
	}
}