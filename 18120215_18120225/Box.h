#pragma once
#include <string>
#include "Graphic.h"
#include "Ball.h"
class Box
{
protected:
	int x, y;
	int width;
	int height;
	int health;
	bool destroyed;
public:
	Box();
	void setPosition(int, int,int,int,int);//Set position
	void Draw(int);//Draw with color
	void BoxHitBall(Ball&);
	friend class BoxManager;
};

