#include "header/PlayerObject.h"
#include "header/TextureManager.h"


PlayerObject::PlayerObject(const char* filename, SDL_Renderer* ren, int x_Pos, int y_Pos) {
	rend = ren;
	playerTexture = TextureManager::LoadTexture(filename, ren);
	xPos = x_Pos;
	yPos = y_Pos;
};


void PlayerObject::Update()
{
	

	srcRect.h = 30;
	srcRect.w = 15;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 64;
	destRect.w = 64;
	destRect.x = xPos;
	destRect.y = yPos;

};

void PlayerObject::RenderObject() {
	SDL_RenderCopy(rend, playerTexture, &srcRect, &destRect);
};

void PlayerObject::setX(int x) {
	xPos = x;
}

void PlayerObject::setY(int y) {
	yPos = y;
}

int PlayerObject::getX() {
	return xPos;
}
int PlayerObject::getY() {
	return yPos;
}
