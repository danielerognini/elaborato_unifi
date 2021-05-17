#ifndef GAME_COLLIDER_H
#define GAME_COLLIDER_H

#include <vector>
#include <memory>
#include "../../Activatable.h"
#include "../../Vector2D.h"

class Collider : public Activatable{
public:
    explicit Collider(std::unique_ptr<std::vector<Vector2D>> vertices, const bool& active = true);

private:
    std::unique_ptr<std::vector<Vector2D>> vertices;
};


#endif //GAME_COLLIDER_H
