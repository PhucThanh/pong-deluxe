#pragma once
#include <Windows.h>
#include "Console.h"//For size only
class Graphic//Quan ly draw
{
	static CHAR_INFO* m_bufScreen;//Con tro tuong duong voi tung pixel
	static SMALL_RECT m_rectWindow;//Kich thuoc console
public:
	Graphic();
	static void Update();//Update m_bufScreen vào console
	static void ClearScr();
	static void Draw(int , int , short, short);//Vẽ char c tại điểm x,y màu col
	static void DrawString(int, int, string, short col = 0x000F);//vẽ string tại x,y, màu col
	static void DrawRec(int, int, int, int, short, short);//Ve hình chữ nhật với các tọa độ
	static void goToXY(int, int);
};

