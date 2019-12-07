#pragma once
#include "TaskBar.h"
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
//static int run_menu();
class Menu
{
protected:
	Menu* cur;//con tro menu
	TaskBar task_menu;
	string menu_title;
	string menu_list[MAX_MENU];
	int select;
	input in;
	bool enter = false; // Kiem tra xem phim enter da bam hay chua? de khong bi skip menu (nhay 2 lan)
	int current_time = 0;//So tick den thoi gian hien tai
	bool pressed = true;//kiem tra xem phim da bam hay chua
	int pick;//he so phan biet cac menu: 0: main menu, 1: menu breaker game, 2: menu pong

public:
	Menu() {};
	~Menu() { delete[] cur; };
	//Menu* create_Menu(string);
	int get_Select();// tra ve gia tri duoc chon
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
	void DrawBlock32(int, int, int);//khoi chu
	void DrawIcon(int, int, int);//P.B
	void DrawBorder(int);//Khung game
};
class MainMenu : public Menu
{
	//bool start = false;
public:
	MainMenu();
	~MainMenu();
};
class BreakerMenu : public Menu
{
	//bool start = false;
public:
	BreakerMenu();
	~BreakerMenu();
};
class PongMenu : public Menu
{
	//bool start = false;
public:
	PongMenu();
	~PongMenu();
};
