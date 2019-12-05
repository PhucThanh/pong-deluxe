#pragma once

#include "Animate.h"
//#include <vector>
#include <string>
#define MAX_MENU 4
#define TOP_LEFT static_cast<char>(201)
#define TOP_RIGHT static_cast<char>(187)
#define BOT_LEFT static_cast<char>(200)
#define BOT_RIGHT static_cast<char>(188)
#define ROW static_cast<char>(205)
#define COL static_cast<char>(186)
#define BLOCK static_cast<char>(219)
#define BLOCK_COLOR 205
#define SELECT_COLOR 6
#define DESELECT_COLOR 7
enum input { UP, DOWN, ENTER, NONE };
class Menu
{
	Animate a;
	string menu_title;
	string menu_list[MAX_MENU];
	int select;
	input in;
	int current_time = 0;//So tick den thoi gian hien tai
	bool pressed = false;
public:
	Menu();
	~Menu();
	//ham goi thuc hien menu
	int run_Menu();
	//tuong tac menu
	input GetKey();
	void update_Menu(input);
	//hien thi menu
	void DrawMenu();
	void DrawSelectMenu();
	//trang tri
	void Intro();
	void DrawBlock32(int, int, int);
	void DrawIcon(int, int, int);
	void DrawBorder(int);
};

