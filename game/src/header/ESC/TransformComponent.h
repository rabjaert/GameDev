#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "Components.h"
#include "../ESC/Vector2D.h"

class TransformComponent : public Component
{
public:

	Vector2D postition;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	int xPosInDestRect = 0;
	int yPosInDestRect = 0;

	int speed = 3;


	TransformComponent()
	{
		postition.xPos = 0.0f;
		postition.yPos = 0.0f;
	}

	TransformComponent(int sc) {
		postition.xPos = 0.0f;
		postition.yPos = 0.0f;
		scale = sc;
	}
	
	TransformComponent(float x, float y) {
		postition.xPos = x;
		postition.yPos = y;
	}

	TransformComponent(float x, float y, int h, int w, int sc) {
		postition.xPos = x;
		postition.yPos = y;
		height = h;
		width = w;
		scale = sc;

	}
	
	TransformComponent(float x, float y, int h, int w, int posXinDestRect, int posYinDestRect, int sc) {
		postition.xPos = x;
		postition.yPos = y;
		height = h;
		width = w;
		xPosInDestRect = posXinDestRect;
		yPosInDestRect = posYinDestRect;
		scale = sc;

	}

	void init() override
	{
		velocity.xPos = 0;
		velocity.yPos = 0;
	}

	void update() override
	{
		postition.xPos += velocity.xPos * speed;
		postition.yPos += velocity.yPos * speed;
	}



};

#endif POSITIONCOMPONENT_H
