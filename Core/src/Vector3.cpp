#include "Vector3.h"

namespace Efficio
{
	Vector3::Vector3() : Vector3(0, 0, 0) { }

	Vector3::Vector3(float x, float y, float z) : vector(x, y, z) { }

	Vector3::~Vector3() { }

	float Vector3::x() { return vector.x(); }

	float Vector3::y() { return vector.y(); }

	float Vector3::z() { return vector.z(); }

	std::array<float, 3> Vector3::ToArray() { return { vector.x(), vector.y(), vector.z() }; }

	float Vector3::DistanceTo(Vector3 v) { return vector.distance(v.vector); }

	float Vector3::Dot(Vector3 v) { return vector.dot(v.vector); }

	float Vector3::Length() { return vector.length(); }

	static Vector3 Midpoint(Vector3 point1, Vector3 point2) { return (point1 + point2) / 2; }

	Vector3 Vector3::operator-(Vector3 v)
	{
		auto temp = this->vector - v.vector;
		return Vector3(temp.x(), temp.y(), temp.z());
	}

	Vector3 Vector3::operator+(Vector3 v)
	{
		auto temp = this->vector + v.vector;
		return Vector3(temp.x(), temp.y(), temp.z());
	}

	Vector3 Vector3::operator/(float divisor) { return Vector3(vector.x() / divisor, vector.y() /divisor, vector.z() /divisor); }
}