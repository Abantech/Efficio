#include "Vector3.h"
namespace Efficio {
	Vector3::Vector3(float x, float y, float z) : vector(x, y, z)
	{
	}

	Vector3::~Vector3()
	{
	}

	float Vector3::X()
	{
		return vector.x();
	}

	float Vector3::Y() {
		return vector.y();
	}

	float Vector3::Z() {
		return vector.z();
	}
}