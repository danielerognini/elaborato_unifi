#include "Widget.h"
#include "../Cursor.h"

Widget::Widget(const std::function<void()>& onClick, const std::string& texturePath) : Entity(texturePath, false), hovered(false) {
}

bool Widget::checkCursorHover() {
    bool inside = false;
    for(auto iter = this->begin(); !inside && iter != this->end(); iter++) {
        inside = true;
        for(auto& border : iter->second) {
            inside = inside && border.checkSide(Cursor::getInstance().getTransform().getPosition());
        }
    }
    if(inside) {
        Cursor::getInstance().setCurrentHoveredWidget(this);
    }
    return inside;
}

void Widget::onHover(bool hovered) {
    static std::string currentAnimation = getSprite().getCurrentAnimation();
    if (hovered != this->hovered && hovered) {
        this->hovered = hovered;
        getSprite().setCurrentAnimation("hover"); //maybe its temporary
    } else if (hovered != this->hovered && this->hovered) {
        this->hovered = hovered;
        getSprite().setCurrentAnimation(currentAnimation);
    }
}

void Widget::update() {
    Entity::update();
    onHover(checkCursorHover());
}

void Widget::resolveCollision(Entity* externalEntity, const Vector2D& collisionVector) {
}

void Widget::onClick() {
    click();
}
