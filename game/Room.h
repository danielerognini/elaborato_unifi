#ifndef GAME_ROOM_H
#define GAME_ROOM_H

#include <map>
#include <string>
#include "ecs/Manager.h"

struct Doors {
    bool nord = false;
    bool sud = false;
    bool east = false;
    bool west = false;
};

struct Node {
    Vector2D position;
    unsigned short int range = 0;
    std::list<Node*> linkedNodes;
};

struct RoomTile {
    unsigned short int index = 0;
    unsigned short int frame = 0;
    Vector2D offset;
};

class Room : public Activatable {
public:
    Room(const std::string& name, const std::string& roomTemplate, unsigned int priorityOffset, bool discovered, bool active);
    ~Room() override;
    
    void enable() override;
    void disable() override;
    
    std::map<std::string, std::shared_ptr<Manager>>::iterator begin();
    std::map<std::string, std::shared_ptr<Manager>>::iterator end();
    Manager& getLayer(std::string layer);
    
    bool isDiscovered() const;
    void discover();
    
    void setPosition(const Vector2D& position);
    const Vector2D& getPosition();
    const Vector2D& getDimension();
    
    void lock();
    void unlock();
    
    const std::string& getName();

private:
    bool discovered;
    std::string name;
    std::map<std::string, std::shared_ptr<Manager>> layers;
    Vector2D position;
    Vector2D dimension;
    std::list<Node> nodes;
    Doors doorSides;
    std::list<Vector2D> spawnPoints;
    std::list<RoomTile> tiles;
    void parseFile();
};


#endif //GAME_ROOM_H
