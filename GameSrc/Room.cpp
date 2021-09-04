#include <string>
#include "Engine.h"
#include "Room.h"

Room::Room(const std::string& name, unsigned int priorityOffset, bool discovered, bool active) : name(name) {
    std::list<std::string> layersName = {name + "_enviroment", name + "_doors", name + "_enemies", name + "_NPCs", name + "_pets", name + "_players", name + "_items", name + "_bullets"};
    for (int i = 0; i < layersName.size(); i++) {
        Engine::getInstance().addManager(*std::next(layersName.begin(), i), i + priorityOffset);
        layers.emplace(*std::next(layersName.begin(), i), &Engine::getInstance().getManager(*std::next(layersName.begin(), i)));
    }
}

Room::~Room() {
    for (auto& layer: layers) {
        Engine::getInstance().removeManager(layer.first);
    }
}

void Room::enable() {
    Activatable::enable();
    for (auto& layer: layers) {
        layer.second->enable();
    }
}

void Room::disable() {
    Activatable::disable();
    for (auto& layer: layers) {
        layer.second->disable();
    }
}

std::map<std::string, std::shared_ptr<Manager>>::iterator Room::begin() {
    return layers.begin();
}

std::map<std::string, std::shared_ptr<Manager>>::iterator Room::end() {
    return layers.end();
}

bool Room::isDiscovered() const {
    return discovered;
}

void Room::discover() {
    discovered = true;
}

void Room::lock() {
    std::shared_ptr<Manager> doors = layers.find(name + "_doors")->second;
    for (auto& door: *doors) {
        // door lock
    }
}

void Room::unlock() {
    std::shared_ptr<Manager> doors = layers.find(name + "_doors")->second;
    for (auto& door: *doors) {
        // door unlock
    }
}
