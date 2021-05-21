#include <list>
#include <future>
#include "Manager.h"

void Manager::flush() {
    for(std::unordered_map<std::string, std::unique_ptr<Entity>>::iterator iter = entities.begin(); iter != entities.end(); iter++){
        if(!iter->second->isActive()){
            removeEntity(iter->first);
        }
    }
}

void Manager::update() {
    std::list<std::future<void>> asyncCalls;
    for(std::unordered_map<std::string, std::unique_ptr<Entity>>::iterator iter = entities.begin(); iter != entities.end(); iter++){
        asyncCalls.push_front(std::async(std::launch::async, &Entity::update, iter->second.get()));
    }
    for(std::list<std::future<void>>::iterator iter = asyncCalls.begin(); iter != asyncCalls.end(); iter++) {
        iter->get();
    }
}

void Manager::draw() {
    for(std::unordered_map<std::string, std::unique_ptr<Entity>>::iterator iter = entities.begin(); iter != entities.end(); iter++){
        iter->second->draw();
    }
}

bool Manager::addEntity(const std::string& name, std::unique_ptr<Entity> entity) {
    return entities.emplace(name, std::move(entity)).second;
}

bool Manager::removeEntity(const std::string& name) {
    return entities.erase(name);
}

std::unique_ptr<Entity>& Manager::getEntity(const std::string& name) {
    std::unordered_map<std::string, std::unique_ptr<Entity>>::iterator result = entities.find(name);
    if (result == entities.end()) {
        throw std::runtime_error("\"" + name + "\" key does not exists in this unordered_map");
    }
    return result->second;
}

const bool& Manager::isLocalCollisionsActive() const {
    return localCollisionsActive;
}

void Manager::setLocalCollisionsActive(const bool& localCollisionsActive) {
    this->localCollisionsActive = localCollisionsActive;
}

const bool& Manager::isGlobalCollisionsActive() const {
    return globalCollisionsActive;
}

void Manager::setGlobalCollisionsActive(const bool& globalCollisionsActive) {
    this->globalCollisionsActive = globalCollisionsActive;
}

const unsigned int& Manager::getPriority() const {
    return priority;
}

void Manager::setPriority(const unsigned int& priority) {
    this->priority = priority;
}

Manager::Manager(const bool& active) {
    this->active = active;
}

std::unordered_map<std::string, std::unique_ptr<Entity>>::iterator Manager::getEntitiesBegin() {
    return entities.begin();
}

std::unordered_map<std::string, std::unique_ptr<Entity>>::iterator Manager::getEntitiesEnd() {
    return entities.end();
}