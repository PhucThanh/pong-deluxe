#include "GameBreaker.h"
GameBreaker::GameBreaker() 
{
	start = false;
	bar.set_Bar(game_width / 2, game_height - 15, 8);	//tao thanh truot
	b.set_Ball(game_width / 2 - 1, game_height / 2+3);	//tao bong
}
void GameBreaker::BeforeStart(bool& Check) 
{
	//C.GoToXY(int(Width_console / 2 - 12), int(Height_console / 1.5f));	//dua con tro toi giua man hinh
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2) + 3, "Press any key to start");
	//C.GoToXY(int(Width_console / 2 - 12), int(Height_console / 1.5f) + 1);
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2) + 4, "Press ESC to exit");
	if (GetAsyncKeyState(VK_SPACE))		//nhan phim space
	{
		//Xoa Text Press any key...
		Graphic::DrawRec(game_width / 2 - 12, int(game_height / 2) + 3, game_width / 2 - 12 + 21, int(game_height / 2) + 4, ' ', 0);
		boxManager.GenerateRandomBoxes(30);
		start = true;	//game bat dau
	}
	if (GetAsyncKeyState(VK_ESCAPE))	//Nhan phim ESC
	{
		Graphic::DrawRec(game_width / 2 - 12, int(game_height / 2) + 3, game_width / 2 - 12 + 21, int(game_height / 2) + 4, ' ', 0);
		Check = false;	// Ket thuc
	}
}
#define PI 3.14159265358979323846
void GameBreaker::Begin() 
{
	//b.ChangeAngle(1, 1);
	//b.ChangeAngle(45*PI/180);
	b.dx = 3;
	b.dy = 10;

	bool Check = true;	//Bien kiem tra xem nguoi choi co muon thoat game hay khong
	int timeSinceBegin = 0;
	while (Check)
	{
		current_time = GetTickCount();
		if (current_time > timeSinceBegin)
		{
			//b.MaxSpeed(2);
			if (start)	//game bat dau
			{

				bar.GetKey(VK_LEFT, VK_RIGHT);	//phim dieu khien thanh truot 1
				bar.HitBorder(game_width);			//thanh truot 1 cham bien
				b.steps = abs(b.dx) > abs(b.dy) ? abs(b.dx) : abs(b.dy);
				float Xinc = b.dx / (float)b.steps;
				float Yinc = b.dy / (float)b.steps;
				//past
				b.x_previous = round(b.x);
				b.y_previous = round(b.y);
				

				//b.x += b.sx;
				//b.y += b.sy;
				b.x += Xinc;
				b.y += Yinc;

				b.HitBarBottom(bar);//bong cham thanh truot
				b.HitSideTopBorder(game_width, game_height);
				
				//boxManager.BallHitBoxes(b);
				//bong cham bien
				//Win();							//xu li thang thua
			}
			else
			{
				BeforeStart(Check);				//Man hinh truoc khi game bat dau
			}
			bar.Draw(bar_color);							//tao thanh truot 1
			
			boxManager.Draw();
			b.Draw(ball_color);							//tao bong
			Graphic::Update();
			timeSinceBegin = current_time + 40;
		}
	}
}