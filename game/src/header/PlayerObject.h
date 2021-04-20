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

	void setX(int x);
	void setY(int y);

	int getX();
	int getY();



private:
	int xPos;
	int yPos;

	SDL_Texture* playerTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* rend;







};




#endif PlayerObject_H
