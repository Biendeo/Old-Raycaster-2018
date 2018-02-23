#include "Vector2.h"

Vector2::Vector2() : Vector2(0.0f, 0.0f) {}

Vector2::Vector2(Vector2::type allValues) : Vector2(allValues, allValues) {}

Vector2::Vector2(Vector2::type x, Vector2::type y) {
	X(x);
	Y(y);
}

Vector2 &Vector2::operator+=(const Vector2& v) {
	X(X() + v.X());
	Y(Y() + v.Y());
	return *this;
}

Vector2 &Vector2::operator-=(const Vector2& v) {
	X(X() - v.X());
	Y(Y() - v.Y());
	return *this;
}

Vector2 &Vector2::operator*=(const Vector2& v) {
	X(X() * v.X());
	Y(Y() * v.Y());
	return *this;
}

Vector2& Vector2::operator/=(const Vector2& v) {
	X(X() / v.X());
	Y(Y() / v.Y());
	return *this;
}

Vector2 Vector2::operator+(const Vector2& v) const {
	return Vector2(*this) += v;
}

Vector2 Vector2::operator-(const Vector2& v) const {
	return Vector2(*this) -= v;
}

Vector2 Vector2::operator*(const Vector2& v) const {
	return Vector2(*this) *= v;
}

Vector2 Vector2::operator/(const Vector2& v) const {
	return Vector2(*this) /= v;
}

Vector2& Vector2::operator*=(Vector2::type i) {
	X(X() * i);
	Y(Y() * i);
	return *this;
}

Vector2& Vector2::operator/=(Vector2::type i) {
	X(X() / i);
	Y(Y() / i);
	return *this;
}

Vector2 Vector2::operator*(Vector2::type i) const {
	return Vector2(*this) *= i;
}

Vector2 Vector2::operator/(Vector2::type i) const {
	return Vector2(*this) /= i;
}

Vector2::type Vector2::Dot(const Vector2& v) const {
	return X() * v.X() + Y() * v.Y();
}

Vector2::type Vector2::Determinant(const Vector2& v) const {
	return X() * v.Y() - Y() * v.X();
}

Vector2::type Vector2::Magnitude() const {
	return X() * X() + Y() * Y();
}

void Vector2::X(Vector2::type i) {
	_x = i;
}

void Vector2::Y(Vector2::type i) {
	_y = i;
}

Vector2::type& Vector2::X() {
	return _x;
}

Vector2::type& Vector2::Y() {
	return _y;
}

Vector2::type Vector2::X() const {
	return _x;
}

Vector2::type Vector2::Y() const {
	return _y;
}