#include "Animate.h"
void Animate::draw_Snow()
{
	//clear();
	//srand((int)time(0));
	for (int i = 0; i < 50; i++)
	{
		Graphic::Draw(rand() % (game_width-2) + 1, rand() % (game_height-5) + 1, static_cast<char>(248), 15);
	}
	for (int i = 0; i < 50; i++)
	{
		Graphic::Draw(rand() % (game_width - 2) + 1, rand() % (game_height - 5) + 1, static_cast<char>(250), 15);
	}
	for (int i = 0; i < 50; i++)
	{
		Graphic::Draw(rand() % (game_width - 2) + 1, rand() % (game_height - 5) + 1, static_cast<char>(42), 8);
	}
	
	for (int i = 0; i < 30; i++)
	{
		Graphic::Draw(rand() % (game_width - 2) + 1, game_height - (rand() % ((game_height / 3) - 2)  + 6 ), static_cast<char>(249), 15);
	}
}
void Animate::draw_Tree(int x, int y)//ve theo toa do dinh cay thong
{
	Graphic::Draw(x, y, static_cast<char>(94), 10);
	Graphic::Draw(x - 1, y + 1, static_cast<char>(47), 10);
	Graphic::Draw(x, y + 1, static_cast<char>(255), 10);
	Graphic::Draw(x + 1, y + 1, static_cast<char>(92), 10);
	Graphic::Draw(x - 1, y + 2, static_cast<char>(47), 10);
	Graphic::Draw(x, y + 2, static_cast<char>(255), 10);
	Graphic::Draw(x + 1, y + 2, static_cast<char>(92), 10);
	Graphic::Draw(x, y + 3, static_cast<char>(179), 4);
}
void Animate::draw_Land()
{
	for (int i = 1; i < game_width - 1; i++)
	{
		for (int j = game_height - ((game_height / 10) - 2); j < game_height-1; j++)
		{
			Graphic::Draw( i , j, static_cast<char>(239), 10);
		}
	}
	for (int i = 3; i < 60; i+=4)
	{
		draw_Tree(i, 53);
		//Graphic::Draw(rand() % (game_width - 2) + 1, game_height - (rand() % ((game_height / 8) - 2) + 4), static_cast<char>(176), 6);
	}
	
}