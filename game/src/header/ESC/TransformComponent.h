#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "Components.h"
#include "../ESC/Vector2D.h"

class TransformComponent : public Component
{
public:

	Vector2D postition;
	Vector2D velocity;

	int speed = 0.001;


	TransformComponent()
	{
		postition.xPos = 0.0f;
		postition.yPos = 0.0f;
	}
	
	TransformComponent(float x, float y) {
		postition.xPos = x;
		postition.yPos = y;
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
