#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "Room.h"

enum RoomType {
    SPAWN, BOSS, ENCOUNTER, LOOT, HALLWAY
};

struct RoomPlaceholder {
    explicit RoomPlaceholder(RoomType type) {
        this->type = type;
    }
    
    bool linked = false;
    Doors doors;
    RoomType type;
};

class Map {
public:
    Map();
private:
    std::vector<std::vector<u_ptr<RoomPlaceholder>>> grid;
    unsigned short int roomNumber;
    unsigned short int lootChance{20};
    
    std::string getRoomTemplate(RoomType type, const std::string& name);
    void reserveMatrix();
    void placeRooms();
    void linkRooms(unsigned int row, unsigned int column);
};


#endif //GAME_MAP_H
