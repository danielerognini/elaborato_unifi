#ifndef GAME_COLLIDER_H
#define GAME_COLLIDER_H

#include <vector>
#include <memory>
#include "../../Activatable.h"
#include "../../Vector2D.h"

class Collider : public Activatable{
public:
    explicit Collider(std::unique_ptr<std::vector<Vector2D>> vertices, const bool& active = true);
    std::vector<Vector2D>::iterator getVerticesBegin();
    std::vector<Vector2D>::iterator getVerticesEnd();

    const Vector2D& getCenter();

private:
    std::unique_ptr<std::vector<Vector2D>> vertices;
    Vector2D center;
    Vector2D calculateCenter();
    double calculateArea();
    double calculateTriangleHeight(double area, double base);
};


#endif //GAME_COLLIDER_H
