#ifndef GAME_TRANSFORM_H
#define GAME_TRANSFORM_H

#include "../../Vector2D.h"
#include "../../Activatable.h"
#include <cmath>

class Transform : public Activatable{
private:

    Vector2D position;
    double direction; //in radians
    int speed;
    bool moving;

public:
    explicit Transform(int x = 0, int y = 0, double direction = 0.0, int speed = 0, bool active = true);

    int getSpeed() const;
    void setSpeed(int speed);

    void update();

    double getDirection() const;
    void setDirection(double direction);

    bool isMoving() const;
    void setMoving(bool moving);

    Vector2D& getPosition();
};


#endif //GAME_TRANSFORM_H
