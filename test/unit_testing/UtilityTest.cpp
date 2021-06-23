#include "gtest/gtest.h"
#include "Utility.h"
#include "Engine.h"

class UtilityFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        intersection = checkLinesIntersection(std::make_pair<Vector2D, Vector2D>(Vector2D(0,0), Vector2D(2,2)), std::make_pair<Vector2D, Vector2D>(Vector2D(0,2), Vector2D(2,0)));
    }

    Vector2D intersection;
};

TEST_F(UtilityFixture, lineIntersection) {
    EXPECT_TRUE(intersection.getX() == 1 && intersection.getY() == 1);
}




