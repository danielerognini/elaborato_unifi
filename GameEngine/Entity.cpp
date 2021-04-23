#include "Entity.h"
#include "Engine.h"
#include "Texture.h"

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

const Collider& Entity::getCollider() const {
    return collider;
}

void Entity::setCollider(const Collider &collider) {
    Entity::collider = collider;
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

bool Entity::isActive() {
    return active;
}

