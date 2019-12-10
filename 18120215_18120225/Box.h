#pragma once
#include <string>
#include "Graphic.h"
#include "Ball.h"
#include "PickUp.h"
class Box
{
protected:
	int x, y;
	int width;
	int height;
	int health;
	int col;
	bool destroyed;
	PickUp pickUp;
public:
	Box();
	void setPosition(int, int,int,int,int);//Set position
	virtual void Draw();//Draw
	virtual string getType() 
	{
		return "Box";
	}
	void PickUpHitBar(Ball&,Bar&);
	void BoxHitBall(Ball&);
	friend class BoxManager;
};

