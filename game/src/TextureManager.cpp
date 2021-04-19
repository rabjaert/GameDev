#include "header/TextureManager.h"



SDL_Texture* TextureManager::LoadTexture(const char* file, SDL_Renderer* renderer)
{
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(file);
    if (surface) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
    return texture;
};

/*const char* TextureManager::GetImages(const char* folder, const char* image_name) {
    
    const char *satan = "res/textures/" + *folder + '/' + *image_name + '.png';
    
    
    return satan;
        
};*/

