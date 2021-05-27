#include "Collider.h"
#include "../../Utility.h"
#include <cmath>

Collider::Collider(std::unique_ptr<std::vector<Vector2D>> vertices, const bool& active) : vertices(std::move(vertices)), center(calculateCenter()){
    this->active = active;
}

std::vector<Vector2D>::iterator Collider::getVerticesBegin() {
    return vertices->begin();
}

std::vector<Vector2D>::iterator Collider::getVerticesEnd() {
    return vertices->end();
}

const Vector2D& Collider::getCenter() {
    return center;
}

Vector2D Collider::calculateCenter() {
    double area = calculateArea();
    double lengthH1 = calculateTriangleHeight(area / vertices->size(), (*vertices)[0] % (*vertices)[1]);
    double lengthH2 = calculateTriangleHeight(area / vertices->size(), (*vertices)[1] % (*vertices)[2]);
    Vector2D vectorH1;
    vectorH1.setPolarVector2D(lengthH1, - (M_PI_2 + acos(((*vertices)[1].getX() - (*vertices)[0].getX()) / ((*vertices)[0] % (*vertices)[1]))));
    Vector2D vectorH2;
    vectorH2.setPolarVector2D(lengthH2, - (M_PI_2 + acos(((*vertices)[2].getX() - (*vertices)[1].getX()) / ((*vertices)[1] % (*vertices)[2]))));

    return ::checkLinesIntersection(std::make_pair((*vertices)[0] + vectorH1, (*vertices)[1] + vectorH1), std::make_pair((*vertices)[1] + vectorH2, (*vertices)[2] + vectorH2));
}

double Collider::calculateArea() {
    double area = 0.0;
    double a;
    double b;
    double c;

    for(std::vector<Vector2D>::iterator iter = std::next(vertices->begin(), 1); iter != std::prev(vertices->end(), 1); iter++) {
        a = (*vertices)[0] % *iter;
        b = *iter % *std::next(iter, 1);
        c = *std::next(iter, 1) % (*vertices)[0];
        double semiPerimeter = (a + b + c) / 2;
        area += sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
    }

    return area;
}

double Collider::calculateTriangleHeight(double area, double base) {
    return (area * 2) / base;
}
