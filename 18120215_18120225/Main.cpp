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
	//TaskBar t;
	//t.draw_TaskBar();
	//m.run_Menu();
	//m.Intro();	//Hien intro
	int l; //de dai thoi
	do
	{
		l=m.run_Menu();	//Hien menu
			//Nhap lenh
		Graphic::ClearScr();
		switch (l)	//Xet gia tri moi nhap vao cua lenh
		{
		case 11:
			//Game Breaker
			GB.Begin();
			break;
		case 12:
			//Game Breaker Bot
			system("pause");
			break;
		case 21:
			//Pong pvp
			G.Begin();
			break;
		case 22:
			//Pong pve
			G.BeginBOT();
			break;
		
		}
	} while (l!=4); //Lap lai qua trinh tren neu lenh khac 4*/
	return 0;
}
