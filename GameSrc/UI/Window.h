#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <ECS/Entity.h>

class Window : public Entity {
public:
    Window(const std::string& texturePath, bool active = false);

    void resolveCollision(const Entity& externalEntity, const Vector2D& collisionVector) override;
private:

};


#endif //GAME_WINDOW_H
