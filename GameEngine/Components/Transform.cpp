#include "Transform.h"
#include "../Engine.h"

int Transform::getSpeed() const {
    return speed;
}

void Transform::setSpeed(int speed) {
    this->speed = speed;
}

void Transform::update() {
    if(active && moving) {
        this->position.add(speed * Engine::getScale() * cos(direction), speed * Engine::getScale() * sin(direction));
    }
}

double Transform::getDirection() const {
    return direction;
}

void Transform::setDirection(double direction) {
    this->direction = direction;
}

bool Transform::isActive() const{
    return active;
}

void Transform::setActive(bool status) {
    active = status;
}

void Transform::toggle() {
    active = !active;
}

bool Transform::isMoving() const {
    return moving;
}

void Transform::setMoving(bool moving) {
    this->moving = moving;
}

Transform::Transform(int x, int y, double direction, int speed, bool active) : direction(direction), speed(speed), active(active) {
    moving = 0;
    position = Vector2D(x, y);
}
