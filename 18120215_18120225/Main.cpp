﻿#include "Menu.h"
#include "Game.h"
#include "GameBreaker.h"
#include <conio.h>
#include "Score.h"
int main()
{

	Console console;//Constructor cài đặt console
	Graphic g;	//Call the constructor of Graphic
	Game G;		//Tao bien class Game
	GameBreaker GB;	//Game Breaker
	Menu m;		//Tao bien class Menu
	Score s;
	
	//TaskBar t;
	//t.draw_TaskBar();
	//m.run_Menu();
	//m.Intro();	//Hien intro
	int l; //de dai thoi
	
	do
	{
		
		l = m.run_Menu();	//Hien menu
		Graphic::ClearScr();
		switch (l)	//Xet gia tri moi nhap vao cua lenh
		{
		case 11:
			//Xoa menu
			//Graphic::DrawRec(29, 12, 50, 19, ' ', 0);
			//G.Begin();
			//s.draw_Score(75, 40, 12);//Bat dau tro choi PvP
			GB.Begin();
			
			break;
		case 12:
			system("pause");
			break;
		case 21:
			G.Begin();
			break;
		case 22:
			//Graphic::DrawRec(29, 12, 50, 19, ' ', 0);
			G.BeginBOT();	//Bat dau tro choi vs BOT
			break;
		
			
		
		}
	} while (l!=4); //Lap lai qua trinh tren neu lenh khac 4*/
	return 0;
}
