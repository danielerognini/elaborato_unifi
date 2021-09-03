#include <list>
#include <future>
#include "Manager.h"

void Manager::flush() {
    for (auto& entity: entities) {
        if (!entity.second.isActive()) {
            removeEntity(entity.first);
        }
    }
}

void Manager::update() {
    std::list<std::future<void>> asyncCalls;
    for (auto& entity: entities) {
        if(entity.isActive()){
            asyncCalls.push_back(std::async(std::launch::async, &Entity::update, entity.second));
        }
    }
    for (auto& asyncCall: asyncCalls) {
        asyncCall.get();
    }
}

void Manager::draw() {
    for (auto& entity: entities) {
        if(entity.isActive()) {
            entity.second.draw();
        }
    }
}

bool Manager::addEntity(const std::string& name, Entity entity) {
    entity.setManagerStatus({&active, &frozen});
    return entities.emplace(name, std::move(entity)).second;
}

bool Manager::removeEntity(const std::string& name) {
    return entities.erase(name);
}

Entity& Manager::getEntity(const std::string& name) {
    auto result = entities.find(name);
    if (result == entities.end()) {
        throw std::runtime_error("\"" + name + "\" key does not exists in this unordered_map");
    }
    return result->second;
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

Manager::Manager(unsigned int priority, bool localCollisionsActive, bool globalCollisionsActive, bool active) : priority(priority), localCollisionsActive(localCollisionsActive), globalCollisionsActive(globalCollisionsActive) {
    this->active = active;
}

std::unordered_map<std::string, Entity>::iterator Manager::begin() {
    return entities.begin();
}

std::unordered_map<std::string, Entity>::iterator Manager::end() {
    return entities.end();
}

bool Manager::isFrozen() {
    return frozen;
}

void Manager::setFrozen(bool frozen) {
    this->frozen = frozen;
}
