#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H


#include "../game.h"
#include "EntityComponent.h"
#include "Components.h"

class KeyboardController : public Component
{

public:
	TransformComponent *transform;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();

	}

	void update() override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.yPos = -1;
				break;
			case SDLK_a:
				transform->velocity.xPos = -1;
				break;
			case SDLK_d:
				transform->velocity.xPos = 1;
				break;
			case SDLK_s:
				transform->velocity.yPos = 1;
			default:
				break;
			}
		}
		if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.yPos = 0;
				break;
			case SDLK_a:
				transform->velocity.xPos = 0;
				break;
			case SDLK_d:
				transform->velocity.xPos = 0;
				break;
			case SDLK_s:
				transform->velocity.yPos = 0;
			default:
				break;
			}
		}
	}
};







#endif KEYBOARDCONTROLLER_H
