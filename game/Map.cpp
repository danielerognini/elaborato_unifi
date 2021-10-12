#include "Map.h"
#include "Utils.h"
#include <filesystem>

Map::Map() {
    roomNumber = random<int>(8, 13);
    roomNumber = (roomNumber / 2) * 2;
}

std::string Map::getRoomTemplate(RoomType type, const std::string& name) {
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
        path += files[random<unsigned int>(0, files.size() - 1)];
    } else {
        path += name + ".room";
    }
    return path;
}

void Map::reserveMatrix() {
    unsigned int height = 1;
    unsigned int width = 1;
    unsigned int i = 0;
    unsigned int padded = roomNumber / 3 + 1 + roomNumber;
    while (height * width < padded) {
        if (i % 2 == 0) {
            height++;
        } else {
            width++;
        }
        i++;
    }
    grid.resize(height + 2);
    for (auto& column: grid) {
        column.resize(width);
    }
}

void Map::placeRooms() {
    std::vector<std::vector<unsigned int>> positions(grid.size() - 2);
    for (auto& position: positions) {
        position.reserve(grid[0].size());
        for (int i = 0; i < grid[i].size(); i++) {
            position[i] = i;
        }
    }
    unsigned int spawnIndex = random<int>(1, static_cast<int>(positions[0].size()));
    grid[0][random<int>(1, static_cast<int>(positions[0].size()))].reset(new RoomPlaceholder(BOSS));
    grid[grid.size() - 1][spawnIndex].reset(new RoomPlaceholder(SPAWN));
    unsigned int maxRoomsPerRow = ceil(static_cast<float>(roomNumber) / static_cast<float>(grid.size() - 2));
    std::vector<unsigned int> columnOccupations(grid.size() - 2, 0);
    unsigned int roomPlaced = 0;
    unsigned int rowRooms;
    unsigned int rand;
    while (roomPlaced < roomNumber) {
        for (int i = 0; i < grid.size() - 2; i++) {
            if (positions[i].size() < maxRoomsPerRow) {
                rowRooms = random<unsigned int>(1, maxRoomsPerRow);
                for (int j = 0; j < rowRooms; j++) {
                    rand = random<unsigned int>(0, positions[i].size() - 1);
                    grid[i][positions[i][rand]].reset(new RoomPlaceholder(random<unsigned short int>(1, 100) <= lootChance ? LOOT : ENCOUNTER));
                    positions[i].erase(std::next(positions[i].begin(), rand));
                }
            }
        }
    }
}

void Map::linkRooms(unsigned int row, unsigned int column) {
    auto proximity = [](int t, unsigned short int& x, unsigned short int& y) {
        x = ceil(cos(t * M_PI_2));
        y = ceil(sin(t * M_PI_2));
    };
    unsigned short int x;
    unsigned short int y;
    for (int i = 0; i < 8; i++) {
        proximity(i, x, y);
        x += row;
        y += column;
        if (x <= grid.size() && x >= 0 && y <= grid[x].size() && y >= 0) {
            if (grid[x][y] != nullptr) {
                if (!grid[x][y]->linked && grid[x][y]->type != HALLWAY) {
                    grid[row][column]->linked = true;
                    grid[x][y]->linked = true;
                    if (x > row) {
                        if (y > column) {
                            //TODO: bottom right link
                        } else if (y < column) {
                            //TODO: bottom left link
                        } else {
                            grid[row][column]->doors.sud = true;
                            grid[x][y]->doors.nord = true;
                        }
                    } else if (x < row) {
                        if (y > column) {
                            //TODO: top right link
                        } else if (y < column) {
                            //TODO: top left link
                        } else {
                            grid[row][column]->doors.nord = true;
                            grid[x][y]->doors.sud = true;
                        }
                    } else {
                        if (y > column) {
                            grid[row][column]->doors.east = true;
                            grid[x][y]->doors.west = true;
                        } else {
                            grid[row][column]->doors.west = true;
                            grid[x][y]->doors.east = true;
                        }
                    }
                }
            }
        }
    }
}

