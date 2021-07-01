#include <cmath>
#include <algorithm>
#include "Border.h"

Border::Border(const Vector2D& prevEdge, const Vector2D& nextEdge) : prevEdge(prevEdge), nextEdge(nextEdge) {}

std::pair<std::pair<bool, Vector2D>, std::pair<bool, bool>> Border::checkBordersIntersection(const Border& border) {
    std::pair<std::pair<bool, Vector2D>, std::pair<bool, bool>> result = std::make_pair(std::make_pair(false, Vector2D(0, 0)), std::make_pair(false, false));
    double a1 = nextEdge.getY() - prevEdge.getY();
    double b1 = prevEdge.getX() - nextEdge.getX();
    double c1 = a1 * (prevEdge.getX()) + b1 * (prevEdge.getY());
    
    double a2 = border.nextEdge.getY() - border.prevEdge.getY();
    double b2 = border.prevEdge.getX() - border.nextEdge.getX();
    double c2 = a2 * (border.prevEdge.getX()) + b2 * (border.prevEdge.getY());
    
    double determinant = a1 * b2 - a2 * b1;
    
    if (determinant != 0) {
        int x = static_cast<int>(round((b2 * c1 - b1 * c2) / determinant));
        int y = static_cast<int>(round((a1 * c2 - a2 * c1) / determinant));
        result.first.second.setVector(x, y);
        result.second.first = this->checkSide(border.nextEdge);
        result.second.second = border.checkSide(this->nextEdge);
        
        if (x <= std::min(std::max(prevEdge.getX(), nextEdge.getX()), std::max(border.prevEdge.getX(), border.nextEdge.getX()))
            && x >= std::max(std::min(prevEdge.getX(), nextEdge.getX()), std::min(border.prevEdge.getX(), border.nextEdge.getX()))
            && y <= std::min(std::max(prevEdge.getY(), nextEdge.getY()), std::max(border.prevEdge.getY(), border.nextEdge.getY()))
            && y <= std::max(std::min(prevEdge.getY(), nextEdge.getY()), std::min(border.prevEdge.getY(), border.nextEdge.getY()))) {
        result.first.first = true;
        }
    }
    return result;
}

bool Border::checkSide(const Vector2D& edge) const{
    Border line = Border(*this);
    Vector2D point = Vector2D(edge);
    line.nextEdge.setX(line.nextEdge.getX() - line.prevEdge.getX());
    line.nextEdge.setY(line.nextEdge.getY() - line.prevEdge.getY());
    point.setX(point.getX() - line.prevEdge.getX());
    point.setY(point.getY() - line.prevEdge.getY());
    
    // Determining cross Product
    int crossProduct = line.nextEdge.getX() * point.getY() - line.nextEdge.getY() * point.getX();

    return (crossProduct >= 0 && innerSide) || (crossProduct < 0 && !innerSide);
}

const Vector2D& Border::getPrevEdge() const {
    return prevEdge;
}

void Border::setPrevEdge(const Vector2D& prevEdge) {
    Border::prevEdge = prevEdge;
}

const Vector2D& Border::getNextEdge() const {
    return nextEdge;
}

void Border::setNextEdge(const Vector2D& nextEdge) {
    Border::nextEdge = nextEdge;
}

bool Border::isInnerSide() const {
    return innerSide;
}

void Border::setInnerSide(bool innerSide) {
    Border::innerSide = innerSide;
}
