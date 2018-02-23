#include "Color.h"

Color::Color() : Color(0, 0, 0, static_cast<uint8_t>(1)) {}

Color::Color(uint8_t r, uint8_t g, uint8_t b) : Color(r, g, b, 1) {}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	R(r);
	G(g);
	B(b);
	A(a);
}

Color::Color(float r, float g, float b) : Color(r, g, b, 1.0f) {}

Color::Color(float r, float g, float b, float a) {
	R(static_cast<uint8_t>(r / 255.0f));
	G(static_cast<uint8_t>(g / 255.0f));
	B(static_cast<uint8_t>(b / 255.0f));
	A(static_cast<uint8_t>(a / 255.0f));
}

uint8_t& Color::R() {
	return _r;
}

uint8_t& Color::G() {
	return _g;
}

uint8_t& Color::B() {
	return _b;
}

uint8_t& Color::A() {
	return _a;
}

uint8_t Color::R() const {
	return _r;
}

uint8_t Color::G() const {
	return _g;
}

uint8_t Color::B() const {
	return _b;
}

uint8_t Color::A() const {
	return _a;
}

void Color::R(uint8_t r) {
	_r = r;
}

void Color::G(uint8_t g) {
	_g = g;
}

void Color::B(uint8_t b) {
	_b = b;
}

void Color::A(uint8_t a) {
	_a = a;
}
