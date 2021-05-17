#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include "SDL2/SDL.h"
#include "Vector2D.h"

class Input {
public:
    void scanInput();

private:
    SDL_Event event;
    Vector2D mousePosition;

    //-------Main Events------------------------
    void keyUp(const SDL_Event& event);
    void keyDown(const SDL_Event& event);
    void mouseButtonDown(const SDL_Event &event);
    void mouseButtonUp(const SDL_Event &event);
    void windowEvent(const SDL_Event &event);

    //-------Sub Events (must override)-----------------------
    virtual void closeWindow() = 0;

    virtual void mouseMotion(const int& x, const int& y) = 0;
    virtual void mouseButtonLeftDown() = 0;
    virtual void mouseButtonMiddleDown() = 0;
    virtual void mouseButtonRightDown() = 0;
    virtual void mouseButtonX1Down() = 0;
    virtual void mouseButtonX2Down() = 0;
    virtual void mouseButtonLeftUp() = 0;
    virtual void mouseButtonMiddleUp() = 0;
    virtual void mouseButtonRightUp() = 0;
    virtual void mouseButtonX1Up() = 0;
    virtual void mouseButtonX2Up() = 0;
    virtual void mouseWheel(const int& x, const int& y) = 0;

};


#endif //GAME_INPUT_H
