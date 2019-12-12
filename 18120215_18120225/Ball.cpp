#include "Ball.h"

void Ball::setPosition(int x1, int y1) //tao bong
{
	x = x1;  //dua gia tri x1 vao x
	y = y1;  //dua gia tri y1 vao y

	x_previous = x;         //set vi tri cu
	y_previous = y;         //set vi tri cu

	//Trait
	pastPost.resize(8);
	for (int i = 0;i < pastPost.size();i++) 
	{
		pastPost[i] = pair<float, float>(x, y);
	}
}
void Ball::Clear() 
{
	for (int i = 0;i < pastPost.size();i++) 
	{
		Graphic::Draw(round(pastPost[i].first), round(pastPost[i].second), ' ', 0);
	}
}
void Ball::Draw(int color)   //ve bong tren console
{
	//Graphic::Draw(round(x_previous), round(y_previous), ' ', 0);//Xóa vị trí cũ	
	
	//Trait
	Graphic::Draw(round(pastPost[0].first), round(pastPost[0].second), ' ', 0);//Xóa vị trí cũ
	Graphic::Draw(round(pastPost[7].first), round(pastPost[7].second), 248, 12);//Xóa vị trí cũ

	Graphic::Draw(round(x), round(y), 233, 6);//233 : hình tròn

	//Display speed
	//Graphic::DrawRec(round(x_previous)+1, round(y_previous),round(x_previous)+2,round(y_previous), ' ', 0);//Xóa vị trí cũ	
	//Graphic::DrawString(round(x) + 1, round(y), to_string(ticks), 15);

	pastPost.push_back(pair<float, float>(x, y));
	pastPost.erase(pastPost.begin());
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
			y = p2.y + 1;								//set lai vi tri cua bong o phan tren cua thanh
		}
	}
}

void Ball::HitBarBottom(Bar p) 
{
	if (y >= p.y - 1 && y <= p.y + 1)					//
	{                                                  //bong cham vao thanh truot 1
		if (x >= p.x - p.size && x <= p.x + p.size)  //
		{
			dy *= -1;	//Banh doi nguoc len
			y = p.y - 1;                              //set lai vi tri cua bong o phan tren cua thanh
			//Co 3 goc :
			//dx=3dy	: Goc ngang
			//dx=dy		: Goc 45
			//dx=dy/3	: Goc doc
			//Gioi han	: dy/3 <= dx <= 3dy
			//			: -dy/3 >= -dx >= -3dy
			//Rut gon	: dy/3 <= | dx | <= 3dy

			if (p.isMovingLeft) //bar dang di sang trai
			{
				if (dx < 0)		//Neu bar di cung huong ball thi ball di ngang nhieu hon
				{
					if(abs(dx)<abs(3*dy))
						dx *= 3;
				}
				else	//Neu bar di nguoc huong ball thi ball di doc hon
				{
					if (abs(dx) > abs(dy/3))
						dx /= 3;
				}
			}
			else if (p.isMovingRight) //bar dang di sang phai
			{
				if (dx > 0)
				{
					if (abs(dx) < abs(3 * dy))
						dx *= 3;
				}
				else
				{
					if (abs(dx) > abs(dy / 3))
						dx /= 3;
				}
		
			}

			ticks = 10 / ((float)10 + speed_level) * 60000;
			speed_level++;
			//ticks /= 1.1;
			if (abs(dx) == 3 || abs(dx)==abs(dy/3)) //Slowdown goc 45,speed up goc khac
			{
				ticks_multiply = 1.0f;
			}
			else
			{
				ticks_multiply = 0.7f;
			}
		}
	}
}
void Ball::HitSideBorder(int& width, int& height)             //bong cham bien
{
	if (x <= 1) 
	{													 //bong cham bien trai
		dx *= -1;
		x = 1.0f;										//set lai vi tri bong o trong bien
	}
	else if (x >= width - 2) 
	{													//bong cham bien phai
		dx *= -1;
		x = width - 2;                           //set lai vi tri bong o trong bien
	}
}
void Ball::HitSideTopBorder(int &width, int &height) 
{
	HitSideBorder(width, height);
	if (y <= 1) 
	{
		//sy *= -1;//Doi huong di xuong
		dy *= -1;
		y = 1.0f;
	}
}
void Ball::MaxSpeed(int v)		//Xu ly khi bong vuot qua toc do toi da
{
	if (dx > v)
	{
		dx = v;
	}
	else if (dx < -v) 
	{
		dx = -v;
	}
}
void Ball::setToPrevious() 
{
	x = x_previous;
	y = y_previous;
}