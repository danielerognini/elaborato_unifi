#include "Transform.h"
#include "../../Engine.h"

const unsigned short int& Transform::getSpeed() const {
    return speed;
}

void Transform::setSpeed(const unsigned short int& speed) {
    this->speed = speed;
}

void Transform::update() {
    if (active && moving) {
        Uint32 currentSpeed = speed * ((1 - sqrt(2)) * cos(4 * direction) + 1 + sqrt(2)) / 2;
        if (currentSpeed % (Engine::getInstance().getFrameStart() - lastMovement) == currentSpeed) {
            lastMovement = Engine::getInstance().getFrameStart();
            position.add(Engine::getInstance().getScale() * cos(direction), Engine::getInstance().getScale() * sin(direction));
        }
    }
}

const double& Transform::getDirection() const {
    return direction;
}

void Transform::setDirection(const double& direction) {
    this->direction = direction;
}

const bool& Transform::isMoving() const {
    return moving;
}

void Transform::setMoving(const bool& moving) {
    this->moving = moving;
}

Transform::Transform(const int& x, const int& y, const double& direction, const int& speed, const bool& moving, const bool& active) : direction(direction), speed(speed), moving(moving) {
    this->active = active;
    position = Vector2D(x, y);
    lastMovement = 0;
}

const Vector2D& Transform::getPosition() const {
    return position;
}

void Transform::setPosition(const int& x, const int& y) {
    position.setX(x);
    position.setY(y);
}