#ifndef GAME_COLLISIONAREA_H
#define GAME_COLLISIONAREA_H

#include <ECS/Entity.h>

class CollisionArea : public Entity{
public:
    CollisionArea(bool solid = true, bool active = true);
private:
    Sprite& getSprite() override;
    Text& getText() override;
    void setText(const Text& text) override;
};


#endif //GAME_COLLISIONAREA_H
