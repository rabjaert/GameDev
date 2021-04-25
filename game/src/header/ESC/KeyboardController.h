#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H


#include "../game.h"
#include "EntityComponent.h"
#include "Components.h"

class KeyboardController : public Component
{

public:
	TransformComponent* transform;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		//sprite = &entity->getComponent<SpriteComponent>();

	}

	void update() override
	{

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

		Game::event;

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
		}
		
	



		//transform->velocity.xPos = 0;
		
		/*else {
			transform->velocity.xPos = 0;
			transform->velocity.yPos = 0;
		}
		*/

		

			

		
		/*
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				std::cout << "w pressed" << std::endl;
				transform->velocity.yPos = -1;
				break;
			case SDLK_a:
				std::cout << "a pressed" << std::endl;
				transform->velocity.xPos = -1;
				break;
			case SDLK_d:
				std::cout << "d pressed" << std::endl;
				transform->velocity.xPos = 1;
				break;
			case SDLK_s:
				std::cout << "s pressed" << std::endl;
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
		}*/
	}
};







#endif KEYBOARDCONTROLLER_H
