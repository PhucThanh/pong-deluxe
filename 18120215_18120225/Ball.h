#pragma once
#include <iostream>
#include "Console.h"
#include "Bar.h"
using namespace std;

class Ball
{
public:
	float x, y;		//vi tri hien tai
	float xp, yp;	//x previous, y previous - vi tri cu
	float xpp, ypp;//VI trí cũ cũ
	float sx, sy;	//speed x,y - toc do
	void set_Ball(int, int);	//ham tao bong, input la vi tri x,y cua bong
	void Draw(int);		//tao bong tren console, input la mau qua bong
	void ChangeSpeed(float, float);		//thay doi toc do, input la sx, sy moi cua bong
	void HitBar(Bar, Bar);		//doi huong khi bong cham vao thanh truot, input la gia tri hai thanh tren va duoi
	void HitBorder(int, int);	//doi huong khi bong cham vao bien, input la chieu rong va chieu cao cua ban do choi
	void MaxSpeed(int);			//Xu li khi bong vuot qua toc do toi da, input la max speed
};

