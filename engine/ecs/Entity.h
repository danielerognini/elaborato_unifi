#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "components/Collider.h"
#include "components/Sprite.h"
#include "components/Transform.h"
#include "../Activatable.h"
#include "components/Text.h"

struct ManagerStatus {
    bool* active;
    bool* frozen;
};

class Entity : public Activatable {
public:
    explicit Entity(const std::string& texturePath, bool solid = true);
    
    virtual Collider& getCollider(const std::string& name);

    virtual bool addCollider(const std::string& name, std::vector<Border> borders, const bool& active);

    virtual bool removeCollider(const std::string& name);

    virtual Sprite& getSprite();

    virtual Transform& getTransform();

    virtual Text& getText();
    virtual void setText(const Text& text);

    virtual void update();
    virtual void draw();

    virtual void resolveCollision(Entity* externalEntity, const Vector2D& collisionVector);

    virtual bool isSolid() const;
    
    virtual void setSolid(bool solid);
    
    virtual bool isCollidersActive();
    
    virtual std::unordered_map<std::string, Collider>::iterator begin();
    virtual std::unordered_map<std::string, Collider>::iterator end();
    
    virtual const ManagerStatus& getManagerStatus() const;
    virtual void setManagerStatus(const ManagerStatus& managerStatus);

private:
    std::unordered_map<std::string, Collider> colliders;
    Sprite sprite;
    Text text;
    Transform transform;
    bool solid;
    ManagerStatus managerStatus;
};

#endif //GAME_ENTITY_H
