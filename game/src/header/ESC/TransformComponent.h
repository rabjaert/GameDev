#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "Components.h"
#include "../ESC/Vector2D.h"

class TransformComponent : public Component
{
public:

	Vector2D postition;

	TransformComponent()
	{
		postition.xPos = 0.0f;
		postition.yPos = 0.0f;
	}
	
	TransformComponent(float x, float y) {
		postition.xPos = x;
		postition.yPos = y;
	}



	void update() override
	{
		
	}



};

#endif POSITIONCOMPONENT_H
