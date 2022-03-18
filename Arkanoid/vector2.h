#pragma once

struct Vector2
{
	float x;
	float y;

	Vector2(const float x, const float y): x(x), y(y) { }
	Vector2() : x(0), y(0) {}

	static Vector2 add(Vector2 const& a, Vector2 const& b);

	Vector2 operator + (Vector2 const& other) const;
	bool operator!=(const Vector2& rh) const;
	bool operator==(const Vector2& rh) const;
	::Vector2& operator+=(const Vector2& vector2);
	Vector2& operator*(const float value);
	Vector2& operator*(const double value);
	float magnitude();
	const Vector2 operator/(float value) const;
	Vector2 normalize();
	Vector2&& operator-(const Vector2& vector2) const;
};
