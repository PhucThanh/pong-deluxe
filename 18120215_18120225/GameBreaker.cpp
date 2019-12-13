#include "GameBreaker.h"

GameBreaker::GameBreaker() 
{
	playing = false;	//Game chua bat dau
	bar.setPosition(game_width / 2, game_height - 10, 8);	//Set thanh truot o giua san
	b.setPosition(game_width / 2 , game_height -11);	//Set bong o giua san
}
void GameBreaker::BeforeStart(bool& ESCAPE)
{
	//Man hinh cho truoc khi bat dau. Bam phim space de choi hoac ESC de thoat
	//Draw truoc nhung gi can hien thi

	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2) + 5, "Press <space> to start",10);
	Graphic::DrawString(game_width / 2 - 12, int(game_height / 2) + 7, " Press <ESC> to exit",12);
	bar.Draw(bar_color);	//Ve thanh truot
	b.Draw(ball_color);		//Ve Ball

	if (GetAsyncKeyState(VK_SPACE))		//nhan phim space
	{
		Graphic::ClearScr();

		DrawHealthAmmoes();
		b.Draw(ball_color);
		bar.Draw(bar_color);
		
		//Generate level

		int number_of_box = 20 + level * 3;
		if (number_of_box > 69)
			number_of_box = 69;
		boxManager.GenerateRandomBoxes(number_of_box,level);//Create boxes

		//Start the game

		playing = true;	//game bat dau
	}
	else if (GetAsyncKeyState(VK_ESCAPE))	//Nhan phim ESC
	{
		Graphic::ClearScr();
		ESCAPE = true;
	}
	Graphic::Update();
	
	//UI DRAWING
	Graphic::DrawString(game_width / 3 + 1, game_height, "LEVEL :", 15);
	Graphic::DrawString(game_width / 3 + 9, game_height, to_string(level), 15);
	Graphic::DrawString(game_width * 2 / 3 + 1, game_height, "Your score :", 15);
	Graphic::DrawString(1, game_height, "Best score :", 15);
}

void GameBreaker::Restart() 
{
	level = 1;
	ball_pause = true;	//Pause the ball
	Graphic::DrawString(9, game_height, to_string(level), 15);	//Update level in UI

	playing = false;	//Game chua bat dau

	Graphic::DrawRec(int(bar.x) - bar.size, int(bar.y), int(bar.x) + bar.size - 1, int(bar.y), ' ', 0);//Xoa bar cu
	bar.setPosition(game_width / 2, game_height - 10, bar.size);	//Set thanh truot o giua san


	//Khoi tao lai cac thong so cho ball
	b.setPosition(game_width / 2 - 1, game_height - 11);	//Set bong o giua san
	b.ticks = 60000;	//Reset ball ticks
	b.ticks_multiply = 1.0f;
	b.speed_level = 0;	//Reset speed level
	b.dx = 3;	//Ball's direction
	b.dy = -3;	//Ball's direction
}

