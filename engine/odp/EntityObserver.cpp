#include "EntityObserver.h"

EntityObserver::EntityObserver(const std::map<std::string, Signature>& signatures, Entity* entity, const std::function<void(Entity*)>& function, const std::function<void()>& observerFunction) : Observer(signatures, observerFunction), entity(entity), function(function) {}

void EntityObserver::update() {
    if (entity->getManagerStatus().active && !entity->getManagerStatus().frozen) {
        function(entity);
        Observer::update();
    }
}

bool EntityObserver::hasTarget() const {
    return entity->isActive();
}

