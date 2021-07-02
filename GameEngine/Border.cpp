#include <cmath>
#include <algorithm>
#include "Border.h"

Border::Border(const Vector2D& prevVertex, const Vector2D& nextVertex) : prevVertex(prevVertex),
                                                                         nextVertex(nextVertex) {}

std::pair<std::pair<bool, Vector2D>, std::pair<bool, bool>> Border::checkBordersIntersection(const Border& border, const Vector2D& referencePosition, const Vector2D& externalPosition) {
    std::pair<std::pair<bool, Vector2D>, std::pair<bool, bool>> result = std::make_pair(
            std::make_pair(false, Vector2D(0, 0)), std::make_pair(false, false));
    Border reference = Border(*this);
    reference.setPrevVertex(reference.getPrevVertex() - referencePosition);
    reference.setNextVertex(reference.getNextVertex() - referencePosition);
    Border external = Border(border);
    external.setPrevVertex(external.getPrevVertex() - externalPosition);
    external.setNextVertex(external.getNextVertex() - externalPosition);
    double a1 = reference.nextVertex.getY() - reference.prevVertex.getY();
    double b1 = reference.prevVertex.getX() - reference.nextVertex.getX();
    double c1 = a1 * (reference.prevVertex.getX()) + b1 * (reference.prevVertex.getY());
    
    double a2 = external.nextVertex.getY() - external.prevVertex.getY();
    double b2 = external.prevVertex.getX() - external.nextVertex.getX();
    double c2 = a2 * (external.prevVertex.getX()) + b2 * (external.prevVertex.getY());
    
    double determinant = a1 * b2 - a2 * b1;
    
    if (determinant != 0) {
        int x = static_cast<int>(round((b2 * c1 - b1 * c2) / determinant));
        int y = static_cast<int>(round((a1 * c2 - a2 * c1) / determinant));
        result.first.second.setVector(x, y);
        result.second.first = this->checkSide(external.nextVertex);
        result.second.second = external.checkSide(reference.nextVertex);
        
        if (x <= std::min(std::max(reference.prevVertex.getX(), reference.nextVertex.getX()),
                          std::max(external.prevVertex.getX(), external.nextVertex.getX())) && x >= std::max(
                std::min(reference.prevVertex.getX(), reference.nextVertex.getX()),
                std::min(external.prevVertex.getX(), external.nextVertex.getX())) && y <= std::min(
                std::max(reference.prevVertex.getY(), reference.nextVertex.getY()),
                std::max(external.prevVertex.getY(), external.nextVertex.getY())) && y <= std::max(
                std::min(reference.prevVertex.getY(), reference.nextVertex.getY()),
                std::min(external.prevVertex.getY(), external.nextVertex.getY()))) {
            result.first.first = true;
        }
    }
    return result;
}

bool Border::checkSide(const Vector2D& vertex) const {
    Border line = Border(*this);
    Vector2D point = Vector2D(vertex);
    line.nextVertex.setX(line.nextVertex.getX() - line.prevVertex.getX());
    line.nextVertex.setY(line.nextVertex.getY() - line.prevVertex.getY());
    point.setX(point.getX() - line.prevVertex.getX());
    point.setY(point.getY() - line.prevVertex.getY());
    
    // Determining cross Product
    int crossProduct = line.nextVertex.getX() * point.getY() - line.nextVertex.getY() * point.getX();
    
    return (crossProduct >= 0 && innerSide) || (crossProduct < 0 && !innerSide);
}

const Vector2D& Border::getPrevVertex() const {
    return prevVertex;
}

void Border::setPrevVertex(const Vector2D& prevVertex) {
    Border::prevVertex = prevVertex;
}

const Vector2D& Border::getNextVertex() const {
    return nextVertex;
}

void Border::setNextVertex(const Vector2D& nextVertex) {
    Border::nextVertex = nextVertex;
}

bool Border::isInnerSide() const {
    return innerSide;
}

void Border::setInnerSide(bool innerSide) {
    Border::innerSide = innerSide;
}
