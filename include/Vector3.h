#pragma once

/**
 * Handles mathematics involving 3D co-ordinates.
 */
class Vector3 {
	public:
	/**
	 * The common type used internally by Vector3 objects.
	 */
	using type = float;

	/**
	 * Constructs a Vector3 with zero values.
	 */
	Vector3();

	/**
	 * Constructs a Vector3 where all three fields are of the given value.
	 * @param allValues
	 */
	Vector3(type allValues);

	/**
	 * Constructs a Vector3 with the specified values.
	 * @param x
	 * @param y
	 * @param z
	 */
	Vector3(type x, type y, type z);

	/**
	 * Adds a Vector3 piece-wise to this one.
	 * @param v
	 * @return
	 */
	Vector3& operator+=(const Vector3& v);

	/**
	 * Subtracts a Vector3 piece-wise to this one.
	 * @param v
	 * @return
	 */
	Vector3& operator-=(const Vector3& v);

	/**
	 * Multiplies a Vector3 piece-wise to this one.
	 * @param v
	 * @return
	 */
	Vector3& operator*=(const Vector3& v);

	/**
	 * Divides a Vector3 piece-wise to this one.
	 * @param v
	 * @return
	 */
	Vector3& operator/=(const Vector3& v);

	/**
	 * Adds a Vector3 piece-wise and returns a new object.
	 * @param v
	 * @return
	 */
	Vector3 operator+(const Vector3& v) const;

	/**
	 * Subtracts a Vector3 piece-wise and returns a new object.
	 * @param v
	 * @return
	 */
	Vector3 operator-(const Vector3& v) const;

	/**
	 * Multiplies a Vector3 piece-wise and returns a new object.
	 * @param v
	 * @return
	 */
	Vector3 operator*(const Vector3& v) const;

	/**
	 * Divides a Vector3 piece-wise and returns a new object.
	 * @param v
	 * @return
	 */
	Vector3 operator/(const Vector3& v) const;

	/**
	 * Multiplies a scalar with all of this Vector3's fields.
	 * @param i
	 * @return
	 */
	Vector3& operator*=(const type i);

	/**
	 * Divides a scale with all of this Vector3's fields.
	 * @param i
	 * @return
	 */
	Vector3& operator/=(const type i);

	/**
	 * Multiplies this with a scalar and returns a new object.
	 * @param i
	 * @return
	 */
	Vector3 operator*(const type i) const;

	/**
	 * Divides this with a scalar and returns a new object.
	 * @param i
	 * @return
	 */
	Vector3 operator/(const type i) const;

	/**
	 * Performs a cross product on this Vector3.
	 * @param v
	 * @return
	 */
	Vector3& CrossSelf(const Vector3& v);

	/**
	 * Performs a cross product with another Vector3 and returns a new object.
	 * @param v
	 * @return
	 */
	Vector3 Cross(const Vector3& v) const;

	/**
	 * Returns the dot product with another Vector3.
	 * @param v
	 * @return
	 */
	type Dot(const Vector3& v) const;

	/**
	 * Returns the magnitude of this Vector3.
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
	 * Sets the Z value.
	 * @param i
	 */
	void Z(type i);

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
	 * Returns a modifiable reference to the Z field.
	 * @return
	 */
	type& Z();

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

	/**
	 * Returns the value of the Z field.
	 * @return
	 */
	type Z() const;

	private:
	type _x;
	type _y;
	type _z;
};


