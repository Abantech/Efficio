#include "vector.hpp"
#include <array>

namespace Efficio
{
	class Vector2
	{
	public:
		Vector2();
		Vector2(float x, float y);
		~Vector2();

		float x();
		float y();

		std::array<float, 2> ToArray();

		float DistanceTo(Vector2 v);

		float Length();

		Vector2 operator-(Vector2 v);
	private:
		vmml::vector<2> vector;
	};
}