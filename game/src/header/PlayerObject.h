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

	/* Set the player's position */
	void setX(const int x);
	void setY(const int y);
	void setPosition(const int x, const int y);

	/* Moves the player relative to its current position */
	void moveRelative(const int x, const int y);

	/* Getters for position */
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
