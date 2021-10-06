#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "Room.h"

enum TemplateType {
    SPAWN, BOSS, ENCOUNTER, LOOT
};

class Map {
public:
    Map();
private:
    unsigned short int x;
    unsigned short int y;
    std::vector<std::vector<u_ptr<Room>>> grid;
    unsigned short int roomNumber;
    
    std::string getRoomTemplate(TemplateType type, const std::string& name);
};


#endif //GAME_MAP_H
