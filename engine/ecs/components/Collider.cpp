#include "Collider.h"
#include <cmath>

Collider::Collider(std::vector<Border> borders, bool active) : Activatable(active), borders(std::move(borders))/*, center(calculateCenter())*/{
}

std::vector<Border>::iterator Collider::begin() {
    return borders.begin();
}

std::vector<Border>::iterator Collider::end() {
    return borders.end();
}
/*
const Vector2D& Collider::getCenter() {
    return center;
}

Vector2D Collider::calculateCenter() {
    double area = calculateArea();
    double lengthH1 = calculateTriangleHeight(area / borders->size(), (*borders)[0] % (*borders)[1]);
    double lengthH2 = calculateTriangleHeight(area / borders->size(), (*borders)[1] % (*borders)[2]);
    Vector2D vectorH1;
    vectorH1.setPolarVector2D(lengthH1, (M_PI_2 + acos(((*borders)[1].getX() - (*borders)[0].getX()) / ((*borders)[0] % (*borders)[1]))));
    Vector2D vectorH2;
    vectorH2.toCartesian(lengthH2, - (M_PI_2 + acos(((*borders)[2].getX() - (*borders)[1].getX()) / ((*borders)[1] % (*borders)[2]))));

    return ::checkLinesIntersection(std::make_pair((*borders)[0] + vectorH1, (*borders)[1] + vectorH1), std::make_pair((*borders)[1] + vectorH2, (*borders)[2] + vectorH2));
}

double Collider::calculateArea() {
    double area = 0.0;
    double a;
    double b;
    double c;

    for(std::vector<Vector2D>::iterator iter = std::next(borders->begin(), 1); iter != std::prev(borders->end(), 1); iter++) {
        a = (*borders)[0] % *iter;
        b = *iter % *std::next(iter, 1);
        c = *std::next(iter, 1) % (*borders)[0];
        double semiPerimeter = (a + b + c) / 2;
        area += sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
    }

    return area;
}

double Collider::calculateTriangleHeight(double area, double base) {
    return (area * 2) / base;
}
*/