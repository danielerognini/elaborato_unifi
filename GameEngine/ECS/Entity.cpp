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
    
    destRect.x = transform.getPosition().getX();
    destRect.y = transform.getPosition().getY();
    
    Engine::getInstance().drawTexture(sprite.getTexturePath(), sprite.getSrcRect(), destRect, sprite.getFlip());
    
    destRect = text.getRect();
    destRect.x = text.getOffset().getX() + transform.getPosition().getX();
    destRect.y = text.getOffset().getY() + transform.getPosition().getY();
    
    Engine::getInstance().drawText(text.getFontPath(), text.getSize(), text.getMessage(), text.getColor(), text.getRect(), destRect);
}

Sprite& Entity::getSprite() {
    return sprite;
}

Transform& Entity::getTransform() {
    return transform;
}

Collider& Entity::getCollider(const std::string& name) {
    std::unordered_map<std::string, Collider>::iterator result = colliders.find(name);
    if (result == colliders.end()) {
        throw std::runtime_error("\"" + name + "\" key does not exists in this unordered_map");
    }
    return result->second;
}

bool Entity::addCollider(const std::string& name, std::unique_ptr<std::vector<Border>> borders, const bool& active) {
    return colliders.emplace(name, Collider(std::move(borders), active)).second;
}

bool Entity::removeCollider(const std::string& name) {
    return colliders.erase(name);
}

void Entity::resolveCollision(const Entity& externalEntity, const Vector2D& collisionVector) {
    if (transform.getPosition().getX() == 7 && transform.getPosition().getY() == 10 && externalEntity.transform.getPosition().getX() == 9 && externalEntity.transform.getPosition().getY() == 9) {
        std::cout << "[" << collisionVector.getX() << ", " << collisionVector.getY() << "]" << std::endl;
    }
    if (externalEntity.isSolid()) {
        double speedCoefficient = transform.isMoving() ? externalEntity.transform.isMoving() ? static_cast<double>(transform.getSpeed()) / (transform.getSpeed() + externalEntity.transform.getSpeed()) : 1 : 0;
        transform.setPosition(transform.getPosition().getX() - (static_cast<int>(round(static_cast<float>(collisionVector.getX() * speedCoefficient))) - (collisionVector.getX() % 2 == 1 && collisionVector.getX() > 0 && transform.getSpeed() == externalEntity.transform.getSpeed() ? 1 : 0)), transform.getPosition().getY() - (static_cast<int>(round(static_cast<float>(collisionVector.getY() * speedCoefficient))) - (collisionVector.getY() % 2 == 1 && collisionVector.getY() > 0 && transform.getSpeed() == externalEntity.transform.getSpeed() ? 1 : 0)));
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
