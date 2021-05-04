#include "Collision.h"
#include "Engine.h"

void Collision::update(std::unordered_map<std::string, Manager> &managers) {
    for(std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); iter != managers.end(); iter++) {
        for(std::unordered_map<std::string, Entity*>::iterator subIter = iter->second.getEntitiesBegin(); subIter != iter->second.getEntitiesEnd(); subIter++) {
            for(std::unordered_map<std::string, Entity*>::iterator subSubIter = std::next(subIter, 1); subSubIter != iter->second.getEntitiesEnd(); subSubIter++) {
                resolveEntityCollisions(subIter->second, subSubIter);
            }
        }
    }
}

void Collision::resolveEntityCollisions(Entity &entity1, Entity &entity2) {
    Vector2D vector1 = controlEntityCollisions(entity1, entity2);
    Vector2D vector2 = controlEntityCollisions(entity2, entity1);

    entity1.resolveCollision(entity2, vector1, vector2);
    entity2.resolveCollision(entity1, vector2, vector1);
}

Vector2D Collision::controlEntityCollisions(Entity &reference, Entity &external) {
    for()
        for()
            resolve referce
            resolve external
    return Vector2D;
}

void Collision::controlColliderCollision(Collider &reference, Collider &external) {

}
