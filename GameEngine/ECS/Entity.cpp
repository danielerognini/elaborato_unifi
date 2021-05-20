#include "Entity.h"
#include "../Engine.h"
#include <cmath>

Entity::Entity(const std::string& texturePath, const bool& solid, const bool& active) : sprite(Sprite(texturePath)), transform(Transform()), solid(solid) {
    this->active = active;
}

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

    Engine::drawTexture(sprite.getTexturePath(), sprite.getSrcRect(), destRect, sprite.getFlip());
}

const Sprite& Entity::getSprite() const {
    return sprite;
}

const Transform& Entity::getTransform() const {
    return transform;
}

const Collider &Entity::getCollider(const std::string& name) {
    std::unordered_map<std::string, Collider>::iterator result = colliders.find(name);
    if(result == colliders.end()) {
        throw std::runtime_error("\"" + name + "\" key does not exists in this unordered_map");
    }
    return result->second;
}

bool Entity::addCollider(const std::string& name, std::unique_ptr<std::vector<Vector2D>> vertices) {
    return colliders.emplace(name, Collider(std::move(vertices))).second;
}

bool Entity::removeCollider(const std::string& name) {
    return colliders.erase(name);
}

void Entity::resolveCollision(const Entity &externalEntity, const Vector2D &ownVertex, const Vector2D &externalVertex) {
    int speedCoefficient = transform.isMoving() ? externalEntity.transform.isMoving() ? round(static_cast<float>(transform.getSpeed()) / (transform.getSpeed() + externalEntity.transform.getSpeed())) : 1 : 0;
    int x = ownVertex.getX() - (externalVertex.getX() + externalEntity.transform.getPosition().getX() - transform.getPosition().getX());
    int y = ownVertex.getY() - (externalVertex.getY() + externalEntity.transform.getPosition().getY() - transform.getPosition().getY());
    transform.setPosition(transform.getPosition().getX() - x * speedCoefficient, transform.getPosition().getY() - y * speedCoefficient);
}

const bool& Entity::isSolid() const {
    return solid;
}

void Entity::setSolid(const bool& solid) {
    this->solid = solid;
}

bool Entity::isCollidersActive() {
    bool result = false;
    for(std::unordered_map<std::string, Collider>::iterator iter = colliders.begin(); iter != colliders.end(); iter++) {
        if(iter->second.isActive()) {
            result = true;
            break;
        }
    }
    return result;
}

std::unordered_map<std::string, Collider>::iterator Entity::getCollidersBegin() {
    return colliders.begin();
}

std::unordered_map<std::string, Collider>::iterator Entity::getCollidersEnd() {
    return colliders.end();
}
