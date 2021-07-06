#include "Entity.h"
#include "../Engine.h"
#include <cmath>
#include <iostream>

Entity::Entity(const std::string& texturePath, const bool& solid, const bool& active) : sprite(Sprite(texturePath)), transform(Transform()), solid(solid) {
    this->active = active;
}

void Entity::update() {
    transform.update();
    sprite.update();
}

void Entity::draw() {
    SDL_Rect destRect = sprite.getSrcRect();
    destRect.w *= Engine::getInstance().getScale();
    destRect.h *= Engine::getInstance().getScale();
    
    destRect.x = static_cast<int>(transform.getPosition().getX()) - Engine::getInstance().getCamera().x;
    destRect.y = static_cast<int>(transform.getPosition().getY()) - Engine::getInstance().getCamera().y;
    
    Engine::getInstance().drawTexture(sprite.getTexturePath(), sprite.getSrcRect(), destRect, sprite.getFlip());
    
    destRect = text.getRect();
    
    destRect.w *= Engine::getInstance().getScale();
    destRect.h *= Engine::getInstance().getScale();
    
    destRect.x = static_cast<int>(transform.getPosition().getX()) - Engine::getInstance().getCamera().x;
    destRect.y = static_cast<int>(transform.getPosition().getY()) - Engine::getInstance().getCamera().y;
    
    Engine::getInstance().drawText(text.getFontPath(), text.getSize(), text.getMessage(), text.getColor(), text.getRect(), destRect);
}

const Sprite& Entity::getSprite() const {
    return sprite;
}

const Transform& Entity::getTransform() const {
    return transform;
}

const Collider& Entity::getCollider(const std::string& name) {
    std::unordered_map<std::string, Collider>::iterator result = colliders.find(name);
    if (result == colliders.end()) {
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

void Entity::resolveCollision(const Entity& externalEntity, const Vector2D& ownVertex) {
    if (externalEntity.isSolid()) {
        int speedCoefficient = transform.isMoving() ? externalEntity.transform.isMoving() ? round(static_cast<float>(transform.getSpeed()) / (transform.getSpeed() + externalEntity.transform.getSpeed())) : 1 : 0;
        int y = ownVertex.getY() - (externalVertex.getY() + externalEntity.transform.getPosition().getY() - transform.getPosition().getY());
        int x = ownVertex.getX() - (externalVertex.getX() + externalEntity.transform.getPosition().getX() - transform.getPosition().getX());
        transform.setPosition(transform.getPosition().getX() - x * speedCoefficient, transform.getPosition().getY() - y * speedCoefficient);
    }
}

const bool& Entity::isSolid() const {
    return solid;
}

void Entity::setSolid(const bool& solid) {
    this->solid = solid;
}

bool Entity::isCollidersActive() {
    std::unordered_map<std::string, Collider>::iterator iter;
    for (iter = colliders.begin(); !iter->second.isActive() && iter != colliders.end(); iter++) {}
    return iter != colliders.end();
}

std::unordered_map<std::string, Collider>::iterator Entity::getCollidersBegin() {
    return colliders.begin();
}

std::unordered_map<std::string, Collider>::iterator Entity::getCollidersEnd() {
    return colliders.end();
}

Text& Entity::getText() {
    return text;
}

void Entity::setText(const Text& text) {
    Entity::text = text;
}
