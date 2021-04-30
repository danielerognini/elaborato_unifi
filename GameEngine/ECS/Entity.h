#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "Components/Collider.h"
#include "Components/Sprite.h"
#include "Components/Light.h"
#include "Components/Transform.h"
#include "../Activatable.h"

class Entity : public Activatable{
public:

    const Collider* getCollider(std::string name) const;

    bool addCollider(const std::string name, std::vector<Vector2D> &vertices);

    bool removeCollider(const std::string name);

    const Sprite &getSprite() const;

    void setSprite(const Sprite &sprite);

    const Transform &getTransform() const;

    void setTransform(const Transform &transform);

    const Light &getLight() const;

    void setLight(const Light &light);

    void update();
    void draw();

    void resolveCollision(Entity& externalEntity, Vector2D& ownVertex, Vector2D& externalVertex);

private:
    std::unordered_map<std::string, Collider> colliders;
    Sprite sprite;
    Transform transform;
    Light light;
};

#endif //GAME_ENTITY_H
