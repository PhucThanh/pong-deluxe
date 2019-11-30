#pragma once
#include "Game.h"
#include "Graphic.h"

class Menu
{
private:
	//Console C;
public:
	int Command;	//Bien lenh do nguoi dung nhap
	Menu();			//constructor
	void Intro();	//Phan intro gioi thieu
	void ShowMenu();	//Hien thi menu
	void EnterCommand();	//Nhap lenh
	void Help();		//Hien thi huong dan choi
	void Draw(int color);
};	

