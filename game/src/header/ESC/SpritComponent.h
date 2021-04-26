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
	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		
		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	
	}
	
	void update() override
	{
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




};



#endif SPRITECOMPONENT_H
