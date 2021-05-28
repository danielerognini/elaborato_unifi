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

    const SDL_Rect &getRect() const;

    void setRect(const int& x, const int& y, const int& w, const int& h);

    void setX(const int& x);
    void setY(const int& y);
    void setW(const int& w);
    void setH(const int& h);

    const std::string &getMessage() const;

    void setMessage(const std::string &message);

    void setColor(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a);

    void setFontPath(const std::string& fontPath);

    const std::string& getFontPath();

private:
    SDL_Rect rect;
    std::string message;
    SDL_Color color;
    std::string fontPath;
public:
    const SDL_Color &getColor() const;

    const int& getSize() const;

    void setColor1(const SDL_Color &color);

    void setSize(const int& size);

private:
    int size;
};


#endif //GAME_TEXT_H
