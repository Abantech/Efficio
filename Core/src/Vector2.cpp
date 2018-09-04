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

	Vector2 Vector2::operator-(Vector2 v)
	{
		auto temp = this->vector - v.vector;
		return Vector2(temp.x(), temp.y());
	}
}