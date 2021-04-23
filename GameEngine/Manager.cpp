#include "Manager.h"

void Manager::flush() {
    for(std::map<std::string, Entity>::iterator iter = entities.begin(); iter != entities.end(); iter++){
        if(!iter->second.isActive()){
            removeEntity(iter->first);
        }
    }
}

void Manager::update() {
    for(std::map<std::string, Entity>::iterator iter = entities.begin(); iter != entities.end(); iter++){
        iter->second.update();
    }
}

void Manager::draw() {
    for(std::map<std::string, Entity>::iterator iter = entities.begin(); iter != entities.end(); iter++){
        iter->second.draw();
    }
}

bool Manager::addEntity(std::string name) {
    return entities.emplace(name, Entity()).second;
}

bool Manager::removeEntity(std::string name) {
    return entities.erase(name);
}

Entity* Manager::getEntity(std::string name) {
    return &entities.find(name)->second;
}
