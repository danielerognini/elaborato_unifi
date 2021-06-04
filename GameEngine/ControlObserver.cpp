#include "ControlObserver.h"
#include "Input.h"

ControlObserver::ControlObserver(Entity* entity, std::function<void(Entity*)> function) : entity(entity), function(function) {
    Input::getInstance().append(this);
}

void ControlObserver::update() {
    function(entity);
}
