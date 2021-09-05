#ifndef GAME_ENTITYOBSERVER_H
#define GAME_ENTITYOBSERVER_H

#include "Observer.h"
#include <functional>
#include "ECS/Entity.h"

class EntityObserver : public Observer {
public:
    EntityObserver(const std::unordered_map<std::string, Signature>& signatures, Entity* entity, const std::function<void()>& function);
    ~EntityObserver() override = default;
    void update() override;

private:
    Entity* entity;
};

#endif //GAME_ENTITYOBSERVER_H
