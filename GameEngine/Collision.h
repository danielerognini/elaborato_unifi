#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H

#include <unordered_map>
#include "ECS/Manager.h"

void update(std::unordered_map<std::string, Manager>& managers);
void resolveEntityCollisions(Entity& entity1, Entity& entity2);
Vector2D controlEntityCollisions(Entity& reference, Entity& external); //the reference entity is the one we are checking, the external one is the one we want to figure out if is colliding with our reference
void controlColliderCollisions(Collider& reference, Collider& external);

#endif //GAME_COLLISION_H
