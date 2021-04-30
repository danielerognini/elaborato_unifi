#ifndef GAME_COLLIDER_H
#define GAME_COLLIDER_H

#include <vector>
#include "../../Activatable.h"
#include "../../Vector2D.h"

class Collider : public Activatable{
public:
    explicit Collider(std::vector<Vector2D> &vertices, bool active = true);

private:
    std::vector<Vector2D> vertices;
};


#endif //GAME_COLLIDER_H
