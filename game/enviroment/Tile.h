#ifndef GAME_TILE_H
#define GAME_TILE_H

#include <ecs/Entity.h>

class Tile : public Entity{
public:
    Tile(const std::string& texturePath);

private:
    Collider& getCollider(const std::string& name) override;

    bool addCollider(const std::string& name, std::vector<Border> borders, const bool& active) override;

    bool removeCollider(const std::string& name) override;

    Text& getText() override;

    void setText(const Text& text) override;

    void resolveCollision(Entity* externalEntity, const Vector2D& collisionVector) override;

    bool isSolid() const override;

    void setSolid(bool solid) override;

    std::unordered_map<std::string, Collider>::iterator begin() override;
    std::unordered_map<std::string, Collider>::iterator end() override;
};


#endif //GAME_TILE_H
