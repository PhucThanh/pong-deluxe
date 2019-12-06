#include "Menu.h"
#include <conio.h>
#include <io.h>
#include <fcntl.h>

#include "GameBreaker.h"//to test only
int main()
{
	//_setmode(_fileno(stdout), _O_WTEXT);

	Console console;//Constructor cài đặt console
	Graphic g;//Call the constructor of Graphic
	srand(time(NULL));
	




	//Box bo;
	//bo.setPosition(20, 35, 3);
	//Ball b;
	//b.set_Ball(25 + 5, 40 + 3);
	//

	//b.ChangeSpeed(-1, -1);
	//while (1)
	//{
	//	b.x += b.sx;					//thay doi vi tri bong
	//	b.y += b.sy;

	//	//Future predict for collision with box
	//	b.xn = b.x + b.sx;
	//	b.yn = b.y + b.sy;
	//	b.Draw(3);
	//	bo.Draw(3);
	//	bo.BoxHitBall(b);
	//	Graphic::Update();
	//	Sleep(350);
	//}



	Graphic::Update();
	Game G;		//Tao bien class Game PONG
	GameBreaker GB;//Tao bien class Game Breaker
	Menu m;		//Tao bien class Menu
	m.Intro();	//Hien intro
	do
	{
		m.ShowMenu();	//Hien menu
		m.EnterCommand();	//Nhap lenh
		switch (m.Command)	//Xet gia tri moi nhap vao cua lenh
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
			m.Help();		//Huong dan choi
		case 5:
			Graphic::DrawRec(29, 12, 50, 19, ' ', 0);
			GB.Begin();
			break;
		}
	} while (m.Command!=4); //Lap lai qua trinh tren neu lenh khac 4
	return 0;
}