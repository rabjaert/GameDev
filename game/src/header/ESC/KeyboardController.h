#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H


#include "../game.h"
#include "EntityComponent.h"
#include "Components.h"

class KeyboardController : public Component
{

public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();

	}

	void update() override
	{

		
		transform->velocity.xPos = 0;
		transform->velocity.yPos = 0;
		
		auto* state = SDL_GetKeyboardState(NULL);
		if (state[SDL_SCANCODE_W]) {
			transform->velocity.yPos = -1;
		}
		if (state[SDL_SCANCODE_A]) {
			transform->velocity.xPos = -1;
		}


		if (state[SDL_SCANCODE_D]) {
			transform->velocity.xPos = 1;
		}

		if (state[SDL_SCANCODE_S]) {
			transform->velocity.yPos = 1;
		}
		
		

		/*Game::event;

		if (Game::event.type == SDL_KEYUP) {
			if (Game::event.key.keysym.scancode == SDL_SCANCODE_W) {

				transform->velocity.yPos = 0;
			}
			if (Game::event.key.keysym.scancode == SDL_SCANCODE_A)
			{

				transform->velocity.xPos = 0;
			}
			if (Game::event.key.keysym.scancode == SDL_SCANCODE_D)
			{
				transform->velocity.xPos = 0;
			}
			if (Game::event.key.keysym.scancode == SDL_SCANCODE_S)
			{
				transform->velocity.yPos = 0;
			}
	}*/
	}

};







#endif KEYBOARDCONTROLLER_H
