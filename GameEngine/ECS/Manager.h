#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Entity.h"
#include "../Activatable.h"
#include "Utility.h"
#include <unordered_set>

class Manager : public Activatable {
public:
    explicit Manager(unsigned int priority, bool localCollisionsActive = true, bool globalCollisionsActive = true, bool active = false);
    
    void flush();
    void update();
    void draw();
    
    bool addEntity(Entity* entity);
    bool removeEntity(Entity* entity);
    
    std::unordered_set<u_ptr<Entity>>::iterator begin();
    std::unordered_set<u_ptr<Entity>>::iterator end();
    
    bool find(Entity* entity);
    
    bool isLocalCollisionsActive() const;
    
    void setLocalCollisionsActive(bool localCollisionsActive);
    
    bool isGlobalCollisionsActive() const;
    
    void setGlobalCollisionsActive(bool globalCollisionsActive);
    
    unsigned int getPriority() const;
    
    void setPriority(unsigned int priority);

    bool isFrozen();
    void setFrozen(bool frozen);

private:
    std::unordered_set<u_ptr<Entity>> entities;
    bool localCollisionsActive;
    bool globalCollisionsActive;
    unsigned int priority;
    bool frozen;
};

#endif //GAME_MANAGER_H
