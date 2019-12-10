#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

//physical console size
static int console_width = 884;
static int console_height = 790;

//So luong ky tu ngang va doc
static int game_width = 72;//71 70
static int game_height = 61;
//Font chữ
static int font_x = 0;//7 10
static int font_y = 12;
class Console
{
	
public:
	int x, y;			//vi tri
	Console();				
	~Console();
	void GoToXY(int x1, int y1);	//dua con tro toi vi tri chi dinh
	void ChangeColorText(int);		//doi mau console
	void DrawConsole(int);			//tao console
	void DrawConsoleBOT(int);		//tao console khi choi voi BOT
	void HideCursor();				//xoa dau con tro
};

