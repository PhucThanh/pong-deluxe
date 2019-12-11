#include "GameBreaker.h"
GameBreaker::GameBreaker() 
{
	start = false;	//Game chua bat dau
	bar.set_Bar(game_width / 2, game_height - 10, 12);	//Set thanh truot o giua san
	b.set_Ball(game_width / 2 , game_height -11);	//Set bong o giua san
}
void GameBreaker::BeforeStart(bool& Check) 
{
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2) + 3, "Press space to start");
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2) + 4, "Press ESC to exit");
	bar.Draw(bar_color);	//Ve thanh truot
	if (GetAsyncKeyState(VK_SPACE))		//nhan phim space
	{
		Graphic::ClearScr();
		b.Draw(ball_color);
		bar.Draw(bar_color);
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
	
	//UI DRAWING
	Graphic::DrawString(1, game_height, "Level :", 15);
	Graphic::DrawString(9, game_height, to_string(level), 15);
	Graphic::DrawString(game_width/3+1, game_height, "Scores :", 15);
}
void GameBreaker::Restart() 
{

}
void GameBreaker::NextRound() 
{
	level++;

	Graphic::DrawString(9, game_height, to_string(level), 15);

	start = false;	//Game chua bat dau
	Graphic::DrawRec(int(bar.x) - bar.size, int(bar.y), int(bar.x) + bar.size - 1, int(bar.y), ' ', 0);//Xoa bar cu
	bar.set_Bar(game_width / 2, game_height - 10, 12);	//Set thanh truot o giua san
	b.set_Ball(game_width / 2 - 1, game_height / 2 + 3);	//Set bong o giua san
}
void GameBreaker::Begin() 
{
	//dx,dy : Huong di ban dau
	b.dx = 3;
	b.dy = -3;
	b.ticks = 50000;//So ticks khi bat dau

	bool Check = true;	//Bien kiem tra xem nguoi choi co muon thoat game hay khong

	unsigned long long int timeSinceLastUpdate_Ball = 0;
	//int timeBetweenUpdate_Ball = 50000;//ticks

	int timeSinceLastUpdate_Bar = 0;
	int timeBetweentUpdate_Bar = 25000;

	int timeSinceLastUpdates_Graphic = 0;
	int timeBetweenUpdates = 1000000/100; // 100 fps

	auto t_start = std::chrono::high_resolution_clock::now();


	while (Check)
	{
		using namespace std::chrono;
		//current_time = duration_cast<microseconds>(steady_clock::now().time_since_epoch()).count();;//Thoi gian tu luc bat dau chuong trinh
		
		//Calculate time passed in microsecond
		//1 000 000 ticks = 1 second
		auto t_end = std::chrono::high_resolution_clock::now();
		current_time = std::chrono::duration<double, std::micro>(t_end - t_start).count();


		if (start)	//game bat dau
		{
			if (current_time> timeSinceLastUpdate_Ball)
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
				b.Draw(ball_color);	//Ve banh
				timeSinceLastUpdate_Ball = current_time+ b.ticks;
			}

			if (current_time > timeSinceLastUpdate_Bar)
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
				timeSinceLastUpdate_Bar = current_time + timeBetweentUpdate_Bar;
			}
		}
		else
		{
			BeforeStart(Check);				//Man hinh truoc khi game bat dau
		}

		if (current_time > timeSinceLastUpdates_Graphic)
		{
			Graphic::Update();	//Update everything
			timeSinceLastUpdates_Graphic = current_time + timeBetweenUpdates;//Update sau so ticks. SO ticks can nho ball cang nhanh
		}
	}
}