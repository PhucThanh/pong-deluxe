#include "Menu.h"
#include "Game.h"
#include <conio.h>

int main()
{
	Animate a;
	Console console;//Constructor cài đặt console
	Graphic g;//Call the constructor of Graphic
	Game G;		//Tao bien class Game
	Menu m;		//Tao bien class Menu
	m.Intro();	//Hien intro
	int l; //de dai thoi
	do
	{
		l=m.run_Menu();	//Hien menu
			//Nhap lenh
		a.clear();
		switch (l)	//Xet gia tri moi nhap vao cua lenh
		{
		case 1:
			//Xoa menu
			Graphic::DrawRec(29, 12, 50, 19, ' ', 0);
			G.Begin();		//Bat dau tro choi PvP
			break;
		case 2:
			Graphic::DrawRec(29, 12, 50, 19, ' ', 0);
			G.BeginBOT();	//Bat dau tro choi vs BOT
			break;
		case 3:
			//m.Help();		//Huong dan choi
			break;
		}
	} while (l!=4); //Lap lai qua trinh tren neu lenh khac 4
	return 0;
}