#ifndef GAME_BORDER_H
#define GAME_BORDER_H

#include <utility>
#include "Vector2D.h"

class Border {
public:
    Border(const Vector2D& prevEdge, const Vector2D& nextEdge);
    
    std::pair<std::pair<bool, Vector2D>, std::pair<bool, bool>> checkBordersIntersection(const Border& border);
    
    bool checkSide(const Vector2D& edge) const;
    
    const Vector2D& getPrevEdge() const;
    
    void setPrevEdge(const Vector2D& prevEdge);
    
    const Vector2D& getNextEdge() const;
    
    void setNextEdge(const Vector2D& nextEdge);
    
    bool isInnerSide() const;
    
    void setInnerSide(bool innerSide);

private:
    Vector2D prevEdge;
    Vector2D nextEdge;
    bool innerSide; // given the segment prevEdge----------------nextEdge, true means under, false means over
};

#endif //GAME_BORDER_H
