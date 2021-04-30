#include "Collider.h"

Collider::Collider(std::vector<Vector2D> &vertices, bool active) : vertices(vertices){
    this->active = active;
}
