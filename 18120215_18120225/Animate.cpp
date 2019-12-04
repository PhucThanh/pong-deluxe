#include "Animate.h"
void Animate::clear()
{
	for (int i = 1; i < game_width-1; i++)
	{
		for (int j = 1; j < game_height-1; j++)
		{
			Graphic::Draw(i, j, static_cast<char>(255), 0);
		}
	}
	Graphic::Update();
}
void Animate::draw_Snow()
{
	clear();
	//srand((int)time(0));
	for (int i = 0; i < 100; i++)
	{
		Graphic::Draw(rand() % (game_width-2) + 1, rand() % (game_height-2) + 1, static_cast<char>(248), 15);
	}
	for (int i = 0; i < 100; i++)
	{
		Graphic::Draw(rand() % (game_width - 2) + 1, rand() % (game_height - 2) + 1, static_cast<char>(250), 15);
	}
	for (int i = 0; i < 50; i++)
	{
		Graphic::Draw(rand() % (game_width - 2) + 1, rand() % (game_height - 2) + 1, static_cast<char>(42), 8);
	}
	for (int i = 0; i < 300; i++)
	{
		Graphic::Draw(rand() % (game_width - 2) + 1, game_height - (rand() % ((game_height/10) - 2)  + 2), static_cast<char>(176), 8);
	}
	for (int i = 0; i < 15; i++)
	{
		Graphic::Draw(rand() % (game_width - 2) + 1, game_height - (rand() % ((game_height / 8) - 2) + 4), static_cast<char>(176), 15);
	}
	for (int i = 0; i < 30; i++)
	{
		Graphic::Draw(rand() % (game_width - 2) + 1, game_height - (rand() % ((game_height / 4) - 2)  + 6 ), static_cast<char>(249), 15);
	}

	Graphic::Update();
	
}
//void Animate::draw_SnowFall()
//{
//	//while (true)
//	{ 
//		draw_Snow();
//		Sleep(50);
//		//clear();
//		Graphic::Update();
//	}
//	
//}
