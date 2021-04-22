#include "header/GameObject.h"

#include "header/TextureManager.h"


GameObject::~GameObject()
{
	TextureManager::disposeTexture(texture);
}

void GameObject::setTexture(const char* filename)
{
	this->texture = TextureManager::loadTexture(filename, renderer);
}

void GameObject::setTexture(SDL_Texture *texture)
{
	this->texture = texture;
}

SDL_Texture* GameObject::getTexture() const
{
	return this->texture;
}


void GameObject::render()
{
	SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
};

void GameObject::setX(const int x) {
	xPos = x;
}

void GameObject::setY(const int y) {
	yPos = y;
}

void GameObject::setPosition(const int x, const int y)
{
	setX(x);
	setY(y);
}

void GameObject::moveRelative(const int x, const int y)
{
	setX(xPos + x);
	setY(yPos + y);
}