#ifndef GAME_TRANSFORM_H
#define GAME_TRANSFORM_H

#include "../Vector2D.h"
#include <cmath>

class Transform {
private:
    bool active;

    Vector2D position;
    double direction; //in radians
    int speed;
    bool moving;

public:
    Transform(int x, int y, double direction = 0.0, int speed = 0, bool active = true);

    bool isActive() const;
    void toggle();
    void setActive(bool status);

    int getSpeed() const;
    void setSpeed(int speed);

    void update();

    double getDirection() const;
    void setDirection(double direction);

    bool isMoving() const;
    void setMoving(bool moving);
};


#endif //GAME_TRANSFORM_H
