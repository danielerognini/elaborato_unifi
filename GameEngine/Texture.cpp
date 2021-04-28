#include "Texture.h"
#include "Engine.h"
#include "SDL2/SDL_image.h"
#include <iostream>

SDL_Texture* Texture::loadTexture(const std::string textureName) {
    SDL_Texture* texture = IMG_LoadTexture(Engine::getRenderer(), texturePaths[textureName].c_str()); // LOADS A TEXTURE DIRECTLY FROM THE IMAGE
    if(texture == NULL) //checks if the SDL_image library failed to load the image
    {
        std::cout << "error loading the texture; "; //prints an error to console
        texture = IMG_LoadTexture(Engine::getRenderer(), "../GameEngine/Assets/EmptySprite.png"); //loads the default empty sprite //TODO: change path for the empty sprite
        std::cout << "an empty texture has been assigned to the object." << std::endl;
    }

    return texture; //returning the texture
}

void Texture::draw(const std::string textureName, const SDL_Rect& src, const SDL_Rect& dest, const SDL_RendererFlip& flip) {
    SDL_RenderCopyEx(Engine::getRenderer(), loadTexture(textureName), &src, &dest, NULL, NULL, flip); //the nulls are because we are not implementing a sprite rotation but a flip
}

bool Texture::add(std::string name, std::string path) {
    return texturePaths.emplace(name, path).second;
}

bool Texture::remove(std::string name) {
    return texturePaths.erase(name);
}
