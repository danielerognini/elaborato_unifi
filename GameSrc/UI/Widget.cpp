#include "Widget.h"
#include "../Cursor.h"

void checkCursorHover();

Widget::Widget(const std::string& texturePath, bool active) : Entity(texturePath, false, active) {

}

void Widget::resolveCollision(const Entity &externalEntity, const Vector2D &collisionVector) {

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
    //this function is used to make hovered things do something
}

void Widget::update() {
    Entity::update();
    onHover(checkCursorHover());
}
