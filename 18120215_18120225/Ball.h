#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "Bar.h"
using namespace std;
#define PI 3.14159265358979323846
class Ball
{
public:
	float x, y;		//vi tri hien tai
	
	//Nhung bien nay quan ly di chuyen
	int steps;	// steps = max(dx,dy).
	int damage = 1;
	int dx, dy;	// dy/dx chinh la he so goc di chuyen
	float Xinc;	//So buoc x di trong 1 tick
	float Yinc;	//So buoc y di trong 1 tick

	int speed_level = 0;

	float sx, sy;

	int ticks;
	float ticks_multiply = 1.0f;

	int x_previous, y_previous;	//x previous, y previous - vi tri cu

	vector<pair<float, float>> pastPost;//Trait

	void setPosition(int, int);	//ham tao bong, input la vi tri x,y cua bong
	virtual void Draw(int);		//tao bong tren console, input la mau qua bong
	void Clear();//Clear ball and trait
	void HitBar(Bar, Bar);		//doi huong khi bong cham vao thanh truot, input la gia tri hai thanh tren va duoi
	void HitSideBorder(int&, int&);	//doi huong khi bong cham vao bien, input la chieu rong va chieu cao cua ban do choi
	void MaxSpeed(int);			//Xu li khi bong vuot qua toc do toi da, input la max speed
	void HitBarBottom(Bar);
	void HitBarTop(Bar);
	void HitSideTopBorder(int&, int&);
	void setToPrevious();//Set current position to previous
};

