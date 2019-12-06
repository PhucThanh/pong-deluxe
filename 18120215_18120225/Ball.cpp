#include "Ball.h"

void Ball::set_Ball(int x1, int y1) //tao bong
{
	x = x1;  //dua gia tri x1 vao x
	y = y1;  //dua gia tri y1 vao y

	x_previous = x;         //set vi tri cu
	y_previous = y;         //set vi tri cu
	sx = sy = 0;    //toc do ban dau

	pastPost.resize(8);//Trait
	for (int i = 0;i < pastPost.size();i++) 
	{
		pastPost[i] = pair<float, float>(x, y);
	}
}

void Ball::Draw(int color)   //ve bong tren console
{
	//Graphic::Draw(round(x_previous), round(y_previous), ' ', 0);//Xóa vị trí cũ			
	Graphic::Draw(round(pastPost[0].first), round(pastPost[0].second), ' ', 0);//Xóa vị trí cũ
	Graphic::Draw(round(pastPost[7].first), round(pastPost[7].second), 233, 12);//Xóa vị trí cũ
	
	//Graphic::Draw(round(x_previous), round(y_previous), 233, 4);//Past
	Graphic::Draw(round(x), round(y), 233, 6);//233 : hình tròn
	//Graphic::Draw(round(x_next), round(y_next), 233, 10);//Future
					  //0: moi nhat

	pastPost.push_back(pair<float, float>(x, y));
	pastPost.erase(pastPost.begin());
	
	
}
void Ball::ChangeAngle(float angle)     //thay doi toc do
{
	this->angle = angle;
	sx = sin(angle);
	sy = cos(angle);
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

void Ball::HitBarBottom(Bar p) 
{
	if (y >= p.y - 1 && y <= p.y + 1)					//
	{                                                  //bong cham vao thanh truot 1
		if (x > p.x - p.size && x < p.x + p.size)  //
		{
			dy *= -1;
			ChangeAngle(PI - angle);
			y = p.y - 1;                              //set lai vi tri cua bong o phan tren cua thanh
			//ChangeSpeed(sx * 1.1, sy * 1.1);
			if (p.isMovingLeft) 
			{
				dx -= 3;
			}
			else if (p.isMovingRight) 
			{
				dy += 3;
			}

		}
	}
}
void Ball::HitSideBorder(int& width, int& height)             //bong cham bien
{
	if (x <= 3) 
	{													 //bong cham bien trai
		//sx *= -1;										//doi huong bong
		dx *= -1;
		x = 3.0f;										//set lai vi tri bong o trong bien
	}
	else if (x >= width - 7) 
	{													//bong cham bien phai
		//sx *= -1;									    //doi huong bong
		dx *= -1;
		x = width - 7;                           //set lai vi tri bong o trong bien
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
