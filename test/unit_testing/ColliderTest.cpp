#include "gtest/gtest.h"
#include "Collider.h"


class ColliderFixture : public ::testing::Test {
protected:
    ColliderFixture() : collider(Collider(new vector<Vector2D>({Vector2D(0,0), Vector2D(2,0), Vector2D(2,2), Vector2D(0,2)}))) {}

    virtual void SetUp() {

    }
    Collider collider;
};

TEST_F(ColliderFixture, calculateCenter) {
    Vector2D center = collider.getCenter();
    EXPECT_TRUE(center.getX() == 1, center.getY() == 1);
}