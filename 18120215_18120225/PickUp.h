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
		LONGER,
		SHORTER,
		SLOWER,
		AMMOES,
		LIVES,
	};
	Special  type;
	PickUp();
	void setPosition(int, int, int, int);
	void Draw();
	void PickUpHitBar(Ball&,Bar& bar);
	friend class Box;
};

