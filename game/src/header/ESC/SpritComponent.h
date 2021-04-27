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
	
	std::map<const char*, Animation> animations;
	
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
		Animation walk = Animation(2, 4, 75);

		animations.emplace("Idle", idle);
		animations.emplace("Walk", walk);
		
		Play("Walk");

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
		
		//srcRect.x = transform->srcX;
		srcRect.y = animIndex * transform->srcY;
		
		destRect.x = static_cast<int>(transform->postition.xPos);
		destRect.y = static_cast<int>(transform->postition.yPos);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
		
	}
	
	void render() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
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





};



#endif SPRITECOMPONENT_H
