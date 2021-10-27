#ifndef GAME_ENTITYOBSERVER_H
#define GAME_ENTITYOBSERVER_H

#include "Observer.h"
#include <functional>
#include "ecs/Entity.h"

class EntityObserver : public Observer {
public:
    EntityObserver(const std::map<std::string, Signature>& signatures, Entity* entity, const std::function<void(Entity*)>& function, const std::function<void()>& observerFunction = []() {});
    void update() override;
    bool hasTarget() const override;

private:
    Entity* entity;
    std::function<void(Entity*)> function;
};

#endif //GAME_ENTITYOBSERVER_H
