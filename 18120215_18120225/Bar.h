#pragma once
#include <iostream>
#include "Graphic.h"
#include "Console.h"
using namespace std;

class Bar
{
public:
	float x, y;			//vi tri hien tai
	float xp, yp;		//previous x,y - vi tri cu
	float sx;			//speed x - toc do
	int size;			//chieu dai thanh truot
	void Draw(int);		//ve thanh truot tren console
	void set_Bar(int, int, int);	//tao thanh truot
	void GetKey(int, int);			//nhan tin hieu ban phim
	void HitBorder(int);		//thanh truot cham bien
};

