#ifndef GAME_TEXTURE_H
#define GAME_TEXTURE_H

#include "SDL.h"
#include <string>
#include <map>
#include <iostream>

class Texture {
private:
    static std::map<std::string, std::string> texturePaths;

public:
    //we want it to be static cause we want to call it as a class function rather than a member function belonging to an object
    //that also means we won't have to instantiate an object of this class to call this function
    static SDL_Texture& loadTexture(const std::string fileName);
    static void draw(SDL_Texture* texture, const SDL_Rect& src, const SDL_Rect& dest, const SDL_RendererFlip& flip);

    bool add(std::string name, std::string path);

    bool remove(std::string name);
};


#endif //GAME_TEXTURE_H
