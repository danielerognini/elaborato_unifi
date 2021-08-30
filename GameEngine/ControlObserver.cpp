#include "ControlObserver.h"

#include <utility>
#include "Input.h"

ControlObserver::ControlObserver(std::list<Signature> signatures, Entity* entity, std::function<void(Entity*)> function) : Observer(std::move(signatures)), entity(entity), function(std::move(function)) {}

void ControlObserver::update() {
    function(entity);
}

