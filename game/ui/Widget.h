#ifndef GAME_WIDGET_H
#define GAME_WIDGET_H

#include <ecs/Entity.h>
#include <functional>

class Widget : public Entity {
public:
    explicit Widget(const std::function<void()>& onClick, const std::string& texturePath);
    void update() override;
    void onClick();

private:
    bool hovered;
    std::function<void()> click;
    void resolveCollision(Entity* externalEntity, const Vector2D& collisionVector) final;
    bool checkCursorHover();
    void onHover(bool hovered);
};


#endif //GAME_WIDGET_H
