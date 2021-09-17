#include "Text.h"

Text::Text(bool active) : Activatable(active) {
    rect.x = 0;
    rect.y = 0;
}

Text::~Text() {
}

SDL_Rect& Text::getRect() {
    return rect;
}

const std::string& Text::getMessage() const {
    return message;
}

void Text::setMessage(const std::string& message) {
    Text::message = message;
}

void Text::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
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

int Text::getSize() const {
    return size;
}

void Text::setColor1(const SDL_Color& color) {
    this->color = color;
}

void Text::setSize(int size) {
    this->size = size;
}

void Text::setOffset(int x, int y) {
    offset.setX(x);
    offset.setY(y);
}

void Text::setOffset(const Vector2D& offset) {
    this->offset = offset;
}

const Vector2D &Text::getOffset() const{
    return offset;
}
