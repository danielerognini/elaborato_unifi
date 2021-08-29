#include <future>
#include <map>
#include <numeric>
#include "Collision.h"
#include "Utility.h"

void collisionUpdate(std::unordered_map<std::string, Manager>& managers) {
    std::list<std::future<void>> asyncCalls;
    
    /*
    for(std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); iter != managers.end(); iter++) {
        asyncCalls.push_back(std::async(std::launch::async, ::resolveLocalCollisions, iter));
    }
    for(std::list<std::future<void>>::iterator iter = asyncCalls.begin(); iter != asyncCalls.end(); iter++) {
        iter->get();
    }
    */
    for (std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); iter != managers.end(); iter++) {
        auto debug = iter->second.getEntitiesBegin();
        resolveLocalCollisions(iter);
    }
    /*
     * we replaced use async calls because of an error that occurred using gtest to test Collision.h
     * the error we got was Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)
     * TODO: fix async calls errors
     */
    
    for (std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); std::next(iter, 1) != managers.end(); iter++) {
        if (iter->second.isGlobalCollisionsActive()) {
            for (std::unordered_map<std::string, Manager>::iterator subIter = std::next(iter, 1); subIter != managers.end(); subIter++) {
                if (subIter->second.isGlobalCollisionsActive()) {
                    for (std::unordered_map<std::string, std::shared_ptr<Entity>>::iterator subSubIter = iter->second.getEntitiesBegin(); subSubIter != iter->second.getEntitiesEnd(); subSubIter++) {
                        if (subSubIter->second->isCollidersActive()) {
                            for (std::unordered_map<std::string, std::shared_ptr<Entity>>::iterator subSubSubIter = subIter->second.getEntitiesBegin(); subSubSubIter != subIter->second.getEntitiesEnd(); subSubSubIter++) {
                                if (subSubIter->second->isCollidersActive()) {
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
    
        for (std::unordered_map<std::string, std::shared_ptr<Entity>>::iterator subIter = iter->second.getEntitiesBegin(); std::next(subIter, 1) != iter->second.getEntitiesEnd(); subIter++) {
            if (subIter->second->isCollidersActive()) {
                for (std::unordered_map<std::string, std::shared_ptr<Entity>>::iterator subSubIter = std::next(subIter, 1); subSubIter != iter->second.getEntitiesEnd(); subSubIter++) {
                    if (subSubIter->second->isCollidersActive()) {
                        resolveEntityCollisions(*subIter->second, *subSubIter->second);
                    }
                }
            }
        }
    }
}

void resolveEntityCollisions(Entity& entity1, Entity& entity2) {
    Vector2D vector = controlEntityCollisions(entity1, entity2);
    entity1.resolveCollision(entity2, vector);
    entity2.resolveCollision(entity1, vector * (-1));
}

Vector2D controlEntityCollisions(Entity& reference, Entity& external) {
    std::list<Vector2D> referenceVectors;
    for (std::unordered_map<std::string, Collider>::iterator iter = reference.getCollidersBegin(); iter != reference.getCollidersEnd(); iter++) {
        if (iter->second.isActive()) {
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
    
    typedef struct {
        Border border;
        bool incoming; //true: the border go inside the other collider; false: the border go outside or is totally outside the other collider
    } RefBorder;
    
    typedef struct {
        Border border;
        std::list<Vector2D> intersections;
        bool incoming; //true: the border go inside the other collider; false: the border go outside or is totally outside the other collider
    } ExtBorder;
    
    //std::map<int, std::pair<Border, bool>> referenceIntersectedBorders;
    std::map<int, RefBorder> referenceIntersectedBorders;
    //std::map<int, std::pair<std::pair<Border, std::list<Vector2D>>, bool>> externalIntersectedBorders;
    std::map<int, ExtBorder> externalIntersectedBorders;
    
    int referenceBorderIndex;
    int externalBorderIndex;
    std::list<Vector2D> referenceIncludedVertices;
    std::list<Vector2D> externalIncludedVertices;
    
    for (std::vector<Border>::iterator iter = reference.getBordersBegin(); iter != reference.getBordersEnd(); iter++) {
        referenceBorderIndex = iter - reference.getBordersBegin();
        for (std::vector<Border>::iterator subIter = external.getBordersBegin(); subIter != external.getBordersEnd(); subIter++) {
            externalBorderIndex = subIter - external.getBordersBegin();
            IntersectionResult intersection = iter->checkBordersIntersection(*subIter, referencePosition, externalPosition);
            if (intersection.intersected) {
                if (referenceIntersectedBorders.find(referenceBorderIndex) == referenceIntersectedBorders.end()) {
                    referenceIntersectedBorders.emplace(referenceBorderIndex, RefBorder{*iter, true});
                }
                RefBorder& currentReferenceBorder = referenceIntersectedBorders.find(referenceBorderIndex)->second;
                currentReferenceBorder.incoming = currentReferenceBorder.incoming && intersection.refIncoming;
                
                if (externalIntersectedBorders.find(externalBorderIndex) == externalIntersectedBorders.end()) {
                    externalIntersectedBorders.emplace(externalBorderIndex, ExtBorder{*subIter, std::list<Vector2D>(), true});
                }
                ExtBorder& currentExternalBorder = externalIntersectedBorders.find(externalBorderIndex)->second;
                currentExternalBorder.intersections.emplace_back(intersection.intersection);
                currentExternalBorder.incoming = currentExternalBorder.incoming && intersection.extIncoming;
            }
        }
    }
    
    for (std::map<int, RefBorder>::iterator iter = referenceIntersectedBorders.begin(); iter != referenceIntersectedBorders.end(); iter++) {
        if (iter->second.incoming) {
            referenceIncludedVertices.emplace_back(iter->second.border.getNextVertex());
            for (std::vector<Border>::iterator subIter = std::next(reference.getBordersBegin(), iter->first + 1) != reference.getBordersEnd() ? std::next(reference.getBordersBegin(), iter->first + 1) : reference.getBordersBegin(); std::next(iter, 1) != referenceIntersectedBorders.end() ? subIter - reference.getBordersBegin() != std::next(iter, 1)->first : subIter - reference.getBordersBegin() != referenceIntersectedBorders.begin()->first; std::next(subIter, 1) != reference.getBordersEnd() ? subIter++ : subIter = reference.getBordersBegin()) {
                referenceIncludedVertices.emplace_back(subIter->getNextVertex());
            }
        }
    }
    std::list<Vector2D> intersections;
    for (std::map<int, ExtBorder>::iterator iter = externalIntersectedBorders.begin(); iter != externalIntersectedBorders.end(); iter++) {
        intersections.emplace_back(std::accumulate(iter->second.intersections.begin(), iter->second.intersections.end(), Vector2D(0, 0)) / iter->second.intersections.size());
        if (iter->second.incoming) {
            externalIncludedVertices.emplace_back(iter->second.border.getNextVertex());
            for (std::vector<Border>::iterator subIter = std::next(external.getBordersBegin(), iter->first + 1) != external.getBordersEnd() ? std::next(external.getBordersBegin(), iter->first + 1) : external.getBordersBegin(); std::next(iter, 1) != externalIntersectedBorders.end() ? subIter - external.getBordersBegin() != std::next(iter, 1)->first : subIter - external.getBordersBegin() != externalIntersectedBorders.begin()->first; std::next(subIter, 1) != external.getBordersEnd() ? subIter++ : subIter = external.getBordersBegin()) {
                externalIncludedVertices.emplace_back(subIter->getNextVertex());
            }
        }
    }
    Vector2D result = Vector2D(0, 0);
    if (referenceIncludedVertices.size() > 0 || externalIncludedVertices.size() > 0) {
        //result = calculatePolygonCollisionVector(referenceIncludedVertices, externalIncludedVertices, intersections);
        result = calculateRectCollisionVector(referenceIncludedVertices, externalIncludedVertices, intersections);
    }
    return result;
}

Vector2D& calculateRectCollisionVector(std::list<Vector2D>& referenceIncludedVertices, std::list<Vector2D>& externalIncludedVertices, std::list<Vector2D>& intersections) {
    Vector2D result = Vector2D(0, 0);
    Vector2D referenceVector = Vector2D(0, 0);
    Vector2D externalVector = Vector2D(0, 0);
    if (intersections.size() == 2) {
        if (intersections.front().getX() == intersections.end()->getX()) {
            if (referenceIncludedVertices.size() > 0) {
                referenceVector = Vector2D(referenceIncludedVertices.front().getX() - intersections.front().getX(), 0);
            }
            if (externalIncludedVertices.size() > 0) {
                externalVector = Vector2D(externalIncludedVertices.front().getX() - intersections.front().getX(), 0);
            }
        } else if (intersections.front().getY() == intersections.end()->getY()) {
            if (referenceIncludedVertices.size() > 0) {
                referenceVector = Vector2D(0, referenceIncludedVertices.front().getY() - intersections.front().getY());
            }
            if (externalIncludedVertices.size() > 0) {
                externalVector = Vector2D(0, externalIncludedVertices.front().getY() - intersections.front().getY());
            }
        } else {
            if (abs(referenceIncludedVertices.front().getX() - externalIncludedVertices.front().getX()) > abs(referenceIncludedVertices.front().getY() - externalIncludedVertices.front().getY())) {
                referenceVector = Vector2D(0, referenceIncludedVertices.front().getY() - externalIncludedVertices.front().getY());
            } else if (abs(referenceIncludedVertices.front().getX() - externalIncludedVertices.front().getX()) < abs(referenceIncludedVertices.front().getY() - externalIncludedVertices.front().getY())) {
                referenceVector = Vector2D(referenceIncludedVertices.front().getX() - externalIncludedVertices.front().getX(), 0);
            } else {
                referenceVector = referenceIncludedVertices.front() - externalIncludedVertices.front();
            }
        }
        result = referenceVector - externalVector;
    } else if (intersections.size() == 4) {
        if (referenceIncludedVertices.front().getX() == referenceIncludedVertices.back().getX()) {
            result = Vector2D(referenceIncludedVertices.front().getX() - externalIncludedVertices.front().getX(), 0);
        } else {
            result = Vector2D(0, referenceIncludedVertices.front().getY() - externalIncludedVertices.front().getY());
        }
    }
    return result;
}

Vector2D& calculatePolygonCollisionVector(std::list<Vector2D>& referenceIncludedVertices, std::list<Vector2D>& externalIncludedVertices, std::list<Vector2D>& intersections) {
    Vector2D result = Vector2D(0, 0);
    Vector2D averageIntersection(std::accumulate(intersections.begin(), intersections.end(), Vector2D(0, 0)));
    averageIntersection /= intersections.size();
    if (intersections.size() == 2) {
        Border intersectionSegment = Border(intersections.front(), intersections.back(), true);
        if (referenceIncludedVertices.size() > 0) {
            if (bool side = !intersectionSegment.checkSide(referenceIncludedVertices.front())) {
                intersectionSegment.setInnerSide(side);
            }
            //arccos[(xa * xb + ya * yb) / (√(xa2 + ya2) * √(xb2 + yb2))]
            Vector2D intersectionVector;
            if (intersectionSegment.isInnerSide()) {
                intersectionVector = intersectionSegment.getNextVertex() - intersectionSegment.getPrevVertex();
            }
            double angle = acos(intersectionVector.getX() / sqrt(pow(intersectionVector.getX(), 2) + pow(intersectionVector.getY(), 2)));
            for (std::__cxx11::list<Vector2D>::iterator iter = referenceIncludedVertices.begin(); iter != referenceIncludedVertices.end(); iter++) {
                *iter -= averageIntersection;
                iter->setVector(iter->getX() * cos(angle) + iter->getY() * sin(angle), -iter->getX() * sin(angle) + iter->getY() * cos(angle));
            }
            double counter_angle = angle - 2 * M_PI;
            for (std::__cxx11::list<Vector2D>::iterator iter = externalIncludedVertices.begin(); iter != externalIncludedVertices.end(); iter++) {
                *iter -= averageIntersection;
                iter->setVector(iter->getX() * cos(counter_angle) + iter->getY() * sin(counter_angle), -iter->getX() * sin(counter_angle) + iter->getY() * cos(counter_angle));
            }
            result = calculateResultingVector2D(referenceIncludedVertices) - calculateResultingVector2D(externalIncludedVertices);
            angle *= -1;
            result.setVector(result.getX() * cos(angle) + result.getY() * sin(angle), -result.getX() * sin(angle) + result.getY() * cos(angle));
        }
    } else {
        //TODO: exceptional case to handle
    }
    return result;
}

Vector2D calculateResultingVector2D(std::list<Vector2D>& vectors) {
    int maxUp = 0;
    int maxDown = 0;
    int maxLeft = 0;
    int maxRight = 0;
    
    for (std::list<Vector2D>::iterator iter = vectors.begin(); iter != vectors.end(); iter++) {
        if (iter->getX() > maxRight) {
            maxRight = iter->getX();
        } else if (iter->getX() < maxLeft) {
            maxLeft = iter->getX();
        }
        if (iter->getY() > maxDown) {
            maxDown = iter->getY();
        } else if (iter->getY() < maxUp) {
            maxUp = iter->getY();
        }
    }
    return Vector2D(maxRight + maxLeft, maxDown + maxUp);
}