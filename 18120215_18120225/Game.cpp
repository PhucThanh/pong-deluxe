#include "Game.h"
Game::Game()
{
	playing = false;		//game chua bat dau
	p1.setPosition(game_width / 2, game_height - 15, 8);	//tao thanh truot 1
	p2.setPosition(game_width / 2, 10, 8);			//tao thanh truot 2
	b.setPosition(game_width / 2 - 1, game_height / 2);	//tao bong
	score1 = 0;			//diem ban dau
	score2 = 0;
}

void Game::Restart()	//choi lai
{
	//Remove player WON
	Graphic::DrawString(game_width / 3 + 1, game_height, "            ", 4);


	ball_pause = true;	//Pause the ball
	playing = false;	//Game chua bat dau

	//Khoi tao lai cac thong so cho ball
	b.Clear();
	b.setPosition(game_width / 2 - 1, game_height/2);	//Set bong o giua san
	b.ticks = 60000;	//Reset ball ticks
	b.ticks_multiply = 1.0f;
	b.speed_level = 0;	//Reset speed level
	b.dx = 3;	//Ball's direction
	b.dy = -3;	//Ball's direction
}

void Game::Win()	//xu li thang thua
{
	
	
	
	if (int(b.y) >= game_height-3) //bong cham bien duoi
	{
		++score2;	//cong diem player 2
		Graphic::DrawString(game_width * 2 / 3 + 11, game_height, to_string(score2), 4);
		
		if (score2 == 3) 
		{
			Graphic::DrawString(game_width / 3 + 1, game_height, "PLAYER 2 WIN", 4);
			playing = false;
			score1 = 0;
			score2 = 0;
		}
		else
		{
			Restart();	//choi lai
			playing = true;
		}
		Graphic::Update();
		
	}
	else if (int(b.y) <= 2) //bong cham bien tren
	{
		++score1;	//cong diem player 2
		Graphic::DrawString(11, game_height, to_string(score1), 11);
		
		if (score1 == 3)
		{
			Graphic::DrawString(game_width / 3 + 1, game_height, "PLAYER 1 WIN", 11);
			playing = false;
			score1 = 0;
			score2 = 0;
		}
		else 
		{
			Restart();	//choi lai
			playing = true;
		}
		Graphic::Update();
	}
}

void Game::BeforeStart(bool& ESCAPE)	//man hinh truoc khi bat dau choi
{
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2) + 5, "Press <space> to start", 10);
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2) + 7, " Press <ESC> to exit", 12);
	p1.Draw(bar_color);	//Ve thanh truot
	p2.Draw(bar_color);	//Ve thanh truot
	b.Draw(ball_color);		//Ve Ball
	if (GetAsyncKeyState(VK_SPACE))		//nhan phim space
	{
		Graphic::ClearScr();//clear press space text

		//Re-draw after clear
		b.Draw(ball_color);
		p1.Draw(bar_color);
		p2.Draw(bar_color);

		playing = true;	//game bat dau
	}
	if (GetAsyncKeyState(VK_ESCAPE))	//Nhan phim ESC
	{
		Graphic::ClearScr();
		ESCAPE =true;	// Ket thuc
	}
	//UI
	Graphic::DrawString(1, game_height, "Player 1:", 15);
	Graphic::DrawString(11, game_height, to_string(score1), 11);
	Graphic::DrawString(game_width * 2 / 3 + 1, game_height, "Player 2:", 15);
	Graphic::DrawString(game_width * 2 / 3 + 11, game_height, to_string(score2), 4);
	Graphic::Update();
}

