#ifndef GAME_TRANSFORM_H
#define GAME_TRANSFORM_H

#include "../../Vector2D.h"
#include "../../Activatable.h"
#include <cmath>

class Transform : public Activatable {
public:
    explicit Transform(const int& x = 0, const int& y = 0, const double& direction = 0.0, const int& speed = 0, const bool& moving = false, const bool& active = true);
    
    const int& getSpeed() const;
    void setSpeed(const int& speed);
    
    void update();
    
    const double& getDirection() const;
    void setDirection(const double& direction);
    
    const bool& isMoving() const;
    void setMoving(const bool& moving);
    
    const Vector2D& getPosition() const;
    void setPosition(const int& x, const int& y);

private:
    Vector2D position;
    double direction; //in radians, clockwise is the positive direction, 0 is on the positive x axis (right side)
    int speed;
    bool moving;
};

#endif //GAME_TRANSFORM_H
