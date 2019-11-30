#include "Ball.h"

void Ball::set_Ball(int x1, int y1) //tao bong
{
	x = float(x1);  //dua gia tri x1 vao x
	y = float(y1);  //dua gia tri y1 vao y
	xp = x;         //set vi tri cu
	yp = y;         //set vi tri cu
	xpp = xp;	//set vi tri cu 2
	ypp = ypp;//set vi tri cu 2
	sx = sy = 0;    //toc do ban dau
}

void Ball::Draw(int color)   //ve bong tren console
{

	Graphic::Draw(round(xp), round(yp), ' ', 0);//Xóa vị trí cũ

	Graphic::Draw(round(x), round(y), 233, color);//233 : hình tròn

	xpp = xp;
	ypp = yp;
	xp = x;                     //set lai vi tri cu
	yp = y;                     //set lai vi tri cu
}
void Ball::ChangeSpeed(float vx, float vy)     //thay doi toc do
{
	sx = vx;
	sy = vy;
}
void Ball::HitBar(Bar p1, Bar p2)    //doi huong khi cham vao thanh truot
{
	if (y >= p1.y - 1 && y <= p1.y + 1)					//
	{                                                  //bong cham vao thanh truot 1
		if (x > p1.x - p1.size && x < p1.x + p1.size)  //
		{
			sy *= -1;                                  //doi huong bong
			//sx += float(x - p1.x) / 3;                 //
			y = p1.y - 1;                              //set lai vi tri cua bong o phan tren cua thanh
			//ChangeSpeed(sx * 1.1, sy * 1.1);
		}
	}
	if (y <= p2.y + 1 && y >= p2.y - 1)					//
	{                                                   //bong cham vao thanh truot 2
		if (x > p2.x - p2.size && x < p2.x + p2.size)   //
		{
			sy *= -1;                                   //doi huong bong
			//sx += float(x - p2.x) / 3;					//
			y = p2.y + 1;								//set lai vi tri cua bong o phan tren cua thanh
			//ChangeSpeed(sx * 1.1, sy * 1.1);
		}
	}
}
void Ball::HitBorder(int width, int height)             //bong cham bien
{
	if (x <= 3) 
	{													 //bong cham bien trai
		sx *= -1;										//doi huong bong
		x = 3.0f;										//set lai vi tri bong o trong bien
	}
	else if (x >= width - 7) 
	{													//bong cham bien phai
		sx *= -1;									    //doi huong bong
		x = float(width - 7);                           //set lai vi tri bong o trong bien
	}
}

void Ball::MaxSpeed(int v)		//Xu ly khi bong vuot qua toc do toi da
{
	if (sx < -v)			//So sanh toc do hien tai voi v
	{
		sx = -v;					// Cho toc do bang v
	}
	else if (sx > v)
	{
		sx = v;
	}
	if (sy < -v)			//So sanh toc do hien tai voi v
	{
		sy = -v;					// Cho toc do bang v
	}
	else if (sy > v)
	{
		sy = v;
	}
}
