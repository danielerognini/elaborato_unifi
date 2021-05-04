#include "Entity.h"
#include "../Engine.h"
#include "../Texture.h"
#include <cmath>

void Entity::update() {
    transform.update();
    sprite.update();
}

void Entity::draw() {
    SDL_Rect destRect = sprite.getSrcRect();
    destRect.w *= Engine::getScale();
    destRect.h *= Engine::getScale();

    destRect.x = static_cast<int>(transform.getPosition().getX()) - Engine::getCamera().x;
    destRect.y = static_cast<int>(transform.getPosition().getY()) - Engine::getCamera().y;

    Texture::draw(sprite.getTextureName(), sprite.getSrcRect(), destRect, sprite.getFlip());
}

const Sprite& Entity::getSprite() const {
    return sprite;
}

void Entity::setSprite(const Sprite &sprite) {
    Entity::sprite = sprite;
}

const Transform& Entity::getTransform() const {
    return transform;
}

void Entity::setTransform(const Transform &transform) {
    Entity::transform = transform;
}

const Light& Entity::getLight() const {
    return light;
}

void Entity::setLight(const Light &light) {
    Entity::light = light;
}

const Collider *Entity::getCollider(std::string name) const {
    return &colliders.find(name)->second;
}

bool Entity::addCollider(const std::string name, std::vector<Vector2D> &vertices) {
    return colliders.emplace(name, Collider(vertices)).second;
}

bool Entity::removeCollider(const std::string name) {
    return colliders.erase(name);
}

void Entity::resolveCollision(Entity &externalEntity, Vector2D &ownVertex, Vector2D &externalVertex) {
    int speedCoefficient = transform.isMoving() ? externalEntity.transform.isMoving() ? round(static_cast<float>(transform.getSpeed()) / (transform.getSpeed() + externalEntity.transform.getSpeed())) : 1 : 0;
    int x = ownVertex.getX() - (externalVertex.getX() + externalEntity.transform.getPosition().getX() - transform.getPosition().getX());
    int y = ownVertex.getY() - (externalVertex.getY() + externalEntity.transform.getPosition().getY() - transform.getPosition().getY());
    transform.getPosition().subtract(x * speedCoefficient, y * speedCoefficient);
}

bool Entity::isSolid() const {
    return solid;
}

void Entity::setSolid(bool solid) {
    this->solid = solid;
}
