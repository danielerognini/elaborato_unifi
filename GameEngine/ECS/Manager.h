#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Entity.h"
#include "../Activatable.h"
#include <unordered_map>


class Manager : public Activatable{
private:
    std::unordered_map<std::string, Entity*> entities;
    bool active;

public:
    void flush();
    void update();
    void draw();

    bool addEntity(std::string name);
    bool removeEntity(std::string name);
    Entity* getEntity(std::string name);
};


#endif //GAME_MANAGER_H
