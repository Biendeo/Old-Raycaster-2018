#pragma once

/**
 * Handles mathematics involving 2D co-ordinates.
 */
class Vector2 {
	public:
	/**
	 * The common type used internally by Vector2 objects.
	 */
	using type = float;

	/**
	 * Constructs a Vector2 with zero values.
	 */
	Vector2();

	/**
	 * Constructs a Vector2 where all three fields are of the given value.
	 * @param allValues
	 */
	Vector2(type allValues);

	/**
	 * Constructs a Vector2 with the specified values.
	 * @param x
	 * @param y
	 */
	Vector2(type x, type y);

	/**
	 * Adds a Vector2 piece-wise to this one.
	 * @param v
	 * @return
	 */
	Vector2& operator+=(const Vector2& v);

	/**
	 * Subtracts a Vector2 piece-wise to this one.
	 * @param v
	 * @return
	 */
	Vector2& operator-=(const Vector2& v);

	/**
	 * Multiplies a Vector2 piece-wise to this one.
	 * @param v
	 * @return
	 */
	Vector2& operator*=(const Vector2& v);

	/**
	 * Divides a Vector2 piece-wise to this one.
	 * @param v
	 * @return
	 */
	Vector2& operator/=(const Vector2& v);

	/**
	 * Adds a Vector2 piece-wise and returns a new object.
	 * @param v
	 * @return
	 */
	Vector2 operator+(const Vector2& v) const;

	/**
	 * Subtracts a Vector2 piece-wise and returns a new object.
	 * @param v
	 * @return
	 */
	Vector2 operator-(const Vector2& v) const;

	/**
	 * Multiplies a Vector2 piece-wise and returns a new object.
	 * @param v
	 * @return
	 */
	Vector2 operator*(const Vector2& v) const;

	/**
	 * Divides a Vector2 piece-wise and returns a new object.
	 * @param v
	 * @return
	 */
	Vector2 operator/(const Vector2& v) const;

	/**
	 * Multiplies a scalar with all of this Vector2's fields.
	 * @param i
	 * @return
	 */
	Vector2& operator*=(type i);

	/**
	 * Divides a scale with all of this Vector2's fields.
	 * @param i
	 * @return
	 */
	Vector2& operator/=(type i);

	/**
	 * Multiplies this with a scalar and returns a new object.
	 * @param i
	 * @return
	 */
	Vector2 operator*(type i) const;

	/**
	 * Divides this with a scalar and returns a new object.
	 * @param i
	 * @return
	 */
	Vector2 operator/(type i) const;

	/**
	 * Compares whether two Vector2s are equal.
	 * @param v
	 * @return
	 */
	bool operator==(const Vector2& v) const;

	/**
	 * Compares whether two Vector2s are not equal.
	 * @param v
	 * @return
	 */
	bool operator!=(const Vector2& v) const;

	/**
	 * Returns the dot product with another Vector2.
	 * @param v
	 * @return
	 */
	type Dot(const Vector2& v) const;

	/**
	 * Returns the determinant of this Vector2 with another one.
	 * @param v
	 * @return
	 */
	type Determinant(const Vector2& v) const;

	/**
	 * Returns the magnitude of this Vector2.
	 * @return
	 */
	type Magnitude() const;

	/**
	 * Sets the X value.
	 * @param i
	 */
	void X(type i);

	/**
	 * Sets the Y value.
	 * @param i
	 */
	void Y(type i);

	/**
	 * Returns a modifiable reference to the X field.
	 * @return
	 */
	type& X();

	/**
	 * Returns a modifiable reference to the Y field.
	 * @return
	 */
	type& Y();

	/**
	 * Returns the value of the X field.
	 * @return
	 */
	type X() const;

	/**
	 * Returns the value of the Y field.
	 * @return
	 */
	type Y() const;

	private:
	type _x;
	type _y;
};