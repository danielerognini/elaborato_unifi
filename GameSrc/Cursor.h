#ifndef GAME_CURSOR_H
#define GAME_CURSOR_H

#include <ECS/Entity.h>
#include "UI/Widget.h"

class Cursor : public Entity {
public:
    static Cursor& getInstance();
    void setCurrentHoveredWidget(Widget* currentHoveredWidget);
    void click();

private:
    Cursor();
    Widget* currentHoveredWidget;
};


#endif //GAME_CURSOR_H
