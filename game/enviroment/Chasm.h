#ifndef GAME_CHASM_H
#define GAME_CHASM_H

#include "CollisionArea.h"

class Chasm : public CollisionArea{
public:
    explicit Chasm(bool solid = true);
    void resolveCollision(Entity* externalEntity, const Vector2D& collisionVector) override;
private:
};


#endif //GAME_CHASM_H
