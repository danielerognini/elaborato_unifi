#include "gtest/gtest.h"
#include "ECS/Components/Sprite.h"

class SpriteFixture : public ::testing::Test {
protected:
    SpriteFixture() : sprite(Sprite("", true)) {}

    virtual void SetUp() {
        sprite.addAnimation("1", 0, 1, 0);
        sprite.addAnimation("2", 0, 1, 0);
    }

    Sprite sprite;
};

TEST_F(SpriteFixture, addAnimation) {
    EXPECT_TRUE(sprite.addAnimation("3", 0, 1, 0));
    EXPECT_TRUE(sprite.addAnimation("4", 0, 1, 0));
    EXPECT_FALSE(sprite.addAnimation("4", 0, 1, 0));
}

TEST_F(SpriteFixture, removeAnimation) {
    EXPECT_TRUE(sprite.removeAnimation("1"));
    EXPECT_TRUE(sprite.removeAnimation("2"));
    EXPECT_FALSE(sprite.removeAnimation("2"));
}