#include <list>
#include <future>
#include "Manager.h"

void Manager::flush() {
    std::erase_if(entities, [](u_ptr<Entity>& entity) { return !entity->isActive(); });
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

void Manager::addEntity(Entity* entity) {
    entity->setManagerStatus({&active, &frozen});
    entities.emplace_back(entity);
}

bool Manager::removeEntity(Entity* entity, bool release) {
    bool result = false;
    for (auto iter = entities.begin(); iter != entities.end() && !result; iter++) {
        if (iter->get() == entity) {
            if (release) {
                iter->release();
            }
            entities.erase(iter);
            result = true;
        }
    }
    return result;
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

std::list<u_ptr<Entity>>::iterator Manager::begin() {
    return entities.begin();
}

std::list<u_ptr<Entity>>::iterator Manager::end() {
    return entities.end();
}

bool Manager::isFrozen() {
    return frozen;
}

void Manager::setFrozen(bool frozen) {
    this->frozen = frozen;
}

bool Manager::find(Entity* entity) {
    bool result = false;
    for (auto iter = entities.begin(); iter != entities.end() && !result; iter++) {
        if (iter->get() == entity) {
            result = true;
        }
    }
    return result;
}
