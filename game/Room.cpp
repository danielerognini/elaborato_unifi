#include <string>
#include <fstream>
#include <sstream>
#include "Engine.h"
#include "Room.h"
#include "enviroment/Door.h"

Room::Room(const std::string& name, const std::string& roomTemplate, unsigned int priorityOffset, bool discovered, bool active) : Activatable(active), name(name) {
    parseFile();
    position = Vector2D(0, 0);
    std::list<std::string> layersNames = {name + "_enviroment", name + "_colliders", name + "_doors", name + "_enemies", name + "_NPCs", name + "_items", name + "_bullets"};
    for (int i = 0; i < layersNames.size(); i++) {
        Engine::getInstance().addManager(*std::next(layersNames.begin(), i), i + priorityOffset);
        layers.emplace(std::next(layersNames.begin(), i)->substr(name.length() + 1), &Engine::getInstance().getManager(*std::next(layersNames.begin(), i)));
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

void Room::parseFile() {
    //TODO: implement validator
    std::ifstream file("");
    std::stringstream line;
    std::string str;
    std::__cxx11::list<std::vector<Border>> colliders;
    Vector2D pVertex;
    Vector2D nVertex;
    bool innerSide;
    std::unordered_map<std::string, RoomNode> roomNodes;
    std::string nodeIndex;
    auto nextField = [&]() { return static_cast<bool>(getline(line, str, ' ')); };
    
    if (file) {
        getline(file, str);
        line << str + " ";
        nextField();
        dimension.setX(std::stoi(str));
        nextField();
        dimension.setY(std::stoi(str));
        getline(file, str);
        line.clear();
    }
    while (!str.empty() && getline(file, str)) {
        line << str + " ";
        tiles.emplace_back(RoomTile());
        nextField();
        tiles.back().index = std::stoul(str);
        nextField();
        tiles.back().frame = std::stoul(str);
        nextField();
        tiles.back().offset.setX(std::stoi(str));
        nextField();
        tiles.back().offset.setY(std::stoi(str));
        line.clear();
    }
    while (!str.empty() && getline(file, str)) {
        line << str + " ";
        if (str == "@") {
            colliders.emplace_back(std::vector<Border>());
        } else {
            nextField();
            pVertex.setX(std::stoi(str));
            nextField();
            pVertex.setY(std::stoi(str));
            nextField();
            nVertex.setX(std::stoi(str));
            nextField();
            nVertex.setY(std::stoi(str));
            nextField();
            innerSide = static_cast<bool>(std::stoi(str));
            colliders.back().emplace_back(pVertex, nVertex, innerSide);
        }
        line.clear();
    }
    
    getline(file, str);
    line << str + " ";
    nextField();
    doorSides.north = static_cast<bool>(std::stoi(str));
    nextField();
    doorSides.south = static_cast<bool>(std::stoi(str));
    nextField();
    doorSides.east = static_cast<bool>(std::stoi(str));
    nextField();
    doorSides.west = static_cast<bool>(std::stoi(str));
    line.clear();
    
    while (!str.empty() && getline(file, str)) {
        line << str + " ";
        spawnPoints.emplace_back(Vector2D());
        nextField();
        spawnPoints.back().setX(std::stoi(str));
        nextField();
        spawnPoints.back().setY(std::stoi(str));
        line.clear();
    }
    while (!str.empty() && getline(file, str)) {
        line << str + " ";
        nextField();
        roomNodes[nodeIndex = str] = RoomNode();
        nextField();
        roomNodes[nodeIndex].position.setX(std::stoi(str));
        nextField();
        roomNodes[nodeIndex].position.setY(std::stoi(str));
        nextField();
        roomNodes[nodeIndex].range = std::stoul(str);
        line.clear();
    }
    while (!str.empty() && getline(file, str)) {
        line << str + " ";
        nextField();
        nodeIndex = str;
        while (nextField()) {
            roomNodes[nodeIndex].linkedNodes.emplace_back(&roomNodes[str]);
        }
        protoNodes.emplace_back(roomNodes[nodeIndex]);
    }
    file.close();
}

void Room::placeRoom() {
    for (auto& tile: tiles) {
        layers["enviroment"]->addEntity(Factory::createTile(tile.index, tile.frame, biome, position + tile.offset));
    }
}

void Room::calculateShorthestPath() {
    for (auto& protoNode: protoNodes) {
        //TODO: implement dijkstra algorithm
    }
}
