#pragma once
#include "Graphic.h"
#include "Bar.h"
#include "Ball.h"
class PickUp
{
	float x, y;
	float xp, yp;
	int width;
	int height;
	int col;
	bool destroyed;
public:
	enum class Special 
	{
		NOTHING,
		EXTRA_BALL,
		LONGER,
		SHORTER,
		SLOWER,
		SPEED_UP,
		SPEED_DOWN,
		SUPER_BALL,
		GUN
	};
	Special  type;
	PickUp();
	void setPosition(int, int, int, int);
	void Draw();
	void PickUpHitBar(Ball&,Bar& bar);
	friend class Box;
};

