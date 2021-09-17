#include <odp/EntityObserver.h>
#include "Player.h"
#include "../Scheduler.h"

Player::Player(const std::string& texturePath, int speed, unsigned short hp, unsigned short mana, unsigned short accuracy, double critRate, std::function<void()> specialAbility, std::function<void()> passiveAbility) : Entity(texturePath, true), hp(hp), mana(mana), accuracy(accuracy), critRate(critRate), specialAbility(specialAbility), passiveAbility(passiveAbility) {
    this->getTransform().setSpeed(speed);
    //Scheduler::getInstance().addObserver(new EntityObserver({}, this, [&](){}));
}
