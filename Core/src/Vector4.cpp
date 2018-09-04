#include "Vector4.h"

namespace Efficio
{
	Vector4::Vector4() : Vector4(0, 0, 0, 0) { }

	Vector4::Vector4(float x, float y, float z, float w) : vector(x, y, z, w) { }

	Vector4::~Vector4() { }

	float Vector4::x() { return vector.x(); }

	float Vector4::y() { return vector.y(); }

	float Vector4::z() { return vector.z(); }

	float Vector4::w() { return vector.w(); }

	std::array<float, 4> Vector4::ToArray() { return { vector.x(), vector.y(), vector.z(), vector.w() }; }

	float Vector4::DistanceTo(Vector4 v) { return vector.distance(v.vector); }

	float Vector4::Dot(Vector4 v) { return vector.dot(v.vector); }

	float Vector4::Length() { return vector.length(); }

	Vector4 Vector4::Midpoint(Vector4 point1, Vector4 point2) { return (point1 + point2) / 2; }

	Vector4 Vector4::operator-(Vector4 v)
	{
		auto temp = this->vector - v.vector;
		return Vector4(temp.x(), temp.y(), temp.z(), temp.w());
	}

	Vector4 Vector4::operator+(Vector4 v)
	{
		auto temp = this->vector + v.vector;
		return Vector4(temp.x(), temp.y(), temp.z(), temp.w());
	}

	Vector4 Vector4::operator/(float divisor) { return Vector4(vector.x() / divisor, vector.y() / divisor, vector.z() / divisor, vector.w() / divisor); }
}