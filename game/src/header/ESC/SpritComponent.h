#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Components.h"
#include "SDL.h"
#include "Animation.h"
#include <map>
#include <iostream>

class SpriteComponent : public Component
{

private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;

	


public:
	
	int animIndex = 0;
	bool walkUpwards;
	bool walkDownwards;
	
	std::map<const char*, Animation> animations;
	

	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
	
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTex(path);
	}

	SpriteComponent(const char* path, bool isAnimated)
	{
		animated = isAnimated;
		
		Animation idle = Animation(0, 1, 500);
		//Animation idle = Animation(0, 0, 100);
		//Animation walk = Animation(2, 5, 75);
		Animation walk = Animation(2, 5, 100);
		Animation walkUp = Animation(0, 5, 100);
		Animation walkDown = Animation(1, 5, 100);
		

		animations.emplace("Idle", idle);
		animations.emplace("Walk", walk);
		animations.emplace("Walkup", walkUp);
		animations.emplace("Walkdown", walkDown);
		
		
		Play("Walk");
		//PlayUp("Walkup");
		//PlayDown("Walkdown");
	

		setTex(path);
	}
	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		
		srcRect.x = transform->srcX;
		srcRect.y = transform->srcY;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	
	}
	
	
	void update() override
	{
		
		
		if (animated) 
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);	
		}
		
		if (walkUpwards == true) 
		{

			srcRect.y = animIndex * transform->srcY;
				srcRect.h = transform->height;
				

				destRect.x = static_cast<int>(transform->postition.xPos);
				destRect.y = static_cast<int>(transform->postition.yPos);
				destRect.w = transform->width * transform->scale;
				destRect.h = transform->height * transform->scale;
				std::cout << "W" << std::endl;
		}


		if (walkDownwards == true)
		{

			srcRect.y = animIndex * transform->srcY - 40;
			srcRect.h = transform->height - 8;

			destRect.x = static_cast<int>(transform->postition.xPos);
			destRect.y = static_cast<int>(transform->postition.yPos);
			destRect.w = transform->width * transform->scale;
			destRect.h = transform->height * transform->scale;
			std::cout << "A" << std::endl;
		}
		else 
		{
			srcRect.y = animIndex * transform->srcY;
			destRect.x = static_cast<int>(transform->postition.xPos);
			destRect.y = static_cast<int>(transform->postition.yPos);
			destRect.w = transform->width * transform->scale;
			destRect.h = transform->height * transform->scale;
		}

	}

	
	void render() override
	{
		TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
	}

	void setTex(const char* path) {
		texture = TextureManager::loadTexture(path, Game::renderer);
	}

	void Play(const char* animationName)
	{
		frames = animations[animationName].frames;
		animIndex = animations[animationName].index;
		speed = animations[animationName].speed;
	}

	void PlayUp(const char* animationUp) {
		frames = animations[animationUp].frames;
		animIndex = animations[animationUp].index;
		speed = animations[animationUp].speed;
	}
	void PlayDown(const char* animationDown) {
		frames = animations[animationDown].frames;
		animIndex = animations[animationDown].index;
		speed = animations[animationDown].speed;
	}

};



#endif SPRITECOMPONENT_H
