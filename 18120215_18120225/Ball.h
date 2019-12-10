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
	int steps;
	int dx, dy;
	int ticks;
	int x_previous, y_previous;	//x previous, y previous - vi tri cu
	double sx, sy;	//speed x,y - toc do

	double angle;

	vector<pair<float, float>> pastPost;

	void set_Ball(int, int);	//ham tao bong, input la vi tri x,y cua bong
	void Draw(int);		//tao bong tren console, input la mau qua bong
	void HitBar(Bar, Bar);		//doi huong khi bong cham vao thanh truot, input la gia tri hai thanh tren va duoi
	void HitSideBorder(int&, int&);	//doi huong khi bong cham vao bien, input la chieu rong va chieu cao cua ban do choi
	void MaxSpeed(int);			//Xu li khi bong vuot qua toc do toi da, input la max speed
	void HitBarBottom(Bar);
	void HitSideTopBorder(int&, int&);
	void setToPrevious();//Set current position to previous
};

