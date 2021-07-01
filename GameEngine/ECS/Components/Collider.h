#ifndef GAME_COLLIDER_H
#define GAME_COLLIDER_H

#include <vector>
#include <memory>
#include "../../Activatable.h"
#include "../../Segment.h"

class Collider : public Activatable{
public:
    Collider(std::unique_ptr<std::vector<Segment>> borders, const bool& active);
    
    std::vector<Segment>::iterator getBordersBegin();
    std::vector<Segment>::iterator getBordersEnd();

    //const Vector2D& getCenter();

private:
    std::unique_ptr<std::vector<Segment>> borders;
    /*
    Vector2D center;
    Vector2D calculateCenter();
    double calculateArea();
    double calculateTriangleHeight(double area, double base);
     */
};


#endif //GAME_COLLIDER_H
