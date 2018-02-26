#include "Vector2.h"

#include <gtest/gtest.h>

TEST(Vector2Test, Equality) {
	// Testing that two zeroes are equal.
	ASSERT_EQ(Vector2(), Vector2());

	// Testing that a copied Vector2 is equal.
	Vector2 a(5.9f, 2.3f);
	Vector2 b = a;
	ASSERT_EQ(a, b);

	// Testing that that different values are not equal.
	ASSERT_NE(Vector2(), b);
}

TEST(Vector2Test, Addition) {
	// Testing that the properties don't change when a zero is added.
	Vector2 zero(0.0f, 0.0f);
	Vector2 a(5.0f, 3.4f);
	Vector2 b(7.5f, -1.2f);
	ASSERT_EQ(a + zero, a);
	ASSERT_EQ(b + zero, b);

	// Testing that the properties add up to the correct amounts.
	Vector2 c = a + b;
	ASSERT_EQ(a.X() + b.X(), c.X());
	ASSERT_EQ(a.Y() + b.Y(), c.Y());
}

TEST(Vector2Test, Subtraction) {
	// Testing that the properties don't change when a zero is subtracted.
	Vector2 zero(0.0f, 0.0f);
	Vector2 a(5.0f, 3.4f);
	Vector2 b(7.5f, -1.2f);
	ASSERT_EQ(a - zero, a);
	ASSERT_EQ(b - zero, b);

	// Testing that the properties subtract the correct amounts.
	Vector2 c = a - b;
	ASSERT_EQ(a.X() - b.X(), c.X());
	ASSERT_EQ(a.Y() - b.Y(), c.Y());
}

TEST(Vector2Test, Multiplication) {
	// Testing that multiplying by scalar zero gives a zero vector.
	Vector2 zero(0.0f, 0.0f);
	Vector2 a(5.0f, 3.4f);
	Vector2 b(7.5f, -1.2f);
	ASSERT_EQ(a * 0.0f, zero);
	ASSERT_EQ(b * 0.0f, zero);

	// Testing that regular scalar multiplication works.
	Vector2 c = a * 5.0f;
	ASSERT_EQ(a.X() * 5.0f, c.X());
	ASSERT_EQ(a.Y() * 5.0f, c.Y());

	// Testing that multiplying by the zero vector gives a zero vector.
	ASSERT_EQ(a * zero, zero);
	ASSERT_EQ(b * zero, zero);

	// Testing that piece-wise multiplication works.
	ASSERT_EQ((a * b).X(), a.X() * b.X());
	ASSERT_EQ((a * b).Y(), a.Y() * b.Y());
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}