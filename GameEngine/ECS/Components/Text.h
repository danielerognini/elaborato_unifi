#ifndef GAME_TEXT_H
#define GAME_TEXT_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <memory>
#include "../../Activatable.h"

class Text : public Activatable {
public:
    explicit Text(bool active = false);
    ~Text();

    void update();
    
    SDL_Rect& getRect();
    
    void setRect(const int& x, const int& y);
    
    void setX(const int& x);
    void setY(const int& y);
    
    const std::string& getMessage() const;
    
    void setMessage(const std::string& message);
    
    void setColor(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a);
    
    void setFontPath(const std::string& fontPath);
    
    const std::string& getFontPath();

    const SDL_Color& getColor() const;
    
    const int& getSize() const;
    
    void setColor1(const SDL_Color& color);
    
    void setSize(const int& size);

private:
    SDL_Rect rect;
    std::string message;
    SDL_Color color;
    std::string fontPath;
    int size;
};

#endif //GAME_TEXT_H
