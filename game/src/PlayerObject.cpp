#include "header/PlayerObject.h"
#include "header/TextureManager.h"


PlayerObject::PlayerObject(const char* filename, SDL_Renderer* ren, int x_Pos, int y_Pos) 
{
	rend = ren;
	playerTexture = TextureManager::loadTexture(filename, ren);
	xPos = x_Pos;
	yPos = y_Pos;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 30;
	srcRect.w = 15;

	destRect.x = 0;
	destRect.y = 0;
	destRect.h = 64;
	destRect.w = 64;
};

PlayerObject::~PlayerObject()
{
	TextureManager::disposeTexture(playerTexture);
}


void PlayerObject::update()
{
	destRect.x = xPos;
	destRect.y = yPos;
};

void PlayerObject::render() 
{
	SDL_RenderCopy(rend, playerTexture, &srcRect, &destRect);
};

void PlayerObject::setX(const int x) {
	xPos = x;
}

void PlayerObject::setY(const int y) {
	yPos = y;
}

