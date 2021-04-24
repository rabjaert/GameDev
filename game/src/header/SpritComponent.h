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
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		texture = TextureManager::loadTexture(path, Game::renderer);
	}

	void init() override
	{
		position = &entity->getComponent<PositionComponent>();
		
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 64;
		destRect.w = destRect.h = 64;
	}
	
	void update() override
	{
		destRect.x = position->getX();
		destRect.y = position->getY();
	}
	
	void render() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}






};



#endif SPRITECOMPONENT_H
