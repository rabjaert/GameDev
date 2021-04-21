#ifndef PlayerObject_H
#define PlayerObject_H

#include <SDL.h>
//#include <SDL_image.h>


class PlayerObject {

public:
	PlayerObject(const char* image, SDL_Renderer* ren, int xPos, int yPos);
	~PlayerObject();


	void Update();
	void RenderObject();

	void setX(const int x);
	void setY(const int y);

	int getX();
	int getY();



private:
	int xPos;
	int yPos;

	SDL_Texture* playerTexture = nullptr;
	SDL_Renderer* rend = nullptr;
	SDL_Rect srcRect, destRect;
	
};




#endif PlayerObject_H
