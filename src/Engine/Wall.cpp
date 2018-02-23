#include "Wall.h"

Wall::Wall(const Vector2& leftPoint, const Vector2& rightPoint, const Color& color) : _leftPoint(leftPoint), _rightPoint(rightPoint), _color(color) {}

const Vector2& Wall::GetLeftPoint() const {
	return _leftPoint;
}

const Vector2& Wall::GetRightPoint() const {
	return _rightPoint;
}

const Color& Wall::GetColor() const {
	return _color;
}
