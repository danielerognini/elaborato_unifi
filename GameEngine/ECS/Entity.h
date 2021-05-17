#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "Components/Collider.h"
#include "Components/Sprite.h"
#include "Components/Transform.h"
#include "../Activatable.h"

class Entity : public Activatable{
public:
    explicit Entity(const std::string& texturePath, const bool& solid = true, const bool& active = true);

    const Collider& getCollider(const std::string& name) const;

    bool addCollider(const std::string& name, std::unique_ptr<std::vector<Vector2D>> vertices);

    bool removeCollider(const std::string& name);

    const Sprite& getSprite() const;

    const Transform& getTransform() const;

    void update();
    void draw();

    void resolveCollision(const Entity& externalEntity, const Vector2D& ownVertex, const Vector2D& externalVertex);

    const bool& isSolid() const;

    void setSolid(const bool& solid);

private:
    std::unordered_map<std::string, Collider> colliders;
    Sprite sprite;
    Transform transform;
    bool solid;
};

#endif //GAME_ENTITY_H
