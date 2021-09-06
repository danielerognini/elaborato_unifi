#include "Cursor.h"

//TODO: insert real texturePath
Cursor::Cursor() : Entity("") {}

Cursor& Cursor::getInstance() {
    static Cursor cursor = Cursor();
    return cursor;
}

void Cursor::setCurrentHoveredWidget(Widget* currentHoveredWidget) {
    this->currentHoveredWidget = currentHoveredWidget;
}

void Cursor::click() {
    if (currentHoveredWidget != nullptr) {
        //currentHoveredWidget->click();
    }
}
