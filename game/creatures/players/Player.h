#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <functional>
#include <ecs/Entity.h>
#include "../../Inventory.h"
#include "../../Interactable.h"

class Player : public Entity {
public:
    Player(const std::string& texturePath, int speed, unsigned short int hp, unsigned short int mana, unsigned short int accuracy, double critRate, std::function<void()> specialAbility, std::function<void()> passiveAbility);
    unsigned short int getHP();
    void setHP(unsigned short int hp);
    void addHP(unsigned short int hp);
    void subtractHP(unsigned short int hp);
    unsigned short int getMana();
    void setMana(unsigned short int mana);
    void addMana(unsigned short int mana);
    void subtractMana(unsigned short int mana);
    void resolveCollision(Entity* externalEntity, const Vector2D& collisionVector) override;
    void update() override;

private:
    unsigned short int hp;
    unsigned short int mana;
    unsigned short int accuracy;
    double critRate;
    Inventory inventory;
    Interactable* interactable;
    
    std::function<void()> specialAbility;
    std::function<void()> passiveAbility;
};


#endif //GAME_PLAYER_H
