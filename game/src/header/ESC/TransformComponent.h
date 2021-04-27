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

	int srcX = 0;
	int srcY = 0;


	int speed = 3;


	TransformComponent()
	{
		postition.Zero();
	}

	TransformComponent(int sc) {
		postition.Zero();
		scale = sc;
	}
	
	TransformComponent(float x, float y) {
		postition.Zero();
	}

	TransformComponent(float x, float y, int h, int w, int sc) {
		postition.xPos = x;
		postition.yPos = y;
		height = h;
		width = w;
		scale = sc;

	}

	TransformComponent(float x, float y, int h, int w, int srcXi, int srcYi, int sc) {
		postition.xPos = x;
		postition.yPos = y;
		height = h;
		width = w;
		srcX = srcXi;
		srcY = srcYi;
		scale = sc;

	}
	
	

	void init() override
	{
		velocity.Zero();
	}

	void update() override
	{
		postition.xPos += static_cast<int>(velocity.xPos * speed);
		postition.yPos += static_cast<int>(velocity.yPos * speed);
	}



};

#endif POSITIONCOMPONENT_H
