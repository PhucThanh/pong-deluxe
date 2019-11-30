#include "Game.h"
Game::Game()
{
	start = false;		//game chua bat dau
	p1.set_Bar(game_width / 2, game_height - 15, 8);	//tao thanh truot 1
	p2.set_Bar(game_width / 2, 10, 8);			//tao thanh truot 2
	b.set_Ball(game_width / 2 - 1, game_height / 2);	//tao bong
	score1 = 0;			//diem ban dau
	score2 = 0;
}

void Game::Restart()	//choi lai
{
	b.x = float(game_width / 2 - 1);	//set lai vi tri bong
	b.y = float(game_height / 2);
	p1.x = p2.x = float(game_width / 2);	//set lai vi tri thanh truot
	b.ChangeSpeed(float(rand() % 3) - 1.5f, 1);	//thay doi toc do, tro lai ban dau
	start = false;		//game chua bat dau
	//C.GoToXY(0, Height_console + 1);	//dua con tro toi vi tri bien duoi
	//cout << endl << " \t  " << score1 << " \t\t\t   " << score2 << endl;	//update bang diem
}

void Game::Win()	//xu li thang thua
{
	if (int(b.y) >= game_height) //bong cham bien duoi
	{
		++score2;	//cong diem player 2
		Restart();	//choi lai
	}
	else if (int(b.y) <= 1) //bong cham bien tren
	{
		++score1;	//cong diem player 2
		Restart();	//choi lai
	}
}

void Game::BeforeStart(bool& Check)	//man hinh truoc khi bat dau choi
{
	//C.GoToXY(int(Width_console / 2 - 12), int(Height_console / 1.5f));	//dua con tro toi giua man hinh
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2)+3, "Press any key to start");
	//C.GoToXY(int(Width_console / 2 - 12), int(Height_console / 1.5f) + 1);
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2)+4, "Press ESC to exit");
	if (GetAsyncKeyState(VK_SPACE))		//nhan phim space
	{
		//Xoa Text Press any key...
		Graphic::DrawRec(game_width / 2 - 12, int(game_height / 2)+3, game_width / 2 - 12+21, int(game_height / 2)+4, ' ', 0);
		start = true;	//game bat dau
	}
	if (GetAsyncKeyState(VK_ESCAPE))	//Nhan phim ESC
	{
		Graphic::DrawRec(game_width / 2 - 12, int(game_height / 2) + 3, game_width / 2 - 12 + 21, int(game_height / 2) + 4, ' ', 0);
		Check = false;	// Ket thuc
	}
}

void Game::Begin()	//khoi dong game
{
	score1 = 0;		//set lai diem ve 0
	score2 = 0;
	//C.DrawConsole(15);	//tao console
	b.ChangeSpeed(1, 1);		//set toc do lai ban dau
	bool Check = true;	//Bien kiem tra xem nguoi choi co muon thoat game hay khong
	int timeSinceBegin = 0;
	while (Check)
	{
		current_time = GetTickCount();
		if (current_time > timeSinceBegin)
		{
			if (start)	//game bat dau
			{
				p1.GetKey(VK_LEFT, VK_RIGHT);	//phim dieu khien thanh truot 1
				p2.GetKey(65, 68);				//phim dieu khien thanh truot 2
				b.MaxSpeed(2);					//Xu ly max speed
				p1.HitBorder(game_width);			//thanh truot 1 cham bien
				p2.HitBorder(game_width);			//thanh truot 2 cham bien
				b.x += b.sx;					//thay doi vi tri bong
				b.y += b.sy;
				b.HitBar(p1, p2);				//bong cham thanh truot
				b.HitBorder(game_width, game_height);			//bong cham bien
				Win();							//xu li thang thua
			}
			else
			{
				BeforeStart(Check);				//Man hinh truoc khi game bat dau
			}
			p1.Draw(bar_color);							//tao thanh truot 1
			p2.Draw(bar_color);							//tao thanh truot 2
			b.Draw(ball_color);							//tao bong
			Graphic::Update();
			timeSinceBegin = current_time+25;
		}
		
	}
}

void Game::BeginBOT()		//Tuong tu ben tren
{
	score1 = 0;
	score2 = 0;
	//C.DrawConsoleBOT(15);
	int timeSinceBegin = 0;
	b.ChangeSpeed(float(rand() % 3) - 1.5f, 0.5);
	bool Check = true;
	while (Check)
	{
		current_time = GetTickCount();
		if (current_time > timeSinceBegin)
		{
			if (start)
			{
				p1.GetKey(VK_LEFT, VK_RIGHT);
				p2.sx -= float(p2.x - b.x) / 10.0f;		//Cho thanh truoc cua BOT doan huong di chuyen cua bong
				p2.sx *= 0.83f;		//Thay doi toc do thanh truot BOT
				p2.x += p2.sx;		//Thay doi vi tri thanh truoc BOT
				b.MaxSpeed(2);
				p1.HitBorder(game_width);			//thanh truot 1 cham bien
				p2.HitBorder(game_width);			//thanh truot 2 cham bien
				b.x += b.sx;
				b.y += b.sy;
				b.HitBar(p1, p2);
				b.HitBorder(game_width, game_height);
				Win();
			}
			else
			{
				BeforeStart(Check);
			}
			p1.Draw(bar_color);
			p2.Draw(bar_color);
			b.Draw(ball_color);
			Graphic::Update();
			timeSinceBegin = current_time + 25;
		}
	}
}

void Game::Draw(int color)		//Ve man hinh chao mung Game
{
	//C.DrawConsole(color);		//Tao console
	//C.GoToXY(0, Height_console + 1);			//Xoa bang diem phia duoi
	for (int i = 0; i < console_width + 1; ++i)
		cout << ' ';
	cout << endl;
	for (int i = 0; i < console_width + 1; ++i)
		cout << ' ';
	p1.Draw(color);			//Tao thanh truot 1
	p2.Draw(color);			//Tao thanh truot 2
	//C.GoToXY(15, int(Height_console / 2));
	//C.ChangeColorText(color);		//Cau chao mung
	cout << "WELCOME TO BALL BAR GAME!!!";
}

