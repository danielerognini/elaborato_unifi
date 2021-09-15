#include "gtest/gtest.h"
#include "Collisions/Collision.h"
#include "Engine.h"

class CollisionFixture : public ::testing::Test {
protected:
    std::unordered_map<std::string, Manager> managers;

    virtual void SetUp() {
        managers.emplace("1", Manager(1));
        managers.emplace("2", Manager(2));
    
        Entity e1 = Entity("");
        e1.addCollider("1", std::move(std::vector<Border>({Border(Vector2D(0, 0), Vector2D(4, 0), true), Border(Vector2D(4, 0), Vector2D(4, 4), true), Border(Vector2D(4, 4), Vector2D(0, 4), true), Border(Vector2D(0, 4), Vector2D(0, 0), true)})), true);
        e1.getTransform().setPosition(4, 2);
        e1.getTransform().setMoving(true);
        e1.getTransform().setSpeed(1);
        e1.getText().setMessage("1");
        managers.find("1")->second.addEntity(std::move(e1));
        Entity e2 = Entity("");
        e2.addCollider("1", std::move(std::vector<Border>({Border(Vector2D(0, 0), Vector2D(4, 0), true), Border(Vector2D(4, 0), Vector2D(4, 4), true), Border(Vector2D(4, 4), Vector2D(0, 4), true), Border(Vector2D(0, 4), Vector2D(0, 0), true)})), true);
        e2.getTransform().setPosition(9, 9);
        e2.getTransform().setMoving(true);
        e2.getTransform().setSpeed(1);
        e2.getText().setMessage("2");
        managers.find("1")->second.addEntity(e2);
        Entity e3 = Entity("");
        e3.addCollider("1", std::move(std::vector<Border>({Border(Vector2D(0, 0), Vector2D(4, 0), true), Border(Vector2D(4, 0), Vector2D(4, 4), true), Border(Vector2D(4, 4), Vector2D(0, 4), true), Border(Vector2D(0, 4), Vector2D(0, 0), true)})), true);
        e3.getTransform().setPosition(1, 5);
        e3.getTransform().setMoving(true);
        e3.getTransform().setSpeed(1);
        e3.getText().setMessage("3");
        managers.find("2")->second.addEntity(e3);
        Entity e4 = Entity("");
        e4.addCollider("1", std::move(std::vector<Border>({Border(Vector2D(0, 0), Vector2D(4, 0), true), Border(Vector2D(4, 0), Vector2D(4, 4), true), Border(Vector2D(4, 4), Vector2D(0, 4), true), Border(Vector2D(0, 4), Vector2D(0, 0), true)})), true);
        e4.getTransform().setPosition(7, 10);
        e4.getTransform().setMoving(true);
        e4.getTransform().setSpeed(1);
        e4.getText().setMessage("4");
        managers.find("2")->second.addEntity(e4);
    }
};

TEST_F(CollisionFixture, collisionUpdate) {
    Collision::collisionUpdate(managers);
    
    for (auto& entity: managers.find("1")->second) {
        if (entity->getText().getMessage() == "1") {
            EXPECT_TRUE(entity->getTransform().getPosition().getX() == 5 && entity->getTransform().getPosition().getY() == 2);
        } else if (entity->getText().getMessage() == "2") {
            EXPECT_TRUE(entity->getTransform().getPosition().getX() == 10 && entity->getTransform().getPosition().getY() == 9);
        }
    }
    
    for (auto& entity: managers.find("2")->second) {
        if (entity->getText().getMessage() == "3") {
            EXPECT_TRUE(entity->getTransform().getPosition().getX() == 1 && entity->getTransform().getPosition().getY() == 6);
        } else if (entity->getText().getMessage() == "4") {
            EXPECT_TRUE(entity->getTransform().getPosition().getX() == 6 && entity->getTransform().getPosition().getY() == 10);
        }
    }
}





