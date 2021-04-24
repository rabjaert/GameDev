#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "Components.h"


class TransformComponent : public Component
{
private:
	int xPos;
	int yPos;

public:
	
	TransformComponent()
	{
		xPos = 0;
		yPos = 0;
	}
	
	TransformComponent(int x, int y) {
		setPos(x, y);
	}



	void update() override
	{
		xPos++;
		yPos++;
	}

	int getX() { return xPos; }
	int getY() { return yPos; }
	
	void setX(int x) { xPos = x; }
	void setY(int y) { yPos = y; }

	void setPos(int x, int y) {
		xPos = x;
		yPos = y;
	}


};

#endif POSITIONCOMPONENT_H
