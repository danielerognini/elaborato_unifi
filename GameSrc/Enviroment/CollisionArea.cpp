#include "CollisionArea.h"

CollisionArea::CollisionArea(bool solid, bool active) : Entity("", solid, active){

}

Sprite &CollisionArea::getSprite() {
    return Entity::getSprite();
}

Text &CollisionArea::getText() {
    return Entity::getText();
}

void CollisionArea::setText(const Text &text) {
    Entity::setText(text);
}
