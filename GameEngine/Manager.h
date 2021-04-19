#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Entity.h"
#include <map>

class Manager {
private:

public:
    void flush();
    void update();
    void renderEntities();
};


#endif //GAME_MANAGER_H
