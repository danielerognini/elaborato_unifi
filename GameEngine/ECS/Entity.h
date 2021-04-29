#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "Components/Collider.h"
#include "Components/Sprite.h"
#include "Components/Light.h"
#include "Components/Transform.h"
#include "../Activatable.h"

class Entity : public Activatable{
public:
    const Collider &getCollider() const;

    void setCollider(const Collider &collider);

    const Sprite &getSprite() const;

    void setSprite(const Sprite &sprite);

    const Transform &getTransform() const;

    void setTransform(const Transform &transform);

    const Light &getLight() const;

    void setLight(const Light &light);

    void update();
    void draw();

private:
    Collider collider;
    Sprite sprite;
    Transform transform;
    Light light;
};

#endif //GAME_ENTITY_H
