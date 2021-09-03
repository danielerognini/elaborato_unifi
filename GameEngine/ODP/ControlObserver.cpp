#include "ControlObserver.h"

#include <utility>
#include "Input.h"

ControlObserver::ControlObserver(std::unordered_map<std::string, Signature> signatures, Entity* entity, std::function<void(Entity*)> function) : Observer(std::move(signatures)), entity(entity), function(std::move(function)) {}

void ControlObserver::update() {
    if(entity->getManagerStatus().active && !entity->getManagerStatus().frozen) {
        function(entity);
    }
}

