#include "GameBreaker.h"
GameBreaker::GameBreaker() 
{
	start = false;	//Game chua bat dau
	bar.set_Bar(game_width / 2, game_height - 10, 8);	//Set thanh truot o giua san
	b.set_Ball(game_width / 2 - 1, game_height / 2+3);	//Set bong o giua san
}
void GameBreaker::BeforeStart(bool& Check) 
{
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2) + 3, "Press space to start");
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2) + 4, "Press ESC to exit");
	if (GetAsyncKeyState(VK_SPACE))		//nhan phim space
	{
		//Xoa Text Press space...
		Graphic::DrawRec(game_width / 2 - 12, int(game_height / 2) + 3, game_width / 2 - 12 + 21, int(game_height / 2) + 4, ' ', 0);
		boxManager.GenerateRandomBoxes(40);//Tao ra 
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
	//dx,dy : Huong di ban dau
	b.dx = 1;
	b.dy = 1;

	bool Check = true;	//Bien kiem tra xem nguoi choi co muon thoat game hay khong
	int timeSinceBegin = 0;//Thoi gian tu luc bat dau game
	while (Check)
	{
		current_time = GetTickCount();//Thoi gian tu luc bat dau chuong trinh
		if (current_time > timeSinceBegin)
		{
			b.MaxSpeed(4);//Dat gioi han cho speed (dx hoac dy ko the vuot qua 4)
			if (start)	//game bat dau
			{
				bar.GetKey(VK_LEFT, VK_RIGHT);	//Input thanh truot
				bar.HitBorder(game_width);		//Thanh truot cham bien

				b.steps = abs(b.dx) > abs(b.dy) ? abs(b.dx) : abs(b.dy);	//Buoc di cua thanh truot 
				float Xinc = b.dx / (float)b.steps;	//Buoc dich chuyen cua x
				float Yinc = b.dy / (float)b.steps;	//Buoc dich chuyen cua y

				b.x_previous = round(b.x);	//Vi tri da di qua
				b.y_previous = round(b.y);	//Vi tri da di qua
				
				b.x += Xinc;//Di chuyen bong
				b.y += Yinc;//Di chuyen bong

				b.HitBarBottom(bar);//Bong cham thanh truot
				b.HitSideTopBorder(game_width, game_height);//Bong cham bien top va side
				
				boxManager.BallHitBoxes(b);//Bong cham obstacle
				//Win();							//xu li thang thua
			}
			else
			{
				BeforeStart(Check);				//Man hinh truoc khi game bat dau
			}
			bar.Draw(bar_color);		//Ve thanh truot
			boxManager.Draw();	//Ve obstacle
			b.Draw(ball_color);	//Ve banh
			Graphic::Update();	//Update everything
			timeSinceBegin = current_time + 40;
		}
	}
}