#include "EntityObserver.h"

#include <utility>
#include "Input.h"

EntityObserver::EntityObserver(const std::map<std::string, Signature>& signatures, Entity* entity, const std::function<void()>& function) : Observer(signatures, function), entity(entity) {}

void EntityObserver::update() {
    if (entity->getManagerStatus().active && !entity->getManagerStatus().frozen) {
        Observer::update();
    }
}

bool EntityObserver::hasTarget() const {
    return entity->isActive();
}

