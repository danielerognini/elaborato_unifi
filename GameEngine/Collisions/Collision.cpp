#include <future>
#include <map>
#include <numeric>
#include <iostream>
#include "Collision.h"
#include "Utility.h"

void Collision::collisionUpdate(std::unordered_map<std::string, Manager>& managers) {
    std::list<std::future<void>> asyncCalls;
    
    for (auto iter = managers.begin(); iter != managers.end(); iter++) {
        asyncCalls.push_back(std::async(std::launch::async, &Collision::resolveLocalCollisions, iter));
    }
    for (auto& asyncCall: asyncCalls) {
        asyncCall.get();
    }
    
    for (auto iter = managers.begin(); std::next(iter, 1) != managers.end(); iter++) {
        if (iter->second.isGlobalCollisionsActive()) {
            for (auto subIter = std::next(iter, 1); subIter != managers.end(); subIter++) {
                if (subIter->second.isGlobalCollisionsActive()) {
                    for (auto subSubIter = iter->second.begin(); subSubIter != iter->second.end(); subSubIter++) {
                        if ((*subSubIter)->isCollidersActive()) {
                            for (auto& subSubSubIter: subIter->second) {
                                if ((*subSubIter)->isCollidersActive()) {
                                    Collision::resolveEntityCollisions(**subSubIter, *subSubSubIter);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Collision::resolveLocalCollisions(std::unordered_map<std::string, Manager>::iterator iter) {
    if (iter->second.isLocalCollisionsActive()) {
        
        for (auto subIter = iter->second.begin(); std::next(subIter, 1) != iter->second.end(); subIter++) {
            if ((*subIter)->isCollidersActive()) {
                for (auto subSubIter = std::next(subIter, 1); subSubIter != iter->second.end(); subSubIter++) {
                    if ((*subSubIter)->isCollidersActive()) {
                        Collision::resolveEntityCollisions(**subIter, **subSubIter);
                    }
                }
            }
        }
    }
}

void Collision::resolveEntityCollisions(Entity& entity1, Entity& entity2) {
    Vector2D vector = Collision::controlEntityCollisions(entity1, entity2);
    entity1.resolveCollision(entity2, vector);
    entity2.resolveCollision(entity1, vector * (-1));
}

Vector2D Collision::controlEntityCollisions(Entity& reference, Entity& external) {
    std::list<Vector2D> referenceVectors;
    for (auto& ref: reference) {
        if (ref.second.isActive()) {
            for (auto& ext: external) {
                if (ext.second.isActive()) {
                    referenceVectors.push_back(Collision::controlColliderCollisions(ref.second, reference.getTransform().getPosition(), ext.second, external.getTransform().getPosition()));
                }
            }
        }
    }
    return Collision::calculateResultingVector2D(referenceVectors);
}

Vector2D Collision::controlColliderCollisions(Collider& reference, const Vector2D& referencePosition, Collider& external, const Vector2D& externalPosition) {
    
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
    
    for (auto iter = reference.begin(); iter != reference.end(); iter++) {
        referenceBorderIndex = static_cast<int>(iter - reference.begin());
        for (auto subIter = external.begin(); subIter != external.end(); subIter++) {
            externalBorderIndex = static_cast<int>(subIter - external.begin());
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
    
    for (auto iter = referenceIntersectedBorders.begin(); iter != referenceIntersectedBorders.end(); iter++) {
        if (iter->second.incoming) {
            referenceIncludedVertices.emplace_back(iter->second.border.getNextVertex());
            for (auto subIter = std::next(reference.begin(), iter->first + 1) != reference.end() ? std::next(reference.begin(), iter->first + 1) : reference.begin(); std::next(iter, 1) != referenceIntersectedBorders.end() ? subIter - reference.begin() != std::next(iter, 1)->first : subIter - reference.begin() != referenceIntersectedBorders.begin()->first; std::next(subIter, 1) != reference.end() ? subIter++ : subIter = reference.begin()) {
                referenceIncludedVertices.emplace_back(subIter->getNextVertex());
            }
        }
    }
    std::list<Vector2D> intersections;
    for (auto iter = externalIntersectedBorders.begin(); iter != externalIntersectedBorders.end(); iter++) {
        intersections.emplace_back(std::accumulate(iter->second.intersections.begin(), iter->second.intersections.end(), Vector2D(0, 0)) / static_cast<int>(iter->second.intersections.size()));
        if (iter->second.incoming) {
            externalIncludedVertices.emplace_back(iter->second.border.getNextVertex());
            for (auto subIter = std::next(external.begin(), iter->first + 1) != external.end() ? std::next(external.begin(), iter->first + 1) : external.begin(); std::next(iter, 1) != externalIntersectedBorders.end() ? subIter - external.begin() != std::next(iter, 1)->first : subIter - external.begin() != externalIntersectedBorders.begin()->first; std::next(subIter, 1) != external.end() ? subIter++ : subIter = external.begin()) {
                externalIncludedVertices.emplace_back(subIter->getNextVertex());
            }
        }
    }
    Vector2D result = Vector2D(0, 0);
    if (!referenceIncludedVertices.empty() || !externalIncludedVertices.empty()) {
        for (auto& referenceIncludedVertex: referenceIncludedVertices) {
            referenceIncludedVertex += referencePosition;
        }
        for (auto& externalIncludedVertex: externalIncludedVertices) {
            externalIncludedVertex += externalPosition;
        }
        //result = calculatePolygonCollisionVector(referenceIncludedVertices, externalIncludedVertices, intersections);
        result = Collision::calculateRectCollisionVector(referenceIncludedVertices, externalIncludedVertices, intersections);
    }
    return result;
}

Vector2D Collision::calculateRectCollisionVector(std::list<Vector2D>& referenceIncludedVertices, std::list<Vector2D>& externalIncludedVertices, std::list<Vector2D>& intersections) {
    Vector2D result = Vector2D(0, 0);
    Vector2D referenceVector = Vector2D(0, 0);
    Vector2D externalVector = Vector2D(0, 0);
    if (intersections.size() == 2) {
        if (intersections.front().getX() == intersections.end()->getX()) {
            if (!referenceIncludedVertices.empty()) {
                referenceVector = Vector2D(referenceIncludedVertices.front().getX() - intersections.front().getX(), 0);
            }
            if (!externalIncludedVertices.empty()) {
                externalVector = Vector2D(externalIncludedVertices.front().getX() - intersections.front().getX(), 0);
            }
        } else if (intersections.front().getY() == intersections.end()->getY()) {
            if (!referenceIncludedVertices.empty()) {
                referenceVector = Vector2D(0, referenceIncludedVertices.front().getY() - intersections.front().getY());
            }
            if (!externalIncludedVertices.empty()) {
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

/* TODO: solve in finite algebra
Vector2D Collision::calculatePolygonCollisionVector(std::list<Vector2D>& referenceIncludedVertices, std::list<Vector2D>& externalIncludedVertices, std::list<Vector2D>& intersections) {
    Vector2D result = Vector2D(0, 0);
    Vector2D averageIntersection(std::accumulate(intersections.begin(), intersections.end(), Vector2D(0, 0)));
    averageIntersection /= static_cast<int>(intersections.size());
    if (intersections.size() == 2) {
        Border intersectionSegment = Border(intersections.front(), intersections.back(), true);
        if (!referenceIncludedVertices.empty()) {
            if (bool side = !intersectionSegment.checkSide(referenceIncludedVertices.front())) {
                intersectionSegment.setInnerSide(side);
            }
            //arccos[(xa * xb + ya * yb) / (√(xa2 + ya2) * √(xb2 + yb2))]
            Vector2D intersectionVector;
            if (intersectionSegment.isInnerSide()) {
                intersectionVector = intersectionSegment.getNextVertex() - intersectionSegment.getPrevVertex();
            }
            double angle = acos(intersectionVector.getX() / sqrt(pow(intersectionVector.getX(), 2) + pow(intersectionVector.getY(), 2)));
            for (auto & iter : referenceIncludedVertices) {
                iter -= averageIntersection;
                iter.setVector(static_cast<int>(iter.getX() * cos(angle) + iter.getY() * sin(angle)), static_cast<int>(-iter.getX() * sin(angle) + iter.getY() * cos(angle)));
            }
            double counter_angle = angle - 2 * M_PI;
            for (auto & iter : externalIncludedVertices) {
                iter -= averageIntersection;
                iter.setVector(static_cast<int>(iter.getX() * cos(counter_angle) + iter.getY() * sin(counter_angle)), static_cast<int>(-iter.getX() * sin(counter_angle) + iter.getY() * cos(counter_angle)));
            }
            result = calculateResultingVector2D(referenceIncludedVertices) - calculateResultingVector2D(externalIncludedVertices);
            angle *= -1;
            result.setVector(static_cast<int>(result.getX() * cos(angle) + result.getY() * sin(angle)), static_cast<int>(-result.getX() * sin(angle) + result.getY() * cos(angle)));
        }
    } else {
        //TODO: exceptional case to handle
    }
    return result;
}
*/

Vector2D Collision::calculateResultingVector2D(std::list<Vector2D>& vectors) {
    int maxUp = 0;
    int maxDown = 0;
    int maxLeft = 0;
    int maxRight = 0;
    
    for (auto& iter: vectors) {
        if (iter.getX() > maxRight) {
            maxRight = iter.getX();
        } else if (iter.getX() < maxLeft) {
            maxLeft = iter.getX();
        }
        if (iter.getY() > maxDown) {
            maxDown = iter.getY();
        } else if (iter.getY() < maxUp) {
            maxUp = iter.getY();
        }
    }
    return Vector2D(maxRight + maxLeft, maxDown + maxUp);
}