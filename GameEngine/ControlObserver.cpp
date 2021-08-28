#include "ControlObserver.h"
#include "Input.h"

ControlObserver::ControlObserver(Entity* entity, std::function<void(Entity*, const SDL_Event*)> function) : entity(entity), function(function) {
    Input::getInstance().append(this);
}

void ControlObserver::update(const SDL_Event* event) {
    function(entity, event);
}
