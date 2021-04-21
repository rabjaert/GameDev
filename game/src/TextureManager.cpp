#include "header/TextureManager.h"



SDL_Texture *TextureManager::loadTexture(const char* file, SDL_Renderer* renderer)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, file);
    return texture;
}

void TextureManager::disposeTexture(SDL_Texture* texture)
{
        std::cout << "Texture disposed" << std::endl;
        SDL_DestroyTexture(texture);
}


/*const char* TextureManager::GetImages(const char* folder, const char* image_name) {
    
    const char *satan = "res/textures/" + *folder + '/' + *image_name + '.png';
    
    
    return satan;
        
};*/

