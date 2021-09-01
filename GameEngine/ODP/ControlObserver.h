#ifndef GAME_CONTROLOBSERVER_H
#define GAME_CONTROLOBSERVER_H

#include "Observer.h"
#include <functional>
#include "ECS/Entity.h"

class ControlObserver : public Observer {
public:
    void update() override;
    
    ControlObserver(std::unordered_map<std::string, Signature> signatures, Entity* entity, std::function<void(Entity*)> function);
    ~ControlObserver() override = default;

private:
    Entity* entity;
    std::function<void(Entity*)> function;
};

#endif //GAME_CONTROLOBSERVER_H
