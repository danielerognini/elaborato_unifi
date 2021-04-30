#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H


#include <unordered_map>
#include "ECS/Manager.h"

class Collision {
public:
    static void update(std::unordered_map<std::string, Manager>& managers);
};


#endif //GAME_COLLISION_H
