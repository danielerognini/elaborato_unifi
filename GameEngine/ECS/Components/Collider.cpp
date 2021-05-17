#include "Collider.h"

Collider::Collider(std::unique_ptr<std::vector<Vector2D>> vertices, const bool& active) : vertices(std::move(vertices)){
    this->active = active;
}
