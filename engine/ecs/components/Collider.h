#ifndef GAME_COLLIDER_H
#define GAME_COLLIDER_H

#include <vector>
#include <memory>
#include "../../Activatable.h"
#include "collisions/Border.h"

class Collider : public Activatable {
public:
    //borders must be directed and inserted clockwise
    Collider(std::vector<Border> borders, bool active);
    
    std::vector<Border>::iterator begin();
    std::vector<Border>::iterator end();
    
    
    //const Vector2D& getCenter();

private:
    std::vector<Border> borders;
    /*
    Vector2D center;
    Vector2D calculateCenter();
    double calculateArea();
    double calculateTriangleHeight(double area, double base);
     */
};

#endif //GAME_COLLIDER_H
