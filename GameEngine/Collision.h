#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H

#include <unordered_map>
#include <list>
#include "ECS/Manager.h"

void collisionUpdate(std::unordered_map<std::string, Manager>& managers);
void resolveEntityCollisions(Entity& entity1, Entity& entity2);
std::pair<Vector2D, Vector2D> controlEntityCollisions(Entity& reference, Entity& external); //the reference entity is the one we are checking, the external one is the one we want to figure out if is colliding with our reference
std::pair<Vector2D, Vector2D> controlColliderCollisions(Collider& reference, Collider& external);
Vector2D calculateResultingVector2D(std::list<Vector2D>& vectors);
void resolveLocalCollisions(std::unordered_map<std::string, Manager>::iterator& iter);

#endif //GAME_COLLISION_H
