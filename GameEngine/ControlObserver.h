#ifndef GAME_CONTROLOBSERVER_H
#define GAME_CONTROLOBSERVER_H

#include "Observer.h"
#include <functional>
#include "ECS/Entity.h"

class ControlObserver : public Observer {
public:
    void update(const SDL_Event* event) override;
    
    ControlObserver(Entity* entity, std::function<void(Entity*, const SDL_Event*)> function);
    ~ControlObserver();

private:
    Entity* entity;
    std::function<void(Entity*, const SDL_Event*)> function;
};

#endif //GAME_CONTROLOBSERVER_H
