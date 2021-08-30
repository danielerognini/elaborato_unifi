#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "Components/Collider.h"
#include "Components/Sprite.h"
#include "Components/Transform.h"
#include "../Activatable.h"
#include "Components/Text.h"

class Entity : public Activatable {
public:
    explicit Entity(const std::string& texturePath, const bool& solid = true, const bool& active = true);
    
    Collider& getCollider(const std::string& name);
    
    bool addCollider(const std::string& name, std::vector<Border> borders, const bool& active);
    
    bool removeCollider(const std::string& name);
    
    Sprite& getSprite();
    
    Transform& getTransform();
    
    Text& getText();
    void setText(const Text& text);
    
    void update();
    void draw();
    
    void resolveCollision(const Entity& externalEntity, const Vector2D& collisionVector);
    
    const bool& isSolid() const;
    
    void setSolid(const bool& solid);
    
    bool isCollidersActive();
    
    std::unordered_map<std::string, Collider>::iterator getCollidersBegin();
    std::unordered_map<std::string, Collider>::iterator getCollidersEnd();

private:
    std::unordered_map<std::string, Collider> colliders;
    Sprite sprite;
    Text text;
    Transform transform;
    bool solid;
};

#endif //GAME_ENTITY_H
