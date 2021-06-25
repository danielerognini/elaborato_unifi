#include "gtest/gtest.h"
#include "Collision.h"
#include "Engine.h"

class CollisionFixture : public ::testing::Test {
protected:
    std::unordered_map<std::string, Manager> managers;

    virtual void SetUp() {
        managers.emplace("1", Manager(1));
        managers.emplace("2", Manager(2));

        managers.find("1")->second.addEntity("1", std::unique_ptr<Entity>(new Entity("")));
        managers.find("1")->second.getEntity("1")->addCollider("1", std::unique_ptr<std::vector<Vector2D>>(new std::vector<Vector2D>({Vector2D(0, 0), Vector2D(4, 0), Vector2D(4, 4), Vector2D(0, 4)})));
        managers.find("1")->second.getEntity("1")->getTransform().setPosition(4, 2);
        managers.find("1")->second.getEntity("1")->getTransform().setMoving(true);
        managers.find("1")->second.getEntity("1")->getTransform().setSpeed(1);
        managers.find("1")->second.addEntity("2", std::unique_ptr<Entity>(new Entity("")));
        managers.find("1")->second.getEntity("2")->addCollider("1", std::unique_ptr<std::vector<Vector2D>>(new std::vector<Vector2D>({Vector2D(0, 0), Vector2D(4, 0), Vector2D(4, 4), Vector2D(0, 4)})));
        managers.find("1")->second.getEntity("2")->getTransform().setPosition(9, 9);
        managers.find("1")->second.getEntity("2")->getTransform().setMoving(true);
        managers.find("1")->second.getEntity("2")->getTransform().setSpeed(1);
        managers.find("2")->second.addEntity("1", std::unique_ptr<Entity>(new Entity("")));
        managers.find("2")->second.getEntity("1")->addCollider("1", std::unique_ptr<std::vector<Vector2D>>(new std::vector<Vector2D>({Vector2D(0, 0), Vector2D(4, 0), Vector2D(4, 4), Vector2D(0, 4)})));
        managers.find("2")->second.getEntity("1")->getTransform().setPosition(1, 5);
        managers.find("2")->second.getEntity("1")->getTransform().setMoving(true);
        managers.find("2")->second.getEntity("1")->getTransform().setSpeed(1);
        managers.find("2")->second.addEntity("2", std::unique_ptr<Entity>(new Entity("")));
        managers.find("2")->second.getEntity("2")->addCollider("1", std::unique_ptr<std::vector<Vector2D>>(new std::vector<Vector2D>({Vector2D(0, 0), Vector2D(4, 0), Vector2D(4, 4), Vector2D(0, 4)})));
        managers.find("2")->second.getEntity("2")->getTransform().setPosition(7, 10);
        managers.find("2")->second.getEntity("2")->getTransform().setMoving(true);
        managers.find("2")->second.getEntity("2")->getTransform().setSpeed(1);
    }
};

TEST_F(CollisionFixture, collisionUpdate) {
    collisionUpdate(managers);

    std::cout << "[1, 1]: " << "(" << managers.find("1")->second.getEntity("1")->getTransform().getPosition().getX() << ", " << managers.find("1")->second.getEntity("1")->getTransform().getPosition().getY() << ")" << std::endl;
    std::cout << "[1, 2]: " << "(" << managers.find("1")->second.getEntity("2")->getTransform().getPosition().getX() << ", " << managers.find("1")->second.getEntity("2")->getTransform().getPosition().getY() << ")" << std::endl;
    std::cout << "[2, 1]: " << "(" << managers.find("2")->second.getEntity("1")->getTransform().getPosition().getX() << ", " << managers.find("2")->second.getEntity("1")->getTransform().getPosition().getY() << ")" << std::endl;
    std::cout << "[2, 2]: " << "(" << managers.find("2")->second.getEntity("2")->getTransform().getPosition().getX() << ", " << managers.find("2")->second.getEntity("2")->getTransform().getPosition().getY() << ")" << std::endl;

    EXPECT_TRUE(managers.find("1")->second.getEntity("1")->getTransform().getPosition().getX() == 4 && managers.find("1")->second.getEntity("1")->getTransform().getPosition().getY() == 1);
    EXPECT_TRUE(managers.find("1")->second.getEntity("2")->getTransform().getPosition().getX() == 10 && managers.find("1")->second.getEntity("2")->getTransform().getPosition().getY() == 7);
    EXPECT_TRUE(managers.find("2")->second.getEntity("1")->getTransform().getPosition().getX() == 0 && managers.find("2")->second.getEntity("1")->getTransform().getPosition().getY() == 5);
    EXPECT_TRUE(managers.find("2")->second.getEntity("2")->getTransform().getPosition().getX() == 6 && managers.find("2")->second.getEntity("2")->getTransform().getPosition().getY() == 11);
}
/*
TEST_F(CollisionFixture, resolveEntityCollisions) {

}

TEST_F(CollisionFixture, controlEntityCollisions) {

}

TEST_F(CollisionFixture, controlColliderCollisions) {

}

TEST_F(CollisionFixture, calculateResultingVector2D) {

}

TEST_F(CollisionFixture, resolveLocalCollisions) {

}
*/





