#include "gtest/gtest.h"
#include "ECS/Components/Collider.h"
#include "iostream"


class ColliderFixture : public ::testing::Test {
protected:
    ColliderFixture() : collider(Collider(std::move(std::vector<Border>({Border(Vector2D(0, 0), Vector2D(4, 0), true), Border(Vector2D(4, 0), Vector2D(4, 4), true), Border(Vector2D(4, 4), Vector2D(0, 4), true), Border(Vector2D(0, 4), Vector2D(0, 0), true)})), true)) {}

    virtual void SetUp() {

    }
    Collider collider;
};

//TODO: may be removed