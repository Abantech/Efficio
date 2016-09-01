#include "Vector3.h"
namespace Efficio {
	Vector3::Vector3(float x, float y, float z) : vector(x, y, z)
	{
	}

	Vector3::~Vector3()
	{
	}

	float Vector3::DistanceTo(Efficio::Vector3 vector2) {
		vmml::Vector3f vector2vmml(vector2.X(), vector2.Y(), vector2.Z());

		return vector2vmml.distance(vector);;
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