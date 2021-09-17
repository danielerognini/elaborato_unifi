#include "Cursor.h"

//TODO: insert real texturePath
Cursor::Cursor() : Entity(""), currentHoveredWidget(nullptr) {}

Cursor& Cursor::getInstance() {
    static Cursor cursor = Cursor();
    return cursor;
}

void Cursor::setCurrentHoveredWidget(Widget* currentHoveredWidget) {
    this->currentHoveredWidget = currentHoveredWidget;
}

void Cursor::click() {
    if (currentHoveredWidget != nullptr) {
        currentHoveredWidget->onClick();
    }
}
