#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component
{

private:
	PositionComponent* position;
	SDL_Texture* texture;

	SDL_Rect srcRect, destRect;

public:
	Sprit






};



#endif SPRITECOMPONENT_H
