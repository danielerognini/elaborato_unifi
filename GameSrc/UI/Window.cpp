#include "Window.h"

Window::Window(const std::string& texturePath, bool active) : Entity(texturePath, false, active) {

}

void Window::resolveCollision(const Entity &externalEntity, const Vector2D &collisionVector) {

}
