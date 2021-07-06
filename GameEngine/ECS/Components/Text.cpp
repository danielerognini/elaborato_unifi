#include "Text.h"

Text::Text(bool active) {
    this->active = active;
}

Text::~Text() {
}

const SDL_Rect& Text::getRect() const {
    return rect;
}

void Text::setRect(const int& x, const int& y, const int& w, const int& h) {
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

void Text::setX(const int& x) {
    rect.x = x;
}

void Text::setY(const int& y) {
    rect.y = y;
}

void Text::setW(const int& w) {
    rect.w = w;
}

void Text::setH(const int& h) {
    rect.h = h;
}

const std::string& Text::getMessage() const {
    return message;
}

void Text::setMessage(const std::string& message) {
    Text::message = message;
}

void Text::setColor(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a) {
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
}

void Text::setFontPath(const std::string& fontPath) {
    this->fontPath = fontPath;
}

const std::string& Text::getFontPath() {
    return fontPath;
}

const SDL_Color& Text::getColor() const {
    return color;
}

const int& Text::getSize() const {
    return size;
}

void Text::setColor1(const SDL_Color& color) {
    this->color = color;
}

void Text::setSize(const int& size) {
    this->size = size;
}
