#include "gtest/gtest.h"
#include "ECS/Manager.h"

class ManagerFixture : public ::testing::Test {
protected:
    ManagerFixture() : manager(Manager(true)) {}
    
    Entity* e1 = new Entity("");
    Entity* e2 = new Entity("");
    Entity* e3 = new Entity("");
    Entity* e4 = new Entity("");
    
    virtual void SetUp() {
        manager.addEntity(std::move(*e1));
        manager.addEntity(std::move(*e2));
    }
    
    Manager manager;
};

TEST_F(ManagerFixture, addEntity) {
    EXPECT_TRUE(manager.addEntity(std::move(*e3)));
    EXPECT_TRUE(manager.addEntity(std::move(*e4)));
    EXPECT_FALSE(manager.addEntity(std::move(*e4)));
}

TEST_F(ManagerFixture, removeEntity) {
    EXPECT_TRUE(manager.removeEntity(*e1));
    EXPECT_TRUE(manager.removeEntity(*e2));
    EXPECT_FALSE(manager.removeEntity(*e2));
}