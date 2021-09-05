#include "EntityObserver.h"

#include <utility>
#include "Input.h"

EntityObserver::EntityObserver(const std::unordered_map<std::string, Signature>& signatures, Entity* entity, const std::function<void()>& function) : Observer(std::move(signatures), std::move(function)), entity(entity) {}

void EntityObserver::update() {
    if (entity->getManagerStatus().active && !entity->getManagerStatus().frozen) {
        Observer::update();
    }
}

