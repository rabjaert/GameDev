#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include <SDL.h>
//#include <SDL_image.h>


class PlayerObject {

public:
	PlayerObject(const char* image, SDL_Renderer* ren, int xPos, int yPos);
	~PlayerObject();


	void update();
	void render();

	void setX(const int x);
	void setY(const int y);

	inline int getX() { return xPos; }
	inline int gety() { return yPos; }




private:
	int xPos;
	int yPos;

	SDL_Texture* playerTexture = nullptr;
	SDL_Renderer* rend = nullptr;
	SDL_Rect srcRect, destRect;
	
};




#endif PLAYEROBJECT_H
