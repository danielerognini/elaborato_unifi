#include "gtest/gtest.h"
#include "ECS/Entity.h"
#include <iostream>

class EntityFixture : public ::testing::Test{
protected:
    EntityFixture () : entity(Entity("")) {}
    virtual void SetUp() {
        entity.addCollider("1", std::unique_ptr<std::vector<Border>>(new std::vector<Border>({Border(Vector2D(0, 0), Vector2D(4, 0), true), Border(Vector2D(4, 0), Vector2D(4, 4), true), Border(Vector2D(4, 4), Vector2D(0, 4), true), Border(Vector2D(0, 4), Vector2D(0, 0), true)})), true);
    }
    Entity entity;
};

TEST_F(EntityFixture, addCollider) {
    EXPECT_TRUE(entity.addCollider("2", std::unique_ptr<std::vector<Border>>(new std::vector<Border>({Border(Vector2D(0, 0), Vector2D(4, 0), true), Border(Vector2D(4, 0), Vector2D(4, 4), true), Border(Vector2D(4, 4), Vector2D(0, 4), true), Border(Vector2D(0, 4), Vector2D(0, 0), true)})), true));
    EXPECT_FALSE(entity.addCollider("2", std::unique_ptr<std::vector<Border>>(new std::vector<Border>({Border(Vector2D(0, 0), Vector2D(4, 0), true), Border(Vector2D(4, 0), Vector2D(4, 4), true), Border(Vector2D(4, 4), Vector2D(0, 4), true), Border(Vector2D(0, 4), Vector2D(0, 0), true)})), true));
}

TEST_F(EntityFixture, removeCollider) {
    EXPECT_TRUE(entity.removeCollider("1"));
    EXPECT_FALSE(entity.removeCollider("1"));
}

TEST_F(EntityFixture, resolveCollision) {
    Entity external = Entity("");
    external.getTransform().setPosition(3, 3);
    external.getTransform().setSpeed(1);
    external.getTransform().setDirection(-M_PI_2 * 3);
    external.getTransform().setMoving(true);
    external.addCollider("2", std::unique_ptr<std::vector<Border>>(new std::vector<Border>({Border(Vector2D(0, 0), Vector2D(4, 0), true), Border(Vector2D(4, 0), Vector2D(4, 4), true), Border(Vector2D(4, 4), Vector2D(0, 4), true), Border(Vector2D(0, 4), Vector2D(0, 0), true)})), true);
    entity.getTransform().setPosition(1, 2);
    entity.getTransform().setSpeed(1);
    entity.getTransform().setDirection(M_PI_2);
    entity.getTransform().setMoving(true);
    std::cout << "BEFORE" << std::endl;
    std::cout << "Entity: (" << entity.getTransform().getPosition().getX() << ", " << entity.getTransform().getPosition().getY() << ") borders: ";
    for (int i = 0; i < 4; i++) {
        std::cout << "(" << std::next(entity.getCollider("1").getBordersBegin(), i)->getPrevVertex().getX() << ", " << std::next(entity.getCollider("1").getBordersBegin())->getPrevVertex().getY() << ") ";
    }
    std::cout << std::endl;
    std::cout << "External: (" << external.getTransform().getPosition().getX() << ", " << external.getTransform().getPosition().getY() << ") borders: ";
    for (int i = 0; i < 4; i++) {
        std::cout << "(" << std::next(external.getCollider("2").getBordersBegin(), i)->getPrevVertex().getX() << ", " << std::next(external.getCollider("2").getBordersBegin())->getPrevVertex().getY() << ") ";
    }
    std::cout << std::endl;
    entity.resolveCollision(external, Vector2D(2, 3));
    external.resolveCollision(entity, Vector2D(-2, -3));
    std::cout << "AFTER" << std::endl;
    std::cout << "Entity: (" << entity.getTransform().getPosition().getX() << ", " << entity.getTransform().getPosition().getY() << ") borders: ";
    for (int i = 0; i < 4; i++) {
        std::cout << "(" << std::next(entity.getCollider("1").getBordersBegin(), i)->getPrevVertex().getX() << ", " << std::next(entity.getCollider("1").getBordersBegin())->getPrevVertex().getY() << ") ";
    }
    std::cout << std::endl;
    std::cout << "External: (" << external.getTransform().getPosition().getX() << ", " << external.getTransform().getPosition().getY() << ") borders: ";
    for (int i = 0; i < 4; i++) {
        std::cout << "(" << std::next(external.getCollider("2").getBordersBegin(), i)->getPrevVertex().getX() << ", " << std::next(external.getCollider("2").getBordersBegin())->getPrevVertex().getY() << ") ";
    }
    std::cout << std::endl;
    EXPECT_TRUE(entity.getTransform().getPosition().getX() == 0 && entity.getTransform().getPosition().getY() == 4);
    EXPECT_TRUE(external.getTransform().getPosition().getX() == 4 && external.getTransform().getPosition().getY() == 0);
}
