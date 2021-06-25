#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Entity.h"
#include "../Activatable.h"
#include <unordered_map>


class Manager : public Activatable{
public:
    explicit Manager(const unsigned int& priority, const bool& localCollisionsActive = true, const bool& globalCollisionsActive = true, const bool& active = false);

    void flush();
    void update();
    void draw();

    bool addEntity(const std::string& name, std::unique_ptr<Entity> entity);
    bool removeEntity(const std::string& name);
    std::shared_ptr<Entity> getEntity(const std::string& name);

    std::unordered_map<std::string, std::shared_ptr<Entity>>::iterator getEntitiesBegin();
    std::unordered_map<std::string, std::shared_ptr<Entity>>::iterator getEntitiesEnd();

    const bool& isLocalCollisionsActive() const;

    void setLocalCollisionsActive(const bool& localCollisionsActive);

    const bool& isGlobalCollisionsActive() const;

    void setGlobalCollisionsActive(const bool& globalCollisionsActive);

    const unsigned int& getPriority() const;

    void setPriority(const unsigned int& priority);

private:
    std::unordered_map<std::string, std::shared_ptr<Entity>> entities;
    bool localCollisionsActive;
    bool globalCollisionsActive;
    unsigned int priority;
};


#endif //GAME_MANAGER_H
