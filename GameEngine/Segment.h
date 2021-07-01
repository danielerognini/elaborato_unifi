//
// Created by dom on 01/07/21.
//

#ifndef GAME_SEGMENT_H
#define GAME_SEGMENT_H

#include "Vector2D.h"

class Segment {
public:
    Segment(const Vector2D& tail, const Vector2D& head);
    
    Vector2D checkSegmentsIntersection(const Segment& line);
    
    const Vector2D& getTail() const;
    void setTail(const Vector2D& tail);
    const Vector2D& getHead() const;
    void setHead(const Vector2D& head);

private:
    Vector2D tail;
    Vector2D head;
};

#endif //GAME_SEGMENT_H
