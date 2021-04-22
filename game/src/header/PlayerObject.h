#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include <SDL.h>
#include "GameObject.h"

class PlayerObject : public GameObject {

public:

	PlayerObject(SDL_Renderer* ren, int xPos, int yPos);

	void update() override;
};




#endif PLAYEROBJECT_H
