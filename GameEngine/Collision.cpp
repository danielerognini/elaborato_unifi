#include <future>
#include "Collision.h"
#include "Utility.h"

void collisionUpdate(std::unordered_map<std::string, Manager> &managers) {
    std::list<std::future<void>> asyncCalls;
    for(std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); iter != managers.end(); iter++) {
        asyncCalls.push_back(std::async(std::launch::async, ::resolveLocalCollisions, iter));
    }
    for(std::list<std::future<void>>::iterator iter = asyncCalls.begin(); iter != asyncCalls.end(); iter++) {
        iter->get();
    }
    for(std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); iter != std::prev(managers.end()); iter++) {
        if(iter->second.isGlobalCollisionsActive()) {
            for(std::unordered_map<std::string, Manager>::iterator subIter = std::next(iter, 1); subIter != managers.end(); subIter++) {
                if(subIter->second.isGlobalCollisionsActive()) {
                    for(std::unordered_map<std::string, std::unique_ptr<Entity>>::iterator subSubIter = iter->second.getEntitiesBegin(); subSubIter != iter->second.getEntitiesEnd(); subSubIter++) {
                        if(subSubIter->second->isCollidersActive()) {
                            for (std::unordered_map<std::string, std::unique_ptr<Entity>>::iterator subSubSubIter = subIter->second.getEntitiesBegin(); subSubSubIter != subIter->second.getEntitiesEnd(); subSubSubIter++) {
                                if(subSubIter->second->isCollidersActive()) {
                                    resolveEntityCollisions(*subSubIter->second, *subSubSubIter->second);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void resolveLocalCollisions(std::unordered_map<std::string, Manager>::iterator iter) {
    if (iter->second.isLocalCollisionsActive()) {
        for(std::unordered_map<std::string, std::unique_ptr<Entity>>::iterator subIter = iter->second.getEntitiesBegin(); subIter != std::prev(iter->second.getEntitiesEnd()); subIter++) {
            if(subIter->second->isCollidersActive()) {
                for (std::unordered_map<std::string, std::unique_ptr<Entity>>::iterator subSubIter = std::next(subIter, 1); subSubIter != iter->second.getEntitiesEnd(); subSubIter++) {
                    if(subSubIter->second->isCollidersActive()) {
                        resolveEntityCollisions(*subIter->second, *subSubIter->second);
                    }
                }
            }
        }
    }
}

void resolveEntityCollisions(Entity &entity1, Entity &entity2) {
    std::pair<Vector2D, Vector2D> vectors = controlEntityCollisions(entity1, entity2);
    entity1.resolveCollision(entity2, vectors.first, vectors.second);
    entity2.resolveCollision(entity1, vectors.second, vectors.first);
}

std::pair<Vector2D, Vector2D> controlEntityCollisions(Entity &reference, Entity &external) {
    std::list<Vector2D> referenceVectors;
    std::list<Vector2D> externalVectors;
    for(std::unordered_map<std::string, Collider>::iterator iter = reference.getCollidersBegin(); iter != reference.getCollidersEnd(); iter++) {
        if(iter->second.isActive()) {
            for (std::unordered_map<std::string, Collider>::iterator subIter = external.getCollidersBegin(); subIter != external.getCollidersEnd(); subIter++) {
                if (subIter->second.isActive()) {
                    std::pair<Vector2D, Vector2D> relativeVectors = controlColliderCollisions(iter->second,subIter->second);
                    referenceVectors.push_back(relativeVectors.first);
                    externalVectors.push_back(relativeVectors.second);
                }
            }
        }
    }
    return std::make_pair(calculateResultingVector2D(referenceVectors), calculateResultingVector2D(externalVectors));
}

std::pair<Vector2D, Vector2D> controlColliderCollisions(Collider &reference, Vector2D referencePosition, Collider &external, Vector2D externalPosition) {
    std::list<Vector2D> referenceVectors;
    Vector2D distance = referencePosition - externalPosition;
    std::list<Vector2D> externalVectors;

    for(std::vector<Vector2D>::iterator iter = reference.getVerticesBegin(); iter != reference.getVerticesEnd(); iter++) {
        for(std::vector<Vector2D>::iterator subIter = external.getVerticesBegin(); subIter != external.getVerticesEnd(); subIter++) {
            //checking collisions using the getCenter method from collider and calculating the distance from the center to one of the vertices, then check for intersections with the sides of the external collider
            Vector2D referenceIntersection = ::checkLinesIntersection(std::make_pair(reference.getCenter(), *iter), std::make_pair(*subIter, std::next(subIter, 1) == external.getVerticesEnd() ? *external.getVerticesBegin() : *std::next(subIter, 1)));
            if(referenceIntersection.getX() != 0 || referenceIntersection.getY() != 0) {
                referenceVectors.push_back(*iter);
            }
            Vector2D externalIntersection = ::checkLinesIntersection(std::make_pair(external.getCenter(), *subIter), std::make_pair(*iter, std::next(iter, 1) == reference.getVerticesEnd() ? *reference.getVerticesBegin() : *std::next(iter, 1)));
            if(externalIntersection.getX() != 0 || externalIntersection.getY() != 0) {
                externalVectors.push_back(*subIter);
            }
        }
    }
    return std::make_pair(calculateResultingVector2D(referenceVectors), calculateResultingVector2D(externalVectors));
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