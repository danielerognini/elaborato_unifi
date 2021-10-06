#include "Map.h"
#include "Utils.h"
#include <filesystem>

Map::Map() {
    roomNumber = random<int>(8, 12);
    y = roomNumber / 2;
    x = y + 2;
    grid.reserve(x);
    for (auto& row: grid) {
        row.reserve(y);
    }
    grid[0][random<int>(0, y - 1)] = u_ptr<Room>(new Room("boss", "", 0, true, true));
    grid[x - 1][random<int>(0, y - 1)] = u_ptr<Room>(new Room("spawn", "", 0, true, true));
}

std::string Map::getRoomTemplate(TemplateType type, const std::string& name) {
    std::string path = "assets/";
    switch (type) {
        case SPAWN:
            path += "spawn/";
            break;
        case BOSS:
            path += "boss/";
            break;
        case ENCOUNTER:
            path += "encounter/";
            break;
        case LOOT:
            path += "loot/";
            break;
    }
    if (name.empty()) {
        std::vector<std::string> files;
        for (auto& file: std::filesystem::directory_iterator(path)) {
            files.emplace_back(file.path().filename());
        }
        path += files[random<int>(0, files.size() - 1)];
    } else {
        path += name + ".room";
    }
    return path;
}
