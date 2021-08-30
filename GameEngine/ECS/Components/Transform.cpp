#include "Transform.h"
#include "../../Engine.h"

unsigned short int Transform::getSpeed() const {
    return speed;
}

void Transform::setSpeed(unsigned short int speed) {
    this->speed = speed;
}

void Transform::update() {
    if (active && moving) {
        //unsigned int currentSpeed = speed * ((1 - sqrt(2)) * cos(4 * direction) + 1 + sqrt(2)) / 2;
        unsigned int currentSpeed = direction % 2 == 0 ? speed : static_cast<unsigned int>(speed * sqrt(2));
        if (currentSpeed % (Engine::getInstance().getFrameStart() - lastMovement) == currentSpeed) {
            lastMovement = Engine::getInstance().getFrameStart();
            position.add(Engine::getInstance().getScale(), Engine::getInstance().getScale());
        }
    }
}

Direction Transform::getDirection() const {
    return direction;
}

void Transform::setDirection(Direction direction) {
    this->direction = direction;
}

bool Transform::isMoving() const {
    return moving;
}

void Transform::setMoving(bool moving) {
    this->moving = moving;
}

Transform::Transform(int x, int y, Direction direction, int speed, bool moving, bool active) : position(Vector2D(x, y)), direction(direction), speed(speed), moving(moving) {
    this->active = active;
    lastMovement = 0;
}

const Vector2D& Transform::getPosition() const {
    return position;
}

void Transform::setPosition(int x, int y) {
    position.setX(x);
    position.setY(y);
}