#ifndef PlayerObject_H
#define PlayerObject_H

#include <SDL.h>
//#include <SDL_image.h>

class PlayerObject {

public:
	PlayerObject(const char* image, SDL_Renderer* ren);
	~PlayerObject();

	void Update();
	void Renderer();

private:
	
	int xPos;
	int yPos;

	SDL_Texture* playerTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* rend;
};
#endif PlayerObject_H
