#include <list>
#include <future>
#include "Manager.h"

void Manager::flush() {
    for (auto& entity: entities) {
        if (!entity->isActive()) {
            removeEntity(entity.get());
        }
    }
}

void Manager::update() {
    std::list<std::future<void>> asyncCalls;
    for (auto& entity: entities) {
        if (entity->isActive()) {
            asyncCalls.push_back(std::async(std::launch::async, &Entity::update, entity.get()));
        }
    }
    for (auto& asyncCall: asyncCalls) {
        asyncCall.get();
    }
}

void Manager::draw() {
    for (auto& entity: entities) {
        if (entity->isActive()) {
            entity->draw();
        }
    }
}

bool Manager::addEntity(Entity* entity) {
    bool result = false;
    if (entities.find(tmp_ptr<Entity>(entity)) == entities.end()) {
        entity->setManagerStatus({&active, &frozen});
        result = entities.emplace(entity).second;
    }
    return result;
}

bool Manager::removeEntity(Entity* entity) {
    return entities.erase(tmp_ptr<Entity>(entity));
}

bool Manager::isLocalCollisionsActive() const {
    return localCollisionsActive;
}

void Manager::setLocalCollisionsActive(bool localCollisionsActive) {
    this->localCollisionsActive = localCollisionsActive;
}

bool Manager::isGlobalCollisionsActive() const {
    return globalCollisionsActive;
}

void Manager::setGlobalCollisionsActive(bool globalCollisionsActive) {
    this->globalCollisionsActive = globalCollisionsActive;
}

unsigned int Manager::getPriority() const {
    return priority;
}

void Manager::setPriority(unsigned int priority) {
    this->priority = priority;
}

Manager::Manager(unsigned int priority, bool localCollisionsActive, bool globalCollisionsActive, bool active) : Activatable(active), priority(priority), localCollisionsActive(localCollisionsActive), globalCollisionsActive(globalCollisionsActive), frozen(false) {
}

std::unordered_set<u_ptr<Entity>, std::hash<u_ptr<Entity>>, U_ptrComparator<Entity>>::iterator Manager::begin() {
    return entities.begin();
}

std::unordered_set<u_ptr<Entity>, std::hash<u_ptr<Entity>>, U_ptrComparator<Entity>>::iterator Manager::end() {
    return entities.end();
}

bool Manager::isFrozen() {
    return frozen;
}

void Manager::setFrozen(bool frozen) {
    this->frozen = frozen;
}

bool Manager::find(Entity* entity) {
    return entities.find(tmp_ptr<Entity>(entity)) != entities.end();
}
