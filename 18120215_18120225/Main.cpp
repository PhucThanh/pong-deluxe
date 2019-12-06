#include "Menu.h"
#include "Game.h"
#include "GameBreaker.h"
#include <conio.h>

int main()
{

	Console console;//Constructor cài đặt console

	Graphic g;	//Call the constructor of Graphic

	Game G;		//Tao bien class Game

	GameBreaker GB;	//Game Breaker

	Menu m;		//Tao bien class Menu
	m.Intro();	//Hien intro
	int l; //de dai thoi
	do
	{
		l=m.run_Menu();	//Hien menu
			//Nhap lenh
		Graphic::ClearScr();
		switch (l)	//Xet gia tri moi nhap vao cua lenh
		{
		case 0:
			//Xoa menu
			//Graphic::DrawRec(29, 12, 50, 19, ' ', 0);
			//G.Begin();		//Bat dau tro choi PvP
			GB.Begin();
			break;
		case 1:
			G.Begin();
			break;
		case 2:
			//Graphic::DrawRec(29, 12, 50, 19, ' ', 0);
			G.BeginBOT();	//Bat dau tro choi vs BOT
			break;
		case 3:
			//m.Help();		//Huong dan choi
			break;
		}
	} while (l!=4); //Lap lai qua trinh tren neu lenh khac 4
	return 0;
}