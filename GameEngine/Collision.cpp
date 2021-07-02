#include <future>
#include <iostream>
#include <map>
#include "Collision.h"
#include "Utility.h"

void collisionUpdate(std::unordered_map<std::string, Manager> &managers) {
    std::list<std::future<void>> asyncCalls;
    
    /*
    for(std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); iter != managers.end(); iter++) {
        asyncCalls.push_back(std::async(std::launch::async, ::resolveLocalCollisions, iter));
    }
    for(std::list<std::future<void>>::iterator iter = asyncCalls.begin(); iter != asyncCalls.end(); iter++) {
        iter->get();
    }
    */
    for(std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); iter != managers.end(); iter++) {
        auto debug = iter->second.getEntitiesBegin();
        resolveLocalCollisions(iter);
    }
    /*
     * we replaced use async calls because of an error that occurred using gtest to test Collision.h
     * the error we got was Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)
     * TODO: fix async calls errors
     */

    for(std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); std::next(iter, 1) != managers.end(); iter++) {
        if(iter->second.isGlobalCollisionsActive()) {
            for(std::unordered_map<std::string, Manager>::iterator subIter = std::next(iter, 1); subIter != managers.end(); subIter++) {
                if(subIter->second.isGlobalCollisionsActive()) {
                    for(std::unordered_map<std::string, std::shared_ptr<Entity>>::iterator subSubIter = iter->second.getEntitiesBegin(); subSubIter != iter->second.getEntitiesEnd(); subSubIter++) {
                        if(subSubIter->second->isCollidersActive()) {
                            for (std::unordered_map<std::string, std::shared_ptr<Entity>>::iterator subSubSubIter = subIter->second.getEntitiesBegin(); subSubSubIter != subIter->second.getEntitiesEnd(); subSubSubIter++) {
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

void resolveLocalCollisions(std::unordered_map<std::string, Manager>::iterator& iter) {
    if (iter->second.isLocalCollisionsActive()) {

        for(std::unordered_map<std::string, std::shared_ptr<Entity>>::iterator subIter = iter->second.getEntitiesBegin(); std::next(subIter, 1) != iter->second.getEntitiesEnd(); subIter++) {
            if(subIter->second->isCollidersActive()) {
                for (std::unordered_map<std::string, std::shared_ptr<Entity>>::iterator subSubIter = std::next(subIter, 1); subSubIter != iter->second.getEntitiesEnd(); subSubIter++) {
                    if(subSubIter->second->isCollidersActive()) {
                        resolveEntityCollisions(*subIter->second, *subSubIter->second);
                    }
                }
            }
        }
    }
}

void resolveEntityCollisions(Entity &entity1, Entity &entity2) {
    Vector2D vector = controlEntityCollisions(entity1, entity2);
    entity1.resolveCollision(entity2, vector);
    entity2.resolveCollision(entity1, vector * (-1));
}

Vector2D controlEntityCollisions(Entity &reference, Entity &external) {
    std::list<Vector2D> referenceVectors;
    for(std::unordered_map<std::string, Collider>::iterator iter = reference.getCollidersBegin(); iter != reference.getCollidersEnd(); iter++) {
        if(iter->second.isActive()) {
            for (std::unordered_map<std::string, Collider>::iterator subIter = external.getCollidersBegin(); subIter != external.getCollidersEnd(); subIter++) {
                if (subIter->second.isActive()) {
                    referenceVectors.push_back(controlColliderCollisions(iter->second, reference.getTransform().getPosition(), subIter->second, external.getTransform().getPosition()));
                }
            }
        }
    }
    return calculateResultingVector2D(referenceVectors);
}

Vector2D controlColliderCollisions(Collider& reference, const Vector2D& referencePosition, Collider& external, const Vector2D& externalPosition) {
    
    /*
     * borders positions are relative to the entities transforms
     */
    std::map<int, std::pair<std::pair<Border, std::list<Vector2D>>, bool>> referenceIntersectedBorders;
    std::map<int, std::pair<std::pair<Border, std::list<Vector2D>>, bool>> externalIntersectedBorders;
    int referenceBorderIndex;
    int externalBorderIndex;
    std::list<Vector2D> referenceIncludedVertices;
    std::list<Vector2D> externalIncludedVertices;
    std::list<Vector2D> collisionVectors;
    
    for (std::vector<Border>::iterator iter = reference.getBordersBegin(); iter != reference.getBordersEnd(); iter++) {
        referenceBorderIndex = iter - reference.getBordersBegin();
        for (std::vector<Border>::iterator subIter = external.getBordersBegin(); subIter != external.getBordersEnd(); subIter++) {
            externalBorderIndex = subIter - external.getBordersEnd();
            std::pair<std::pair<bool, Vector2D>, std::pair<bool, bool>> intersection = iter->checkBordersIntersection(
                    *subIter, referencePosition, externalPosition);
            if (intersection.first.first) {
                if (referenceIntersectedBorders.find(referenceBorderIndex) == referenceIntersectedBorders.end()) {
                    referenceIntersectedBorders.emplace(referenceBorderIndex,
                                                        std::make_pair(std::make_pair(*iter, std::list<Vector2D>()),
                                                                       true));
                }
                std::pair<std::pair<Border, std::list<Vector2D>>, bool>& currentReferenceBorder = referenceIntersectedBorders.find(
                        referenceBorderIndex)->second;
                currentReferenceBorder.first.second.emplace_back(intersection.first.second);
                currentReferenceBorder.second = currentReferenceBorder.second && intersection.second.first;
                
                if (externalIntersectedBorders.find(externalBorderIndex) == externalIntersectedBorders.end()) {
                    externalIntersectedBorders.emplace(externalBorderIndex,
                                                       std::make_pair(std::make_pair(*subIter, std::list<Vector2D>()),
                                                                      true));
                }
                std::pair<std::pair<Border, std::list<Vector2D>>, bool>& currentExternalBorder = externalIntersectedBorders.find(
                        externalBorderIndex)->second;
                currentExternalBorder.first.second.emplace_back(intersection.first.second);
                currentExternalBorder.second = currentExternalBorder.second && intersection.second.second;
            }
        }
    }
    
    for (std::map<int, std::pair<std::pair<Border, std::list<Vector2D>>, bool>>::iterator iter = referenceIntersectedBorders.begin(); iter != referenceIntersectedBorders.end(); iter++) {
        if (iter->second.second) {
            referenceIncludedVertices.emplace_back(iter->second.first.first.getNextVertex());
            for (std::vector<Border>::iterator subIter = std::next(reference.getBordersBegin(),
                                                                   iter->first + 1); subIter - reference.getBordersBegin() != std::next(
                    iter, 1)->first; subIter++) {
                referenceIncludedVertices.emplace_back(subIter->getNextVertex());
            }
        }
    }
    
    for (std::map<int, std::pair<std::pair<Border, std::list<Vector2D>>, bool>>::iterator iter = externalIntersectedBorders.begin(); iter != externalIntersectedBorders.end(); iter++) {
        if (iter->second.second) {
            externalIncludedVertices.emplace_back(iter->second.first.first.getNextVertex());
            for (std::vector<Border>::iterator subIter = std::next(external.getBordersBegin(),
                                                                   iter->first + 1); subIter - external.getBordersBegin() != std::next(
                    iter, 1)->first; subIter++) {
                externalIncludedVertices.emplace_back(subIter->getNextVertex());
            }
        }
    }
    
    //TODO: calculate collisionVectors given the included Vertices of both colliders
    
    return calculateResultingVector2D(collisionVectors);
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