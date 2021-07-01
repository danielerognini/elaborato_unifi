//
// Created by dom on 01/07/21.
//

#include "Segment.h"

Segment::Segment(const Vector2D& tail, const Vector2D& head) : tail(tail), head(head) {}

Vector2D Segment::checkSegmentsIntersection(const Segment& line) {
    //implement the line intersection check returning the intersection vector relative to the reference line (distance between intersection point and reference vertex)
    //we are going to use the formula: y = mx + q
    double m1 = static_cast<double>(head.getY() - tail.getY()) / static_cast<double>(head.getX() - tail.getX());
    double q1 = tail.getY() - tail.getX() * m1;
    double m2 = static_cast<double>(line.getHead().getY() - line.getTail().getY()) / static_cast<double>(line.getHead().getX() - line.getTail().getX());
    double q2 = line.getTail().getY() - line.getTail().getX() * m2;
    int x = (q1 - q2) / (m2 - m1);
    int y = x * m2 + q2;
    
    return Vector2D(x, y);
}

const Vector2D& Segment::getTail() const {
    return tail;
}

void Segment::setTail(const Vector2D& tail) {
    Segment::tail = tail;
}

const Vector2D& Segment::getHead() const {
    return head;
}

void Segment::setHead(const Vector2D& head) {
    Segment::head = head;
}
