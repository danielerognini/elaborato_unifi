#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "Room.h"

enum RoomType {
    SPAWN, BOSS, ENCOUNTER, LOOT
};

struct RoomPlaceholder {
    bool linked = false;
    RoomType type;
};

class Map {
public:
    Map();
private:
    unsigned short int x;
    unsigned short int y;
    std::vector<std::vector<u_ptr<RoomPlaceholder>>> grid;
    unsigned short int roomNumber;
    unsigned short int lootChance{20};
    
    std::string getRoomTemplate(RoomType type, const std::string& name);
    void placeRooms();
    void reserveMatrix();
};


#endif //GAME_MAP_H
