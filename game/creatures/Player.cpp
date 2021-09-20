#include "Player.h"
#include "../Scheduler.h"

Player::Player(const std::string& texturePath, int speed, unsigned short hp, unsigned short mana, unsigned short accuracy, double critRate, std::function<void()> specialAbility, std::function<void()> passiveAbility) : Entity(texturePath, true), hp(hp), mana(mana), accuracy(accuracy), critRate(critRate), specialAbility(specialAbility), passiveAbility(passiveAbility) {
    this->getTransform().setSpeed(speed);
}

unsigned short int Player::getHP() {
    return hp;
}

void Player::setHP(unsigned short int hp) {
    this->hp = hp;
}

void Player::addHP(unsigned short int hp) {
    this->hp += hp;
    getSprite().playAnimation("healed"); //TODO: confirm
}

void Player::subtractHP(unsigned short int hp) {
    this->hp -= hp;
    getSprite().playAnimation("damaged"); //TODO: confirm
}

unsigned short int Player::getMana() {
    return mana;
}

void Player::setMana(unsigned short mana) {
    this->mana = mana;
}

void Player::addMana(unsigned short mana) {
    this->mana += mana;
}

void Player::subtractMana(unsigned short mana) {
    this->mana -= mana;
}

void Player::resolveCollision(Entity* externalEntity, const Vector2D& collisionVector) {
    Entity::resolveCollision(externalEntity, collisionVector);
    if (isInstanceOf<Interactable>(&externalEntity)) {
        if (interactable == nullptr) {
            interactable = dynamic_cast<Interactable*>(externalEntity);
            interactable->setHighlighted(true);
        }
    }
}

void Player::update() {
    if (interactable != nullptr) {
        interactable->setHighlighted(false);
        interactable = nullptr;
    }
    Entity::update();
}
