#include "Manager.h"

void Manager::flush() {
    for(std::unordered_map<std::string, Entity*>::iterator iter = entities.begin(); iter != entities.end(); iter++){
        if(!iter->second->isActive()){
            removeEntity(iter->first);
        }
    }
}

void Manager::update() {
    for(std::unordered_map<std::string, Entity*>::iterator iter = entities.begin(); iter != entities.end(); iter++){
        iter->second->update();
    }
}

void Manager::draw() {
    for(std::unordered_map<std::string, Entity*>::iterator iter = entities.begin(); iter != entities.end(); iter++){
        iter->second->draw();
    }
}

bool Manager::addEntity(std::string name) {
    return entities.emplace(name, new Entity()).second;
}

bool Manager::removeEntity(std::string name) {
    return entities.erase(name);
}

Entity* Manager::getEntity(std::string name) {
    return entities.find(name)->second;
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
