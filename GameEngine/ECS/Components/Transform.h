#ifndef GAME_TRANSFORM_H
#define GAME_TRANSFORM_H

#include "../../Vector2D.h"
#include "../../Activatable.h"
#include <cmath>

enum Direction {
    RIGHT, RIGHT_DOWN, DOWN, LEFT_DOWN, LEFT, LEFT_UP, UP, RIGHT_UP
};

class Transform : public Activatable {
public:
    explicit Transform(int x = 0, int y = 0, Direction direction = DOWN, int speed = 0, bool moving = false, bool active = true);
    
    unsigned short int getSpeed() const;
    void setSpeed(unsigned short int speed);
    
    void update();
    
    Direction getDirection() const;
    void setDirection(Direction direction);
    
    bool isMoving() const;
    void setMoving(bool moving);
    
    const Vector2D& getPosition() const;
    void setPosition(int x, int y);

private:
    Vector2D position;
    //double direction; //in radians, clockwise is the positive direction, 0 is on the positive x axis (right side)
    Direction direction;
    unsigned short int speed;
    unsigned int lastMovement; // milliseconds of the last movement
    bool moving;
};

#endif //GAME_TRANSFORM_H