void GameBreaker::NextRound() //QUA MAN CHOI KE TIEP
{
	level++;	//Level increase
	ball_pause = true;	//Pause the ball
	Graphic::DrawString(9, game_height, to_string(level), 15);	//Update level in UI

	playing = false;	//Game chua bat dau

	Graphic::DrawRec(int(bar.x) - bar.size, int(bar.y), int(bar.x) + bar.size - 1, int(bar.y), ' ', 0);//Xoa bar cu
	bar.setPosition(game_width / 2, game_height - 10, bar.size);	//Set thanh truot o giua san


	//Khoi tao lai cac thong so cho ball
	b.setPosition(game_width / 2 - 1, game_height - 11);	//Set bong o giua san
	b.ticks = 60000;	//Reset ball ticks
	b.ticks_multiply = 1.0f;
	b.speed_level = 0;	//Reset speed level
	b.dx = 3;	//Ball's direction
	b.dy = -3;	//Ball's direction

}
void GameBreaker::Begin(bool BOT) 
{
	//dx,dy : Huong di ban dau
	b.dx = -3;
	b.dy = -3;
	b.ticks = 60000;//So ticks khi bat dau
	lives = 3;
	bool ESCAPE = false;	//Bien kiem tra xem nguoi choi co muon thoat game hay khong

	unsigned long long int timeSinceLastUpdate_Ball = 0;	//Thoi gian tu lan update ball cuoi cung

	int timeSinceLastUpdate_Bar = 0;		//Thoi gian tu lan update Bar cuoi cung
	int timeBetweentUpdate_Bar = 20000;		//Thoi gian giua hai lan update Bar

	int timeSinceLastUpdate_Bullet=0;		//Thoi gian tu lan update Bullet cuoi cung
	int timeBetweenUpdate_Bullet = 30000;	//THoi gian giua 2 lan update Bullet
	

	int timeSinceLastUpdates_Graphic = 0;	//Thoi gian tu lan update Graphic cuoi cung
	int timeBetweenUpdates = 1000000/30;	//Tuong duong 30 fps, nghia la goi Graphic::Update() 30 lan 1 s
	//Frame qua cao thi Graphic::Update() bi goi nhieu lan => Lag
	//Fram qua tham thi khong choi duoc
	//-> 30fps hop ly

	auto t_start = std::chrono::high_resolution_clock::now();	//Bat dau tinh thoi gian

	while (!ESCAPE)
	{
		//Calculate time passed in microsecond
		//1 000 000 microseconds = 1 second
		auto t_end = std::chrono::high_resolution_clock::now();
		current_time = std::chrono::duration<double, std::micro>(t_end - t_start).count();//Microseconds den thoi diem hien tai

		if (playing)	//Khi dang choi
		{
			if (current_time> timeSinceLastUpdate_Ball)
			{
				if (ball_pause)
				{
					//Dung trai banh va hien thi READY, GO
					ball_pause = false;
					Graphic::DrawString(game_width / 2-3, game_height - 25, "READY", 6);
					Graphic::Update();
					Sleep(800);
					Graphic::DrawRec(game_width / 2-3, game_height - 25, game_width / 2 + 6-3, game_height - 25, ' ', 0);//Xoa

					Graphic::DrawString(game_width / 2 + 1-3, game_height - 25, "GO", 6);
					Graphic::Update();
					Sleep(800);
					Graphic::DrawRec(game_width / 2-3, game_height - 25, game_width / 2 + 6-3, game_height - 25, ' ', 0);//Xoa
				}

				b.steps = abs(b.dx) > abs(b.dy) ? abs(b.dx) : abs(b.dy);	//Buoc di cua thanh truot 
				b.Xinc = b.dx / (float)b.steps;	//Buoc dich chuyen cua x
				b.Yinc = b.dy / (float)b.steps;	//Buoc dich chuyen cua y

				b.x_previous = round(b.x);	//Vi tri da di qua
				b.y_previous = round(b.y);	//Vi tri da di qua

				b.x += b.Xinc;//Vi tri moi
				b.y += b.Yinc;//Vi tri moi

				boxManager.BallHitBoxes(b);					//Bong cham obstacle
				b.HitBarBottom(bar);						//Bong cham thanh truot
				b.HitSideTopBorder(game_width, game_height);//Bong cham bien top va side
				b.Draw(ball_color);							//Ve banh
				Lose();										//Kiem tra end game

				timeSinceLastUpdate_Ball = current_time+ b.ticks* b.ticks_multiply;//b.ticks* b.ticks_multiply = microseconds before updating again
			}

			if (current_time > timeSinceLastUpdate_Bullet)
			{
				if (GetAsyncKeyState(VK_SPACE) && !bullet_firing && bar.ammoes > 0)	//Bam phim space, khong co vien dan nao dang bay
				{
					bar.ammoes--;			//Giam so luong dan
					(*bullet).damage = 100;	//Bullet damage
					bullet_firing = true;	//Dan dang duoc ban
					(*bullet).setPosition(bar.x, bar.y - 1);	//Vi tri vien dan ban
					(*bullet).dx = 0;	//Dan khong bay thi chieu x
					(*bullet).dy = -1; //Dan bay len

					DrawHealthAmmoes();//Update UI ammo
				}

				if (bullet_firing)	//When a bullet on screen
				{
					//(*bullet).steps = abs((*bullet).dx) > abs((*bullet).dy) ? abs((*bullet).dx) : ;	//Buoc di cua thanh truot 
					(*bullet).y_previous = round((*bullet).y);	//Vi tri da di qua
					//(*bullet).Yinc = (*bullet).dy / (float)abs((*bullet).dy);	//Buoc dich chuyen cua y
					(*bullet).y -= 1;
					
					boxManager.BallHitBoxes((*bullet));	//Kiem tra va cham bullet va box

					if ((*bullet).dy > 0)	//Bullet touched box
					{
						(*bullet).x = -10;		//Hide the bullet
						(*bullet).dy = 0;		//Speed = 0
						bullet_firing = false; //No bullet on screen
					}
					if ((*bullet).y == 1)	//Bullet touched top border
					{
						(*bullet).x = -10;		//Hide the bullet
						(*bullet).dy = 0;		//Speed = 0
						bullet_firing = false; //No bullet on screen
					}
					(*bullet).Draw(4);			//Draw bullet with color
				}
				
				timeSinceLastUpdate_Bullet = current_time + timeBetweenUpdate_Bullet;
			}

			if (current_time > timeSinceLastUpdate_Bar)
			{
				if (GetAsyncKeyState(VK_ESCAPE))	//Nhan phim ESC
				{
					//Force losing
					lives = 0;
					b.y = game_height + 10;
					Lose();
					Graphic::ClearScr();
					ESCAPE = true;
				}


				boxManager.updateBoxes(b, bar);	//Kiem tra va cham item va thanh
				DrawHealthAmmoes();//Phong khi nhat duoc ammoes thi update

				if (BOT)	//BOT LOGIC
				{
					float bar_dx = float(b.x - bar.x) / 8.0f;
					if (bar_dx > 0)
					{
						if (rand() % 100 > 70)
						{
							bar.isMovingRight = true;
							bar.isMovingLeft = false;
						}
						else
						{
							bar.isMovingLeft = true;
							bar.isMovingRight = false;
						}

					}
					else if (bar_dx < 0)
					{
						if (rand() % 100 > 70)
						{
							bar.isMovingLeft = true;
							bar.isMovingRight = false;
						}
						else
						{
							bar.isMovingRight = true;
							bar.isMovingLeft = false;
						}
					}
					else
					{
						bar.isMovingLeft = false;
						bar.isMovingRight = false;
					}
					if (b.y > game_height / 2 - 5)
						bar.x += bar_dx;
				}
				else
					bar.GetKey(VK_LEFT, VK_RIGHT);	//Input thanh truot - NOT BOT

				bar.HitBorder(game_width);		//Thanh truot cham bien
				if (boxManager.Win()) //Khong con gift
				{
					NextRound();
				}
				_score.update_Score(boxManager,level); //update diem
				boxManager.Draw();	//Ve obstacle
				bar.Draw(bar_color);	//Ve thanh truot
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

	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		Graphic::ClearScr();
		Graphic::DrawString(game_width / 3, game_height / 4 - 4, "TOP 10 BREAKER GAME SCORE", 14);
		_score.draw_HighScore();
		Graphic::DrawString(game_width / 3, game_height - 10, "PRESS ESC TO RETURN TO MAIN MENU");
		Graphic::Update();
	}
}

void GameBreaker::Lose() 
{
	if (b.y >= game_height - 2) //Ball out of bound
	{
		
		if (lives > 1)
		{
			//Lose 1 life
			lives--;
			ball_pause = true;

			//Reset ball
			b.Clear();//Delete old ball
			b.setPosition(game_width / 2, game_height - 11);
			b.dy = -3;
			b.dx = -3;
			b.ticks = 60000;
			b.ticks_multiply = 1.0f;
			b.speed_level = 0;

			//Update UI for lives
			DrawHealthAmmoes();
			Graphic::Update();
		}
		else 
		{
			//Lose game
			_score.update_HighScore();
			_score.reset_Score();
			Restart();
			playing = false;
		}
	}
}
void GameBreaker::DrawHealthAmmoes() 
{
	//********************************
	//			Draw lives
	//********************************

	Graphic::DrawRec(1, game_height - 3, 10, game_height - 2, ' ', 0);//Clear any heart left
	for (int i = 0;i < lives;i++)
	{
		//These 4 line draw a hear <3
		Graphic::Draw(1 + i * 3, game_height - 3, 239, 4 | 15);
		Graphic::Draw(2 + i * 3, game_height - 3, 239, 4 | 15);
		Graphic::Draw(1 + i * 3, game_height - 2, '\\', 4 | 15);
		Graphic::Draw(2 + i * 3, game_height - 2, '/', 4 | 15);
	}

	//********************************
	//			Draw bullets
	//********************************
	//Instruction
	Graphic::DrawString(game_width - 28, game_height - 2, "<space>", 12);
	Graphic::DrawString(game_width - 20, game_height - 2, "to shoot", 15);
	for (int i = 0;i < 5;i++)
	{
		//Gray background bullets
		Graphic::Draw(game_width - 11 + i * 2, game_height - 3, 239, 8);
		Graphic::Draw(game_width - 11 + i * 2, game_height - 2, 219, 8);
	}
	for (int i = 0;i < bar.ammoes;i++)
	{
		//Active bullets
		Graphic::Draw(game_width - 11 + i * 2, game_height - 3, 239, 14);
		Graphic::Draw(game_width - 11 + i * 2, game_height - 2, 219, 14);
	}
}
