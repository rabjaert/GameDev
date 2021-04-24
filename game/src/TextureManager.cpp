#include "header/TextureManager.h"
#include "header/game.h"


SDL_Texture *TextureManager::loadTexture(const char* file, SDL_Renderer* renderer)
{
        
        SDL_Texture *texture = IMG_LoadTexture(renderer, file);
        if (!texture) {
                std::cout << "Error loading file " << file << std::endl;
                std::cout << IMG_GetError() << std::endl;
        }
        return texture;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
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

