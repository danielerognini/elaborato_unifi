#ifndef GAME_UTILITY_H
#define GAME_UTILITY_H

#include "Vector2D.h"

template<class Iterator, class Object>
void bubble_sort(Iterator begin, Iterator end, Object object) {
    bool ordered;
    int k = 0;
    do {
        ordered = true;
        for (Iterator i = begin; i != std::prev(end, k); i++) {
            if (object->compare(*i, *(std::prev(i, 1)))) {
                std::iter_swap(i, std::prev(i, 1));
                ordered = false;
            }
        }
        k++;
    } while (!ordered);
}

inline Vector2D checkLinesIntersection(std::pair<Vector2D, Vector2D> reference, std::pair<Vector2D, Vector2D> external) {
    //implement the line intersection check returning the intersection vector relative to the reference line (distance between intersection point and reference vertex)
    //we are going to use the formula: y = mx + q
    double m1 = static_cast<double>(reference.second.getY() - reference.first.getY()) / static_cast<double>(reference.second.getX() - reference.first.getX());
    double q1 = reference.first.getY() - reference.first.getX() * m1;
    double m2 = static_cast<double>(external.second.getY() - external.first.getY()) / static_cast<double>(external.second.getX() - external.first.getX());
    double q2 = external.first.getY() - external.first.getX() * m2;
    int x = (q1 - q2) / (m2 - m1);
    int y = x * m2 + q2;
    
    return Vector2D(x, y);
}

#endif //GAME_UTILITY_H
