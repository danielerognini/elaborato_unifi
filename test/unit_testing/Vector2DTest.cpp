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
    Vector2D vector = Vector2D(vector1);
    vector.setVector(4, 2);
    EXPECT_TRUE(vector.getX() == 4 && vector.getY() == 2);
}

TEST_F(Vector2DFixture, addCoordinate) {
    Vector2D vector = Vector2D(vector1);
    vector.add(1, 1);
    EXPECT_TRUE(vector.getX() == 3 && vector.getY() == 5);
}

TEST_F(Vector2DFixture, subtractCoordinate) {
    Vector2D vector = Vector2D(vector1);
    vector.subtract(1, 1);
    EXPECT_TRUE(vector.getX() == 1 && vector.getY() == 3);
}

TEST_F(Vector2DFixture, add) {
    Vector2D vector = Vector2D(vector1);
    vector.add(vector2);
    EXPECT_TRUE(vector.getX() == 5 && vector.getY() == 10);
}

TEST_F(Vector2DFixture, subtract) {
    Vector2D vector = Vector2D(vector1);
    vector.subtract(vector2);
    EXPECT_TRUE(vector.getX() == -1 && vector.getY() == -2);
}

TEST_F(Vector2DFixture, multiply) {
    Vector2D vector = Vector2D(vector1);
    vector.multiply(2);
    EXPECT_TRUE(vector.getX() == 4 && vector.getY() == 8);
}

TEST_F(Vector2DFixture, divide) {
    Vector2D vector = Vector2D(vector1);
    vector.divide(2);
    EXPECT_TRUE(vector.getX() == 1 && vector.getY() == 2);
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
    Vector2D vector = Vector2D(vector1);
    vector += vector2;
    EXPECT_TRUE(vector.getX() == 5 && vector.getY() == 10);
}

TEST_F(Vector2DFixture, operatorMinusEqual) {
    Vector2D vector = Vector2D(vector1);
    vector -= vector2;
    EXPECT_TRUE(vector.getX() == -1 && vector.getY() == -2);
}

TEST_F(Vector2DFixture, operatorStarEqual) {
    Vector2D vector = Vector2D(vector1);
    vector *= 2;
    EXPECT_TRUE(vector.getX() == 4 && vector.getY() == 8);
}

TEST_F(Vector2DFixture, operatorDivisionAssignment) {
    Vector2D vector = Vector2D(vector1);
    vector /= 2;
    EXPECT_TRUE(vector.getX() == 1 && vector.getY() == 2);
}