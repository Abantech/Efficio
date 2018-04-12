#ifndef Vector3_H
#define Vector3_H

#include "vector.hpp"
#include <array>

namespace Efficio
{
	class Vector3
	{
	public:
		Vector3();
		Vector3(float x, float y, float z);
		~Vector3();

		float x();
		float y();
		float z();

		std::array<float, 3> ToArray();

		float DistanceTo(Vector3 v);

		float Dot(Vector3 v);

		float Length();

		Vector3 operator-(Vector3 v);

	private:
		vmml::vector<3> vector;
	};
}
#endif 