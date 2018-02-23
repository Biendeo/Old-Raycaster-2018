#pragma once

#include <cstdint>

/**
 * Handles storing values for a color.
 */
class Color {
	public:
	/**
	 * Constructs a black opaque color object.
	 */
	Color();

	/**
	 * Constructs an opaque color with the given color values.
	 * //TODO: This makes ambiguous calls. How can I be explicit here?
	 * @param r
	 * @param g
	 * @param b
	 */
	Color(uint8_t r, uint8_t g, uint8_t b);

	/**
	 * Constructs a color with the given color values and opacity.
	 * @param r
	 * @param g
	 * @param b
	 * @param a
	 */
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	/**
	 * Constructs an opaque color with the given color values.
	 * @param r
	 * @param g
	 * @param b
	 */
	Color(float r, float g, float b);

	/**
	 * Constructs a color with the given color values and opacity.
	 * @param r
	 * @param g
	 * @param b
	 * @param a
	 */
	Color(float r, float g, float b, float a);

	/**
	 * Sets the R value.
	 * @param r
	 */
	void R(uint8_t r);

	/**
	 * Sets the G value.
	 * @param g
	 */
	void G(uint8_t g);

	/**
	 * Sets the B value.
	 * @param b
	 */
	void B(uint8_t b);

	/**
	 * Sets the A value.
	 * @param a
	 */
	void A(uint8_t a);

	/**
	 * Returns a modifiable reference to the R field.
	 * @return
	 */
	uint8_t& R();

	/**
	 * Returns a modifiable reference to the G field.
	 * @return
	 */
	uint8_t& G();

	/**
	 * Returns a modifiable reference to the B field.
	 * @return
	 */
	uint8_t& B();

	/**
	 * Returns a modifiable reference to the A field.
	 * @return
	 */
	uint8_t& A();

	/**
	 * Returns the value of the R field.
	 * @return
	 */
	uint8_t R() const;

	/**
	 * Returns the value of the G field.
	 * @return
	 */
	uint8_t G() const;

	/**
	 * Returns the value of the B field.
	 * @return
	 */
	uint8_t B() const;

	/**
	 * Returns the value of the A field.
	 * @return
	 */
	uint8_t A() const;

	private:
	uint8_t _r;
	uint8_t _g;
	uint8_t _b;
	uint8_t _a;
};


