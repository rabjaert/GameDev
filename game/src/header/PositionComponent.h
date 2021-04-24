#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "Components.h"


class PositionComponent : public Component
{
private:
	int xPos;
	int yPos;

public:
	
	PositionComponent()
	{
		xPos = 0;
		yPos = 0;
	}
	
	PositionComponent(int x, int y) {
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
