#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Entity.h"
#include "../Activatable.h"
#include <unordered_map>


class Manager : public Activatable{
private:
    std::unordered_map<std::string, Entity*> entities;
    bool localCollisionsActive;
    bool globalCollisionsActive;

    unsigned int priority;

public:
    explicit Manager(bool active = false);

    void flush();
    void update();
    void draw();

    bool addEntity(std::string name);
    bool removeEntity(std::string name);
    Entity* getEntity(std::string name);

    std::unordered_map<std::string, Entity*>::iterator getEntitiesBegin();
    std::unordered_map<std::string, Entity*>::iterator getEntitiesEnd();

    bool isLocalCollisionsActive() const;

    void setLocalCollisionsActive(bool localCollisionsActive);

    bool isGlobalCollisionsActive() const;

    void setGlobalCollisionsActive(bool globalCollisionsActive);

    unsigned int getPriority() const;

    void setPriority(unsigned int priority);
};


#endif //GAME_MANAGER_H
