#include "GameBreaker.h"
GameBreaker::GameBreaker() 
{
	start = false;	//Game chua bat dau
	bar.set_Bar(game_width / 2, game_height - 10, 8);	//Set thanh truot o giua san
	b.set_Ball(game_width / 2 , game_height / 2+15);	//Set bong o giua san
}
void GameBreaker::BeforeStart(bool& Check) 
{
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2) + 2, "LEVEL : ");
	Graphic::DrawString(game_width / 2 - 5, int(game_height / 2) + 2, to_string(level));
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2) + 3, "Press space to start");
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2) + 4, "Press ESC to exit");
	if (GetAsyncKeyState(VK_SPACE))		//nhan phim space
	{
		Graphic::ClearScr();
		boxManager.GenerateRandomBoxes(30);//Tao ra 
		start = true;	//game bat dau

		//Ball bat dau di chuyen
		b.steps = abs(b.dx) > abs(b.dy) ? abs(b.dx) : abs(b.dy);	//Buoc di cua thanh truot 
		b.Xinc = b.dx / (float)b.steps;	//Buoc dich chuyen cua x
		b.Yinc = b.dy / (float)b.steps;	//Buoc dich chuyen cua y
	}
	if (GetAsyncKeyState(VK_ESCAPE))	//Nhan phim ESC
	{
		Graphic::DrawRec(game_width / 2 - 12, int(game_height / 2) + 3, game_width / 2 - 12 + 21, int(game_height / 2) + 4, ' ', 0);
		Check = false;	// Ket thuc
	}
	TaskBar::draw_TaskBar_Game();
	Graphic::Update();
}
void GameBreaker::Restart() 
{

}
void GameBreaker::NextRound() 
{
	level++;
	start = false;	//Game chua bat dau
	Graphic::DrawRec(int(bar.x) - bar.size, int(bar.y), int(bar.x) + bar.size - 1, int(bar.y), ' ', 0);//Xoa bar cu
	bar.set_Bar(game_width / 2, game_height - 10, 7);	//Set thanh truot o giua san
	b.set_Ball(game_width / 2 - 1, game_height / 2 + 3);	//Set bong o giua san
}
void GameBreaker::Begin() 
{
	//dx,dy : Huong di ban dau
	b.dx = 3;
	b.dy = -3;
	b.ticks = 50;//So ticks khi bat dau

	bool Check = true;	//Bien kiem tra xem nguoi choi co muon thoat game hay khong
	int timeSinceBegin_Ball = 0;//Thoi gian tu luc bat dau game
	int timeSinceBegin_Other = 0;

	while (Check)
	{
		current_time = GetTickCount64();//Thoi gian tu luc bat dau chuong trinh
		if (current_time>timeSinceBegin_Ball)
		{
			if (start)	//game bat dau
			{
				b.steps = abs(b.dx) > abs(b.dy) ? abs(b.dx) : abs(b.dy);	//Buoc di cua thanh truot 
				b.Xinc = b.dx / (float)b.steps;	//Buoc dich chuyen cua x
				b.Yinc = b.dy / (float)b.steps;	//Buoc dich chuyen cua y

				b.x_previous = round(b.x);	//Vi tri da di qua
				b.y_previous = round(b.y);	//Vi tri da di qua
				
				b.x += b.Xinc;//Vi tri moi
				b.y += b.Yinc;//Vi tri moi

				boxManager.BallHitBoxes(b);//Bong cham obstacle
				b.HitBarBottom(bar);//Bong cham thanh truot
				b.HitSideTopBorder(game_width, game_height);//Bong cham bien top va side
				
				//Win();							//xu li thang thua
			}
			else
			{
				BeforeStart(Check);				//Man hinh truoc khi game bat dau
			}
			b.Draw(ball_color);	//Ve banh
			Graphic::Update();	//Update everything
			timeSinceBegin_Ball = current_time + b.ticks;//Update sau so ticks. SO ticks can nho ball cang nhanh
		}
		if (current_time > timeSinceBegin_Other)
		{
			if (start)
			{
				boxManager.updateBoxes(b, bar);	//Kiem tra va cham item va thanh
				bar.GetKey(VK_LEFT, VK_RIGHT);	//Input thanh truot
				bar.HitBorder(game_width);		//Thanh truot cham bien
				if (boxManager.Win()) //Khong con gift
				{
					NextRound();
				}
				boxManager.Draw();	//Ve obstacle
				bar.Draw(bar_color);	//Ve thanh truot
				Graphic::Update();	//Update everything
				timeSinceBegin_Other = current_time + 15;
			}
		}
	}
}