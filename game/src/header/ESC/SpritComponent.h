#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component
{

private:
	TransformComponent* transform;
	SDL_Texture* texture;

	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTex(path);
	}

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 64;
		destRect.w = destRect.h = 64;
	}
	
	void update() override
	{
		destRect.x = (int)transform->postition.xPos;
		destRect.y = (int)transform->postition.yPos;
	}
	
	void render() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}

	void setTex(const char* path) {
		texture = TextureManager::loadTexture(path, Game::renderer);
	}




};



#endif SPRITECOMPONENT_H
