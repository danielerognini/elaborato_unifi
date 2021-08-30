#ifndef GAME_TEXT_H
#define GAME_TEXT_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <memory>
#include <Vector2D.h>
#include "../../Activatable.h"

class Text : public Activatable {
public:
    explicit Text(bool active = false);
    ~Text();
    
    SDL_Rect& getRect();

    void setOffset(const Vector2D& offset);
    void setOffset(int x, int y);

    const Vector2D& getOffset() const;
    
    const std::string& getMessage() const;
    
    void setMessage(const std::string& message);
    
    void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    
    void setFontPath(const std::string& fontPath);
    
    const std::string& getFontPath();

    const SDL_Color& getColor() const;
    
    int getSize() const;
    
    void setColor1(const SDL_Color& color);
    
    void setSize(int size);

private:
    Vector2D offset;
    SDL_Rect rect;
    std::string message;
    SDL_Color color;
    std::string fontPath;
    int size;
};

#endif //GAME_TEXT_H
