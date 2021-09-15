#include "gtest/gtest.h"
#include "Engine.h"

class EngineFixture : public ::testing::Test {
protected:
    EngineFixture() : engine(Engine::getInstance()) {}

    void SetUp() override {
        engine.addManager("1", 1);
        engine.addManager("2", 2);
    }

    Engine engine;
};


TEST_F(EngineFixture, addManager){
    EXPECT_TRUE(engine.addManager("3", 3));
    EXPECT_TRUE(engine.addManager("4", 4));
    EXPECT_FALSE(engine.addManager("4", 4));
}

TEST_F(EngineFixture, removeManager) {
    EXPECT_TRUE(engine.removeManager("1"));
    EXPECT_TRUE(engine.removeManager("2"));
    EXPECT_FALSE(engine.removeManager("2"));
}


