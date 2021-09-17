#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <functional>
#include <ecs/Entity.h>

class Player : public Entity {
public:
    Player(const std::string& texturePath, int speed, unsigned short int hp, unsigned short int mana, unsigned short int accuracy, double critRate, std::function<void()> specialAbility, std::function<void()> passiveAbility);
private:
    unsigned short int hp;
    unsigned short int mana;
    unsigned short int accuracy;
    double critRate;
    
    std::function<void()> specialAbility;
    std::function<void()> passiveAbility;
};


#endif //GAME_PLAYER_H
