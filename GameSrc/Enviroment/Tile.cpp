#include "Tile.h"

Collider &Tile::getCollider(const std::string &name) {
    return Entity::getCollider(name);
}

bool Tile::addCollider(const std::string &name, std::vector<Border> borders, const bool &active) {
    return Entity::addCollider(name, borders, active);
}

bool Tile::removeCollider(const std::string &name) {
    return Entity::removeCollider(name);
}

Tile::Tile(const std::string &texturePath, bool active) : Entity(texturePath, false, active) {

}

Text &Tile::getText() {
    return Entity::getText();
}

void Tile::setText(const Text &text) {
    Entity::setText(text);
}

void Tile::resolveCollision(const Entity &externalEntity, const Vector2D &collisionVector) {
    Entity::resolveCollision(externalEntity, collisionVector);
}

bool Tile::isSolid() const {
    return Entity::isSolid();
}

void Tile::setSolid(bool solid) {
    Entity::setSolid(solid);
}

std::unordered_map<std::string, Collider>::iterator Tile::begin() {
    return Entity::begin();
}

std::unordered_map<std::string, Collider>::iterator Tile::end() {
    return Entity::end();
}
