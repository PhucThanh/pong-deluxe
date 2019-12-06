#include "Menu.h"
#include "Game.h"

Menu::Menu()		//Khoi tao menu
{
	//C.resizeConsole(Width_console, Height_console);	//Set gia tri cho san choi
	//C.HideCursor();		//An con tro chuot
	
}
void Menu::Intro()		//Phan intro
{
	//Draw(15);		//ve chao mung
	//Sleep(900);		//Delay de hien thi
	
	for (int i = 1;i < 16;i++) 
	{
		Draw(i);
		Sleep(70);
	}
	Draw(3);//màu teal
}
void Menu::ShowMenu()
{
	Graphic::DrawString(29, 12, "*****");
	Graphic::DrawString(29, 14, "1. P vs P");
	Graphic::goToXY(29, 21);
	cout << static_cast<char>(219);
	Graphic::DrawString(29, 15, "2. P vs BOT");
	Graphic::DrawString(29, 16, "3. HELP");
	Graphic::DrawString(29, 17, "4. EXIT");
	Graphic::DrawString(29, 18, "5. BREAKER");
}

void Menu::EnterCommand()	//Nhap lenh
{
	Graphic::DrawString(29, 19, "Your choice : [ ]");
	Graphic::Update();
	Graphic::goToXY(44, 19);
	cin >> Command;
}

void Menu::Help()		//Huong dan choi
{
	/*
	system("cls");
	Draw(15);
	C.GoToXY(Width_console / 2 - 1, Height_console / 2);
	cout << ' ';
	C.GoToXY(25, 7); cout << "HELP";
	C.GoToXY(23, 9); cout << "********";
	C.GoToXY(8, 11); C.ChangeColorText(14);
	cout << "P vs P";
	C.GoToXY(8, 12); C.ChangeColorText(15);
	cout << "Player 1: Thanh phia duoi, su dung hai phim";
	C.GoToXY(8, 13);	cout << "mui ten trai, phai de dieu khien";
	C.GoToXY(8, 14);
	cout << "Player 2: Thanh phia tren, su dung hai phim";
	C.GoToXY(8, 15);	cout << "A, D de dieu khien";
	C.GoToXY(8, 16); C.ChangeColorText(14);
	cout << "P vs BOT";
	C.GoToXY(8, 17); C.ChangeColorText(15);
	cout << "Thanh phia duoi, su dung hai phim";
	C.GoToXY(8, 18);	cout << "mui ten trai, phai de dieu khien";
	_getch();
	*/
}
void Menu::Draw(int color)		//Ve man hinh chao mung Game
{
	for (int i = 0; i < game_width; ++i)
	{
		Graphic::Draw(i, 0, static_cast<char>(219), color);//Vẽ biên trên
		Graphic::Draw(i, game_height-8, static_cast<char>(219), color);//Vẽ biên dưới
	}
	for (int i = 0; i < game_height - 1; ++i)
	{
		//Biên trái
		Graphic::Draw(0, i, static_cast<char>(219), color);
		Graphic::Draw(1, i, static_cast<char>(219), color);
		//Biên phải
		Graphic::Draw(game_width - 5, i, static_cast<char>(219), color);
		Graphic::Draw(game_width-6, i, static_cast<char>(219), color);
	}
	Graphic::DrawString(game_width / 2-10, game_height / 2-8, "Welcome to pong game !!", color);
	Graphic::Update();
	Graphic::DrawString(game_width / 2 - 10, game_height / 2 - 8, "                       ", color);//Xóa dòng
}
