#include "gtest/gtest.h"
#include "Collisions/Collision.h"
#include "Engine.h"

class CollisionFixture : public ::testing::Test {
protected:
    std::unordered_map<std::string, Manager> managers;

    virtual void SetUp() {
        managers.emplace("1", Manager(1));
        managers.emplace("2", Manager(2));
    
        managers.find("1")->second.addEntity("1", std::move(Entity("")));
        managers.find("1")->second.getEntity("1").addCollider("1", std::move(std::vector<Border>({Border(Vector2D(0, 0), Vector2D(4, 0), true), Border(Vector2D(4, 0), Vector2D(4, 4), true), Border(Vector2D(4, 4), Vector2D(0, 4), true), Border(Vector2D(0, 4), Vector2D(0, 0), true)})), true);
        managers.find("1")->second.getEntity("1").getTransform().setPosition(4, 2);
        managers.find("1")->second.getEntity("1").getTransform().setMoving(true);
        managers.find("1")->second.getEntity("1").getTransform().setSpeed(1);
        managers.find("1")->second.addEntity("2", std::move(Entity("")));
        managers.find("1")->second.getEntity("2").addCollider("1", std::move(std::vector<Border>({Border(Vector2D(0, 0), Vector2D(4, 0), true), Border(Vector2D(4, 0), Vector2D(4, 4), true), Border(Vector2D(4, 4), Vector2D(0, 4), true), Border(Vector2D(0, 4), Vector2D(0, 0), true)})), true);
        managers.find("1")->second.getEntity("2").getTransform().setPosition(9, 9);
        managers.find("1")->second.getEntity("2").getTransform().setMoving(true);
        managers.find("1")->second.getEntity("2").getTransform().setSpeed(1);
        managers.find("2")->second.addEntity("1", std::move(Entity("")));
        managers.find("2")->second.getEntity("1").addCollider("1", std::move(std::vector<Border>({Border(Vector2D(0, 0), Vector2D(4, 0), true), Border(Vector2D(4, 0), Vector2D(4, 4), true), Border(Vector2D(4, 4), Vector2D(0, 4), true), Border(Vector2D(0, 4), Vector2D(0, 0), true)})), true);
        managers.find("2")->second.getEntity("1").getTransform().setPosition(1, 5);
        managers.find("2")->second.getEntity("1").getTransform().setMoving(true);
        managers.find("2")->second.getEntity("1").getTransform().setSpeed(1);
        managers.find("2")->second.addEntity("2", std::move(Entity("")));
        managers.find("2")->second.getEntity("2").addCollider("1", std::move(std::vector<Border>({Border(Vector2D(0, 0), Vector2D(4, 0), true), Border(Vector2D(4, 0), Vector2D(4, 4), true), Border(Vector2D(4, 4), Vector2D(0, 4), true), Border(Vector2D(0, 4), Vector2D(0, 0), true)})), true);
        managers.find("2")->second.getEntity("2").getTransform().setPosition(7, 10);
        managers.find("2")->second.getEntity("2").getTransform().setMoving(true);
        managers.find("2")->second.getEntity("2").getTransform().setSpeed(1);
    }
};

TEST_F(CollisionFixture, collisionUpdate) {
    Collision::collisionUpdate(managers);
    
    EXPECT_TRUE(managers.find("1")->second.getEntity("1").getTransform().getPosition().getX() == 5 && managers.find("1")->second.getEntity("1").getTransform().getPosition().getY() == 2);
    EXPECT_TRUE(managers.find("1")->second.getEntity("2").getTransform().getPosition().getX() == 10 && managers.find("1")->second.getEntity("2").getTransform().getPosition().getY() == 9);
    EXPECT_TRUE(managers.find("2")->second.getEntity("1").getTransform().getPosition().getX() == 1 && managers.find("2")->second.getEntity("1").getTransform().getPosition().getY() == 6);
    EXPECT_TRUE(managers.find("2")->second.getEntity("2").getTransform().getPosition().getX() == 6 && managers.find("2")->second.getEntity("2").getTransform().getPosition().getY() == 10);
}





