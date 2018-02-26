#include "Vector3.h"

Vector3::Vector3() : Vector3(0.0f, 0.0f, 0.0f) {}

Vector3::Vector3(Vector3::type allValues) : Vector3(allValues, allValues, allValues) {}

Vector3::Vector3(Vector3::type x, Vector3::type y, Vector3::type z) {
	X(x);
	Y(y);
	Z(z);
}

Vector3 &Vector3::operator+=(const Vector3& v) {
	X(X() + v.X());
	Y(Y() + v.Y());
	Z(Z() + v.Z());
	return *this;
}

Vector3 &Vector3::operator-=(const Vector3& v) {
	X(X() - v.X());
	Y(Y() - v.Y());
	Z(Z() - v.Z());
	return *this;
}

Vector3 &Vector3::operator*=(const Vector3& v) {
	X(X() * v.X());
	Y(Y() * v.Y());
	Z(Z() * v.Z());
	return *this;
}

Vector3& Vector3::operator/=(const Vector3& v) {
	X(X() / v.X());
	Y(Y() / v.Y());
	Z(Z() / v.Z());
	return *this;
}

Vector3 Vector3::operator+(const Vector3& v) const {
	return Vector3(*this) += v;
}

Vector3 Vector3::operator-(const Vector3& v) const {
	return Vector3(*this) -= v;
}

Vector3 Vector3::operator*(const Vector3& v) const {
	return Vector3(*this) *= v;
}

Vector3 Vector3::operator/(const Vector3& v) const {
	return Vector3(*this) /= v;
}

Vector3& Vector3::operator*=(Vector3::type i) {
	X(X() * i);
	Y(Y() * i);
	Z(Z() * i);
	return *this;
}

Vector3& Vector3::operator/=(Vector3::type i) {
	X(X() / i);
	Y(Y() / i);
	Z(Z() / i);
	return *this;
}

Vector3 Vector3::operator*(Vector3::type i) const {
	return Vector3(*this) *= i;
}

Vector3 Vector3::operator/(Vector3::type i) const {
	return Vector3(*this) /= i;
}

bool Vector3::operator==(const Vector3& v) const {
	return X() == v.X() && Y() == v.Y() && Z() == v.Z();
}

bool Vector3::operator!=(const Vector3& v) const {
	return !operator==(v);
}

Vector3& Vector3::CrossSelf(const Vector3& v) {
	return *this = Cross(v);
}

Vector3 Vector3::Cross(const Vector3& v) const {
	return Vector3(Y() * v.Z() - Z() * v.Y(), Z() * v.X() - X() * v.Z(), X() * v.Y() - Y() * v.Z());
}

Vector3::type Vector3::Dot(const Vector3& v) const {
	return X() * v.X() + Y() * v.Y() + Z() * v.Z();
}

Vector3::type Vector3::Magnitude() const {
	return X() * X() + Y() * Y() + Z() * Z();
}

void Vector3::X(Vector3::type i) {
	_x = i;
}

void Vector3::Y(Vector3::type i) {
	_y = i;
}

void Vector3::Z(Vector3::type i) {
	_z = i;
}

Vector3::type& Vector3::X() {
	return _x;
}

Vector3::type& Vector3::Y() {
	return _y;
}

Vector3::type& Vector3::Z() {
	return _z;
}

Vector3::type Vector3::X() const {
	return _x;
}

Vector3::type Vector3::Y() const {
	return _y;
}

Vector3::type Vector3::Z() const {
	return _z;
}