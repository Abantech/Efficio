#ifndef Vector4_H
#define Vector4_H

#include "vector.hpp"
#include <array>

namespace Efficio
{
	class Vector4
	{
	public:
		Vector4();
		Vector4(float x, float y, float z, float w);
		~Vector4();

		float x();
		float y();
		float z();
		float w();

		std::array<float, 4> ToArray();

		float DistanceTo(Vector4 v);

		float Dot(Vector4 v);

		float Length();

		Vector4 operator-(Vector4 v);
		Vector4 operator+(Vector4 v);
		Vector4 operator/(float divisor);

		static Vector4 Midpoint(Vector4 point1, Vector4 point2);

	private:
		vmml::vector<4> vector;
	};
}
#endif 