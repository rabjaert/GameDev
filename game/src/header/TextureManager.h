#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>



class TextureManager {

public:


	static SDL_Texture* loadTexture(const char* fileName, SDL_Renderer* rendrer);

	
	
	//static const char* GetImages(const char* folder, const char* image_name);
		
	

};

#endif TEXTUREMANAGER_H
