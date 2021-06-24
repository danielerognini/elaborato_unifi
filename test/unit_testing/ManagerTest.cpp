#include "gtest/gtest.h"
#include "Manager.h"

class ManagerFixture : public ::testing::Test {
protected:
    ManagerFixture() : manager(Manager(true)) {}

    virtual void SetUp() {
        manager.addEntity("1", std::unique_ptr<Entity>(new Entity("")));
        manager.addEntity("2", std::unique_ptr<Entity>((new Entity(""))));
    }

    Manager manager;
};

TEST_F(ManagerFixture, addEntity) {
    EXPECT_TRUE(manager.addEntity("3", std::unique_ptr<Entity>(new Entity(""))));
    EXPECT_TRUE(manager.addEntity("4", std::unique_ptr<Entity>(new Entity(""))));
    EXPECT_FALSE(manager.addEntity("4", std::unique_ptr<Entity>(new Entity(""))));
}

TEST_F(ManagerFixture, removeEntity) {
    EXPECT_TRUE(manager.removeEntity("1"));
    EXPECT_TRUE(manager.removeEntity("2"));
    EXPECT_FALSE(manager.removeEntity("2"));
}