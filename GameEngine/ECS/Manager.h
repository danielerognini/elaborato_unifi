#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Entity.h"
#include "../Activatable.h"
#include <unordered_map>

class Manager : public Activatable {
public:
    explicit Manager(unsigned int priority, bool localCollisionsActive = true, bool globalCollisionsActive = true, bool active = false);
    
    void flush();
    void update();
    void draw();
    
    bool addEntity(const std::string& name, Entity entity);
    bool removeEntity(const std::string& name);
    Entity& getEntity(const std::string& name);
    
    std::unordered_map<std::string, Entity>::iterator begin();
    std::unordered_map<std::string, Entity>::iterator end();
    
    bool isLocalCollisionsActive() const;
    
    void setLocalCollisionsActive(bool localCollisionsActive);
    
    bool isGlobalCollisionsActive() const;
    
    void setGlobalCollisionsActive(bool globalCollisionsActive);
    
    unsigned int getPriority() const;
    
    void setPriority(unsigned int priority);

private:
    std::unordered_map<std::string, Entity> entities;
    bool localCollisionsActive;
    bool globalCollisionsActive;
    unsigned int priority;
};

#endif //GAME_MANAGER_H
