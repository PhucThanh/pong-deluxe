#include "Bar.h"

void Bar::setPosition(int x1, int y1, int size1)   //tao thanh truot
{
	isMovingLeft = isMovingRight = false;
	x = float(x1);           //dua gia tri x1 vao x
	y = float(y1);           //dua gia tri y1 vao y
	xp = x;                  //set vi tri cu
	yp = y;                  //set vi tri cu
	sx = 0;                  //toc do ban dau
	size = size1;            //dua gia tri size1 vao size
}
void Bar::Draw(int color)             //ve thanh truot
{
	Graphic::DrawRec(int(xp) - size, int(yp), int(xp) + size-1, int(yp),' ',0); //xoa vi tri cu
	Graphic::DrawRec(int(x) - size, int(y), int(x) + size-1, int(y), 219, 4); //ve thanh truot
	xp = x;                       
	yp = y;                            //set lai vi tri cu
}
void Bar::GetKey(int left, int right)  //nhan tin hieu ban phim
{
	if (GetAsyncKeyState(left))        //phim mui ten trai
	{
		isMovingLeft = true;
	}
	else 
	{
		isMovingLeft = false;
	}
	
	if (GetAsyncKeyState(right)) //phim mui ten phai
	{
		isMovingRight = true;
	}
	else
	{
		isMovingRight = false;
	}
	if (isMovingLeft)
		x -= 2;
	if (isMovingRight)
		x += 2;
}

void Bar::HitBorder(int width)	//thanh truot cham bien
{
	if (x < size+1)						//thanh truot cham bien trai
	{					
		x = float(size+1);				//thanh truot o nguyen vi tri
	}
	else if (x > width - size-1)			//thanh truot cham bien phai
	{
		x = float(width - size-1);		//thanh truot o nguyen vi tri
	}

}
void Bar::Shoot() 
{
	
}