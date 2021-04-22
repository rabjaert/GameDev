#include "header/PlayerObject.h"
#include "header/TextureManager.h"


PlayerObject::PlayerObject(SDL_Renderer* ren, int x_Pos, int y_Pos) 
	: GameObject(ren, x_Pos, y_Pos)
{
	
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


void PlayerObject::update()
{
	
	auto *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_W]) 
		moveRelative(0, -5);
	if (state[SDL_SCANCODE_A])
		moveRelative(-5, 0);
	if (state[SDL_SCANCODE_S])
		moveRelative(0, 5);
	if (state[SDL_SCANCODE_D])
		moveRelative(5, 0);

	destRect.x = xPos;
	destRect.y = yPos;
};