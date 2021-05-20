#include "Collider.h"

Collider::Collider(std::unique_ptr<std::vector<Vector2D>> vertices, const bool& active) : vertices(std::move(vertices)){
    this->active = active;
}

std::vector<Vector2D>::iterator Collider::getVerticesBegin() {
    return vertices->begin();
}

std::vector<Vector2D>::iterator Collider::getVerticesEnd() {
    return vertices->end();
}

Vector2D Collider::getCenter() {
    //TODO: calculate the center of the polygon
    return Vector2D();
}
