#ifndef GAME_BARRIER_H
#define GAME_BARRIER_H

#include "CollisionArea.h"

class Barrier : public CollisionArea{
public:
    explicit Barrier(bool solid = true);
private:
};


#endif //GAME_BARRIER_H
