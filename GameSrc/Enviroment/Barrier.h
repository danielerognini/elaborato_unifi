#ifndef GAME_BARRIER_H
#define GAME_BARRIER_H

#include "CollisionArea.h"

class Barrier : public CollisionArea{
public:
    Barrier(bool solid = true, bool active = true);
private:
};


#endif //GAME_BARRIER_H
