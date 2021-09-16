#ifndef GAME_ENTITYOBSERVER_H
#define GAME_ENTITYOBSERVER_H

#include "Observer.h"
#include <functional>
#include "ECS/Entity.h"

class EntityObserver : public Observer {
public:
    EntityObserver(const std::map<std::string, Signature>& signatures, Entity* entity, const std::function<void()>& function);
    void update() override;
    bool hasTarget() const override;

private:
    Entity* entity;
};

#endif //GAME_ENTITYOBSERVER_H
