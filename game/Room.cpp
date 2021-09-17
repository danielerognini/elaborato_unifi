#include <string>
#include "Engine.h"
#include "Room.h"
#include "enviroment/Door.h"

Room::Room(const std::string& name, const std::string& roomTemplate, unsigned int priorityOffset, bool discovered, bool active) : Activatable(active), name(name) {
    //TODO: template room file parsing.
    dimension = Vector2D(0, 0); //TODO: replace with data parsed from template
    position = Vector2D(0, 0);
    std::list<std::string> layersNames = {name + "_enviroment", name + "_doors", name + "_enemies", name + "_NPCs", name + "_items", name + "_bullets"};
    for (int i = 0; i < layersNames.size(); i++) {
        Engine::getInstance().addManager(*std::next(layersNames.begin(), i), i + priorityOffset);
        layers.emplace(*std::next(layersNames.begin(), i), &Engine::getInstance().getManager(*std::next(layersNames.begin(), i)));
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
        dynamic_cast<Door*>(door.get())->lock();
    }
}

void Room::unlock() {
    std::shared_ptr<Manager> doors = layers.find(name + "_doors")->second;
    for (auto& door: *doors) {
        dynamic_cast<Door*>(door.get())->unlock();
    }
}

void Room::setPosition(const Vector2D& position) {
    this->position = position;
}

const Vector2D& Room::getPosition() {
    return position;
}

const Vector2D& Room::getDimension() {
    return dimension;
}

Manager& Room::getLayer(std::string layer) {
    return *layers.find(name + "_" + layer)->second;
}

const std::string &Room::getName() {
    return name;
}
