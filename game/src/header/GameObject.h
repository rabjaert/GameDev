#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>


class GameObject {
public:
	GameObject(SDL_Renderer *renderer, int x, int y) 
		: renderer(renderer), xPos(x), yPos(y) 
	{}
	GameObject()
	{}

	virtual ~GameObject();

	virtual void update() = 0;
	virtual void render();

	/* Set the SDL_Texture used for rendering */
	virtual void setTexture(const char *filename);
	virtual void setTexture(SDL_Texture *texture);

	virtual SDL_Texture *getTexture() const;

	/* Set the objects's position */
	virtual void setX(const int x);
	virtual void setY(const int y);
	virtual void setPosition(const int x, const int y);

	/* Moves the object relative to its current position */
	virtual void moveRelative(const int x, const int y);

	/* Getters for position */
	inline int getX() { return xPos; }
	inline int gety() { return yPos; }

protected:
	/* 2D position */
	int xPos, yPos;

	/* Reference to main renderer */
	SDL_Renderer * renderer;

	/* Texture loaded in constructor */
	SDL_Texture *texture = nullptr;

	/* Rects for rendering */
	SDL_Rect srcRect = {};
	SDL_Rect destRect = {};
};

#endif