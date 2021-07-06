#ifndef GAME_BORDER_H
#define GAME_BORDER_H

#include <utility>
#include "Vector2D.h"

class Border {
public:
    Border(const Vector2D& prevVertex, const Vector2D& nextVertex, const bool& innerSide = true);
    
    std::pair<std::pair<bool, Vector2D>, std::pair<bool, bool>> checkBordersIntersection(const Border& border, const Vector2D& referencePosition = Vector2D(0, 0), const Vector2D& externalPosition = Vector2D(0, 0));
    
    bool checkSide(const Vector2D& vertex) const;
    
    const Vector2D& getPrevVertex() const;
    
    void setPrevVertex(const Vector2D& prevVertex);
    
    const Vector2D& getNextVertex() const;
    
    void setNextVertex(const Vector2D& nextVertex);
    
    bool isInnerSide() const;
    
    void setInnerSide(bool innerSide);

private:
    Vector2D prevVertex;
    Vector2D nextVertex;
    bool innerSide; // given the segment prevVertex----------------nextVertex, true means under, false means over
};

#endif //GAME_BORDER_H
