#ifndef GAME_WIDGET_H
#define GAME_WIDGET_H

#include <ECS/Entity.h>

class Widget : public Entity {
public:
    Widget(const std::string& texturePath, bool active = false);

    void resolveCollision(const Entity& externalEntity, const Vector2D& collisionVector) override;

    void update() override;
private:
    bool checkCursorHover();
    void onHover(bool hovered);
};


#endif //GAME_WIDGET_H
