#include "gtest/gtest.h"
#include "ecs/Manager.h"

class ManagerFixture : public ::testing::Test {
protected:
    ManagerFixture() : manager(Manager(true)) {}
    
    Entity* e1 = new Entity("");
    Entity* e2 = new Entity("");
    Entity* e3 = new Entity("");
    Entity* e4 = new Entity("");
    
    virtual void SetUp() {
        manager.addEntity(e1);
        manager.addEntity(e2);
    }
    
    Manager manager;
};

TEST_F(ManagerFixture, find) {
    manager.addEntity(e3);
    EXPECT_TRUE(manager.find(e3));
    EXPECT_FALSE(manager.find(e4));
    manager.addEntity(e4);
    EXPECT_TRUE(manager.find(e4));
}

TEST_F(ManagerFixture, removeEntity) {
    EXPECT_TRUE(manager.removeEntity(e1));
    EXPECT_TRUE(manager.removeEntity(e2));
}