#include "gtest/gtest.h"
#include "Vector2D.h"

class Vector2DFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        vector1 = Vector(2, 4);
        vector2 = Vector(3, 6);
    }

    Vector2D vector1;
    Vector2D vector2;
};

TEST_F(Vector2DFixture, setToZero) {
    Vector2D vector = vector1.setToZero();
    EXPECT_TRUE(vector.getX() == 0 && vector.getY() == 0);
}

TEST_F(Vector2DFixture, addCoordinate) {
    Vector2D vector = vector1.add(1, 1);
    EXPECT_TRUE(vector.getX() == 3 && vector.getY() == 5);
}

TEST_F(Vector2DFixture, subtractCoordinate) {
    Vector2D vector = vector1.subtract(1, 1);
    EXPECT_TRUE(vector.getX() == 1 && vector.getY() == 3);
}

TEST_F(Vector2DFixture, add) {
    Vector2D vector = vector1.add(vector2);
    EXPECT_TRUE(vector.getX() == 5 && vector.getY() == 10);
}

TEST_F(Vector2DFixture, subtract) {
    Vector2D vector = vector1.subtract(vector2);
    EXPECT_TRUE(vector.getX() == -1 && vector.getY() == -2);
}

TEST_F(Vector2DFixture, multiply) {
    Vector2D vector = vector1.multiply(2);
    EXPECT_TRUE(vector.getX() == 4 && vector.getY() == 8);
}

TEST_F(Vector2DFixture, divide) {
    Vector2D vector = vector1.divide(2);
    EXPECT_TRUE(vector.getX() == 1 && vector.getY() == 2);
}

TEST_F(Vector2DFixture, operator+) {
    Vector vector = vector1 + vector2;
    EXPECT_TRUE(vector.getX() == 5 && vector.getY() == 10);
}

TEST_F(Vector2DFixture, operator-) {
    Vector vector = vector1 - vector2;
    EXPECT_TRUE(vector.getX() == -1 && vector.getY() == -2);
}

TEST_F(Vector2DFixture, operator*) {
    Vector vector = vector1 * 2;
    EXPECT_TRUE(vector.getX() == 4 && vector.getY() == 8);
}

TEST_F(Vector2DFixture, operator/) {
    Vector vector = vector1 / 2;
    EXPECT_TRUE(vector.getX() == 1 && vector.getY() == 2);
}

TEST_F(Vector2DFixture, operator%) {
    EXPECT_TRUE(static_cast<int>(Vector(-1, 0) % vector1) = 5);
}

TEST_F(Vector2DFixture, operator+=) {
    vector1 += vector2;
    EXPECT_TRUE(vector1.getX() == 5 && vector1.getY() == 10);
}

TEST_F(Vector2DFixture, operator-=) {
    vector1 -= vector2;
    EXPECT_TRUE(vector1.getX() == -1 && vector1.getY() == -2);
}

TEST_F(Vector2DFixture, operator*=) {
    vector1 *= 2;
    EXPECT_TRUE(vector1.getX() == 4 && vector1.getY() == 8);
}

TEST_F(Vector2DFixture, operator/=) {
    vector1 /= 2;
    EXPECT_TRUE(vector1.getX() == 1 && vector1.getY() == 2);
}