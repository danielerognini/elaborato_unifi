#include "gtest/gtest.h"
#include "Vector2D.h"

class Vector2DFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        vector1 = Vector2D(2, 4);
        vector2 = Vector2D(3, 6);
    }
    
    Vector2D vector1;
    Vector2D vector2;
};

TEST_F(Vector2DFixture, setVector) {
    vector1.setVector(4, 2);
    EXPECT_TRUE(vector1.getX() == 4 && vector1.getY() == 2);
}

TEST_F(Vector2DFixture, addCoordinate) {
    vector1.add(1, 1);
    EXPECT_TRUE(vector1.getX() == 3 && vector1.getY() == 5);
}

TEST_F(Vector2DFixture, subtractCoordinate) {
    vector1.subtract(1, 1);
    EXPECT_TRUE(vector1.getX() == 1 && vector1.getY() == 3);
}

TEST_F(Vector2DFixture, add) {
    vector1.add(vector2);
    EXPECT_TRUE(vector1.getX() == 5 && vector1.getY() == 10);
}

TEST_F(Vector2DFixture, subtract) {
    vector1.subtract(vector2);
    EXPECT_TRUE(vector2.getX() == -1 && vector2.getY() == -2);
}

TEST_F(Vector2DFixture, multiply) {
    vector1.multiply(2);
    EXPECT_TRUE(vector1.getX() == 4 && vector1.getY() == 8);
}

TEST_F(Vector2DFixture, divide) {
    vector1.divide(2);
    EXPECT_TRUE(vector1.getX() == 1 && vector1.getY() == 2);
}

TEST_F(Vector2DFixture, operatorSum) {
    Vector2D vector = vector1 + vector2;
    EXPECT_TRUE(vector.getX() == 5 && vector.getY() == 10);
}

TEST_F(Vector2DFixture, operatorMinus) {
    Vector2D vector = vector1 - vector2;
    EXPECT_TRUE(vector.getX() == -1 && vector.getY() == -2);
}

TEST_F(Vector2DFixture, operatorStar) {
    Vector2D vector = vector1 * 2;
    EXPECT_TRUE(vector.getX() == 4 && vector.getY() == 8);
}

TEST_F(Vector2DFixture, operatorSlash) {
    Vector2D vector = vector1 / 2;
    EXPECT_TRUE(vector.getX() == 1 && vector.getY() == 2);
}

TEST_F(Vector2DFixture, operatorModule) {
    EXPECT_TRUE(static_cast<int>(Vector2D(-1, 0) % vector1) == 5);
}

TEST_F(Vector2DFixture, operatorSumAssignment) {
    vector1 += vector2;
    EXPECT_TRUE(vector1.getX() == 5 && vector1.getY() == 10);
}

TEST_F(Vector2DFixture, operatorMinusEqual) {
    vector1 -= vector2;
    EXPECT_TRUE(vector1.getX() == -1 && vector1.getY() == -2);
}

TEST_F(Vector2DFixture, operatorStarEqual) {
    vector1 *= 2;
    EXPECT_TRUE(vector1.getX() == 4 && vector1.getY() == 8);
}

TEST_F(Vector2DFixture, operatorDivisionAssignment) {
    vector1 /= 2;
    EXPECT_TRUE(vector1.getX() == 1 && vector1.getY() == 2);
}