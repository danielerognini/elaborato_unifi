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
    std::list<Vector2D> vectors;
    for(std::unordered_map<std::string, Collider>::iterator iter = reference.getCollidersBegin(); iter != reference.getCollidersEnd(); iter++) {
        for(std::unordered_map<std::string, Collider>::iterator subIter = external.getCollidersBegin(); subIter != external.getCollidersEnd(); subIter++) {
            vectors.push_back(controlColliderCollisions(iter->second, subIter->second));
        }
    }
    return calculateResultingVector2D(vectors);
}

Vector2D controlColliderCollisions(Collider &reference, Vector2D referencePosition, Collider &external, Vector2D externalPosition) {
    std::list<Vector2D> vectors;
    Vector2D distance = referencePosition - externalPosition;

    for(std::vector<Vector2D>::iterator iter = reference.getVerticesBegin(); iter != reference.getVerticesEnd(); iter++) {
        for(std::vector<Vector2D>::iterator subIter = external.getVerticesBegin(); subIter != external.getVerticesEnd(); subIter++) {
            //TODO: checking collisions using the getCenter method from collider and calculating the distance from the center to one of the vertices, then check for intersections with the sides of the external collider
        }
    }
}

Vector2D calculateResultingVector2D(std::list<Vector2D>& vectors) {
    int maxUp = 0;
    int maxDown = 0;
    int maxLeft = 0;
    int maxRight = 0;

    for(std::list<Vector2D>::iterator iter = vectors.begin(); iter != vectors.end(); iter++) {
        if(iter->getX() > maxRight) {
            maxRight = iter->getX();
        }
        else if(iter->getX() < maxLeft) {
            maxLeft = iter->getX();
        }
        if(iter->getY() > maxDown) {
            maxDown = iter->getY();
        }
        else if(iter->getY() < maxUp) {
            maxUp = iter->getY();
        }
    }
    return Vector2D(maxRight + maxLeft, maxDown + maxUp);
}

Vector2D checkLinesIntersection(std::pair<Vector2D, Vector2D>& reference, std::pair<Vector2D, Vector2D>& external) {
    //TODO: implement the line intersection check returning the intersection vector relative to the reference line (distance between intersection point and reference vertex)
    return Vector2D();
}
