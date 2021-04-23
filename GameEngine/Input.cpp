#include "Input.h"
#include "Engine.h"

void Input::scanInput() {
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_KEYDOWN:
            keyDown(event);
            break;
        case SDL_QUIT:
            closeWindow();
            break;

    }
}

void Input::keyDown(SDL_Event& event) {
    switch(event.key.keysym.sym) {
        case SDLK_0:
            break;
        case SDLK_1:
            break;
        case SDLK_2:
            break;
        case SDLK_3:
            break;
        case SDLK_4:
            break;
        case SDLK_5:
            break;
        case SDLK_6:
            break;
        case SDLK_7:
            break;
        case SDLK_8:
            break;
        case SDLK_9:
            break;
        case SDLK_q:
            break;
        case SDLK_e:
            break;
        case SDLK_r:
            break;
        case SDLK_t:
            break;
        case SDLK_y:
            break;
        case SDLK_u:
            break;
        case SDLK_i:
            break;
        case SDLK_o:
            break;
        case SDLK_p:
            break;
        case SDLK_a:
            break;
        case SDLK_s:
            break;
        case SDLK_d:
            break;
        case SDLK_f:
            break;
        case SDLK_g:
            break;
        case SDLK_h:
            break;
        case SDLK_j:
            break;
        case SDLK_k:
            break;
        case SDLK_l:
            break;
        case SDLK_z:
            break;
        case SDLK_x:
            break;
        case SDLK_c:
            break;
        case SDLK_v:
            break;
        case SDLK_b:
            break;
        case SDLK_n:
            break;
        case SDLK_m:
            break;
        case SDLK_SPACE:
            break;
        case KMOD_LCTRL:
            break;
        case KMOD_LALT:
            break;
        case KMOD_LSHIFT:
            break;
        case KMOD_RCTRL:
            break;
        case KMOD_RALT:
            break;
        case KMOD_RSHIFT:
            break;
        case SDLK_ESCAPE:
            break;
        case SDLK_BACKSLASH:
            break;
        case SDLK_COLON:
            break;
        case SDLK_SEMICOLON:
            break;
        case SDLK_COMMA:
            break;
        case SDLK_STOP:
            break;
        case SDLK_UNDERSCORE:
            break;
        case SDLK_BACKSPACE:
            break;
        case SDLK_TAB:
            break;

        default:
            break;
    }
}