#include "vector2.h"
#include <iostream>
Vector2 Vector2::add(Vector2 const& a, Vector2 const& b)
{
	return { a.x + b.x, a.y + b.y };
}
Vector2 Vector2::operator+(Vector2 const& other) const
{
	return add(*this, other);
}

bool Vector2::operator!=(const Vector2& rh) const
{
	return !operator==(rh);
}
bool Vector2::operator==(const Vector2& rh) const
{
	return std::abs(x - rh.x) <= 0.01f && std::abs(y - rh.y) <= 0.01f;
}

Vector2& Vector2::operator+=(const Vector2& vector2)
{
	x += vector2.x;
	y += vector2.y;
	return *this;
}

Vector2& Vector2::operator*(const float value)
{
	x *= value;
	y *= value;
	return *this;
}
Vector2& Vector2::operator*(const double value)
{
	Vector2 newVector2 = Vector2(x * static_cast<float>(value), y * static_cast<float>(value));
	return newVector2;
}

float Vector2::magnitude()
{
	return sqrt(this->x * this->x + this->y * this->y);
}

const Vector2 Vector2::operator/(float value) const
{
	return Vector2(this->y / value, this->y / value);
}

Vector2 Vector2::normalize()
{
	return *this / magnitude();
}

Vector2&& Vector2::operator-(const Vector2& vector2) const
{
	return { this->x - vector2.x, this->y - vector2.y };
}


