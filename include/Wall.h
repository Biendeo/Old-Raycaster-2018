#pragma once

#include "Color.h"
#include "Vector2.h"

class Wall {
	public:
	/**
	 * Constructs a wall between the two given points and with the given color.
	 * @param leftPoint
	 * @param rightPoint
	 * @param color
	 */
	Wall(const Vector2& leftPoint, const Vector2& rightPoint, const Color& color);

	/**
	 * Returns the left point of the wall.
	 * @return
	 */
	const Vector2& GetLeftPoint() const;

	/**
	 * Returns the right point of the wall.
	 * @return
	 */
	const Vector2& GetRightPoint() const;

	/**
	 * Returns the color of the wall.
	 * @return
	 */
	const Color& GetColor() const;

	private:
	Vector2 _leftPoint;
	Vector2 _rightPoint;
	Color _color;
};


