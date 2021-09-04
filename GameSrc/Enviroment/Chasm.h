#ifndef GAME_CHASM_H
#define GAME_CHASM_H

#include "CollisionArea.h"

class Chasm : public CollisionArea{
public:
    explicit Chasm(bool solid = true, bool active = true);
    void resolveCollision(const Entity& externalEntity, const Vector2D& collisionVector) override;
private:
};


#endif //GAME_CHASM_H
