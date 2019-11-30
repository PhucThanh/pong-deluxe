#include "Bar.h"

void Bar::set_Bar(int x1, int y1, int size1)   //tao thanh truot
{
	x = float(x1);           //dua gia tri x1 vao x
	y = float(y1);           //dua gia tri y1 vao y
	xp = x;                  //set vi tri cu
	yp = y;                  //set vi tri cu
	sx = 0;                  //toc do ban dau
	size = size1;            //dua gia tri size1 vao size
}
void Bar::Draw(int color)             //ve thanh truot
{
	//for (int i = -size; i < size; ++i) 
	//{								 
		//Graphic::Draw(int(xp) + i, int(yp), ' ', color);
	//}                                  //
	Graphic::DrawRec(int(xp) - size, int(yp), int(xp) + size-1, int(yp),' ',0); //xoa vi tri cu

	//for (int i = -size; i < size; ++i) //
		//Graphic::Draw(int(x)+i, int(y), 219, color);
	Graphic::DrawRec(int(x) - size, int(y), int(x) + size-1, int(y), 219, 4); //ve thanh truot
	xp = x;                       
	yp = y;                            //set lai vi tri cu
}
void Bar::GetKey(int left, int right)  //nhan tin hieu ban phim
{
	if (GetAsyncKeyState(left))        //phim mui ten trai
	{
		x -= 3;						   //thanh truot di chuyen sang trai
	}
	else if (GetAsyncKeyState(right)) //phim mui ten phai
	{
		x += 3;						   //thanh truot di chuyen sang phai
	}

}

void Bar::HitBorder(int width)	//thanh truot cham bien
{
	if (x < size + 2)						//thanh truot cham bien trai
	{					
		x = float(size + 2);				//thanh truot o nguyen vi tri
	}
	else if (x > width - size - 6)			//thanh truot cham bien phai
	{
		x = float(width - size - 6);		//thanh truot o nguyen vi tri
	}

}