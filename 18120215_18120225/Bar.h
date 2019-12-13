#pragma once
#include "Graphic.h"
//#include "Ball.h"
using namespace std;

class Bar
{
	
public:
	bool isMovingLeft;
	bool isMovingRight;
	float x, y;			//vi tri hien tai
	float xp, yp;		//previous x,y - vi tri cu
	float sx;			//speed x - toc do
	int size;			//chieu dai thanh truot

	int ammoes=0;

	int lives = 3;

	//Ball bullet;

	void Draw(int);		//ve thanh truot tren console
	void setPosition(int, int, int);	//tao thanh truot
	void GetKey(int, int);			//nhan tin hieu ban phim
	void HitBorder(int);		//thanh truot cham bien
	void Shoot();
};

