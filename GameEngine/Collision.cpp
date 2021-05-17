#include "Collision.h"

void update(std::unordered_map<std::string, Manager> &managers) {
    for(std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); iter != managers.end(); iter++) {
        if (iter->second.isLocalCollisionsActive()) {
            for(std::unordered_map<std::string, std::unique_ptr<Entity>>::iterator subIter = iter->second.getEntitiesBegin(); subIter != iter->second.getEntitiesEnd(); subIter++) {
                for(std::unordered_map<std::string, std::unique_ptr<Entity>>::iterator subSubIter = std::next(subIter, 1); subSubIter != iter->second.getEntitiesEnd(); subSubIter++) {
                    resolveEntityCollisions(*subIter->second, *subSubIter->second);
                }
            }
        }
    }
}

void resolveEntityCollisions(Entity &entity1, Entity &entity2) {
    Vector2D vector1 = controlEntityCollisions(entity1, entity2);
    Vector2D vector2 = controlEntityCollisions(entity2, entity1);

    entity1.resolveCollision(entity2, vector1, vector2);
    entity2.resolveCollision(entity1, vector2, vector1);
}

Vector2D controlEntityCollisions(Entity &reference, Entity &external) {
    return Vector2D();
}

void controlColliderCollisions(Collider &reference, Collider &external) {

}