void Game::Begin(bool BOT)	//khoi dong game
{
	score1 = 0;		//set lai diem ve 0
	score2 = 0;

	//dx,dy : Huong di ban dau
	b.dx = -3;
	b.dy = -3;
	b.ticks = 80000;//So ticks khi bat dau
	bool ESCAPE = false;	//Bien kiem tra xem nguoi choi co muon thoat game hay khong
	
	unsigned long long int timeSinceLastUpdate_Ball = 0;	//Thoi gian tu lan update ball cuoi cung

	int timeSinceLastUpdate_Bar = 0;		//Thoi gian tu lan update Bar cuoi cung
	int timeBetweentUpdate_Bar = 20000;		//Thoi gian giua hai lan update Bar

	int timeSinceLastUpdates_Graphic = 0;	//Thoi gian tu lan update Graphic cuoi cung
	int timeBetweenUpdates = 1000000 / 30;	//Tuong duong 30 fps, nghia la goi Graphic::Update() 30 lan 1 s

	auto t_start = std::chrono::high_resolution_clock::now();	//Bat dau tinh thoi gian
	
	while (!ESCAPE)
	{
		auto t_end = std::chrono::high_resolution_clock::now();
		current_time = std::chrono::duration<double, std::micro>(t_end - t_start).count();//Microseconds den thoi diem hien tai
		if (playing)	//game bat dau
		{
			if (current_time > timeSinceLastUpdate_Ball)
			{
				if (ball_pause)
				{
					//Dung trai banh va hien thi READY, GO
					ball_pause = false;
					Graphic::DrawString(game_width / 2 - 3, game_height - 25, "READY", 6);
					Graphic::Update();
					Sleep(800);
					Graphic::DrawRec(game_width / 2 - 3, game_height - 25, game_width / 2 + 6 - 3, game_height - 25, ' ', 0);//Xoa

					Graphic::DrawString(game_width / 2 + 1 - 3, game_height - 25, "GO", 6);
					Graphic::Update();
					Sleep(800);
					Graphic::DrawRec(game_width / 2 - 3, game_height - 25, game_width / 2 + 6 - 3, game_height - 25, ' ', 0);//Xoa
				}

				b.steps = abs(b.dx) > abs(b.dy) ? abs(b.dx) : abs(b.dy);	//Buoc di cua thanh truot 
				b.Xinc = b.dx / (float)b.steps;	//Buoc dich chuyen cua x
				b.Yinc = b.dy / (float)b.steps;	//Buoc dich chuyen cua y

				b.x_previous = round(b.x);	//Vi tri da di qua
				b.y_previous = round(b.y);	//Vi tri da di qua

				b.x += b.Xinc;//Vi tri moi
				b.y += b.Yinc;//Vi tri moi

				b.HitBarBottom(p1);
				b.HitBarTop(p2);
				b.HitSideBorder(game_width, game_height);
				b.Draw(ball_color);
				Win();							//xu li thang thua
				timeSinceLastUpdate_Ball = current_time + b.ticks * b.ticks_multiply;//b.ticks* b.ticks_multiply = microseconds before updating again
			}

			if (current_time > timeSinceLastUpdate_Bar)
			{

				p1.GetKey(VK_LEFT, VK_RIGHT);

				if (BOT)	//BOT LOGIC
				{
					float bar_dx = float(b.x - p2.x) / 8.0f;
					if (bar_dx > 0)
					{
						if (rand() % 100 > 70)
						{
							p2.isMovingRight = true;
							p2.isMovingLeft = false;
						}
						else
						{
							p2.isMovingLeft = true;
							p2.isMovingRight = false;
						}

					}
					else if (bar_dx < 0)
					{
						if (rand() % 100 > 70)
						{
							p2.isMovingLeft = true;
							p2.isMovingRight = false;
						}
						else
						{
							p2.isMovingRight = true;
							p2.isMovingLeft = false;
						}
					}
					else
					{
						p2.isMovingLeft = false;
						p2.isMovingRight = false;
					}
					if (b.y < game_height / 2 +5)
						p2.x += bar_dx;
				}
				else
				{
					p2.GetKey(65, 68);
				}

				p1.HitBorder(game_width);
				p2.HitBorder(game_width);
				p1.Draw(bar_color);
				p2.Draw(bar_color);
				timeSinceLastUpdate_Bar = current_time + timeBetweentUpdate_Bar;
			}
		}
		else
		{
			BeforeStart(ESCAPE);				//Man hinh truoc khi game bat dau
		}
		if (current_time > timeSinceLastUpdates_Graphic)
		{
			Graphic::Update();	//Update Graphic
			timeSinceLastUpdates_Graphic = current_time + timeBetweenUpdates;
		}
	}
}

void Game::BeginBOT()		//Tuong tu ben tren
{
	score1 = 0;
	score2 = 0;
	//C.DrawConsoleBOT(15);
	int timeSinceBegin = 0;
	bool Check = true;
	while (Check)
	{
		current_time = GetTickCount();
		if (current_time > timeSinceBegin)
		{
			if (playing)
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
				b.HitSideBorder(game_width, game_height);
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

//void Game::Draw(int color)		//Ve man hinh chao mung Game
//{
//	//C.DrawConsole(color);		//Tao console
//	//C.GoToXY(0, Height_console + 1);			//Xoa bang diem phia duoi
//	for (int i = 0; i < console_width + 1; ++i)
//		cout << ' ';
//	cout << endl;
//	for (int i = 0; i < console_width + 1; ++i)
//		cout << ' ';
//	p1.Draw(color);			//Tao thanh truot 1
//	p2.Draw(color);			//Tao thanh truot 2
//	//C.GoToXY(15, int(Height_console / 2));
//	//C.ChangeColorText(color);		//Cau chao mung
//	cout << "WELCOME TO BALL BAR GAME!!!";
//}

