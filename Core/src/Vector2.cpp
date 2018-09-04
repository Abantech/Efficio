#include "Vector2.h"

namespace Efficio
{
	Vector2::Vector2() : Vector2(0, 0) { }

	Vector2::Vector2(float x, float y) : vector(x, y) { }

	Vector2::~Vector2() { }

	float Vector2::x() { return vector.x(); }

	float Vector2::y() { return vector.y(); }

	std::array<float, 2> Vector2::ToArray() { return { vector.x(), vector.y() }; }

	float Vector2::DistanceTo(Vector2 v) { return vector.distance(v.vector); }

	float Vector2::Length() { return vector.length(); }

	static Vector2 Midpoint(Vector2 point1, Vector2 point2) { return (point1 + point2) / 2; }

	Vector2 Vector2::operator-(Vector2 v)
	{
		auto temp = this->vector - v.vector;
		return Vector2(temp.x(), temp.y());
	}

	Vector2 Vector2::operator+(Vector2 v)
	{
		auto temp = this->vector + v.vector;
		return Vector2(temp.x(), temp.y());
	}

	Vector2 Vector2::operator/(float divisor) { return Vector2(vector.x() / divisor, vector.y() / divisor); }
}