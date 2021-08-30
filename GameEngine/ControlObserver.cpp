#include "ControlObserver.h"

#include <utility>
#include "Input.h"

ControlObserver::ControlObserver(std::list<Signature> signatures, Entity* entity, std::function<void(Entity*, const SDL_Event*)> function) : Observer(std::move(signatures)), entity(entity), function(std::move(function)) {}

void ControlObserver::update(const SDL_Event* event) {
    function(entity, event);
}

