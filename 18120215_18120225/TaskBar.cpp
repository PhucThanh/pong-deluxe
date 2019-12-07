#include "TaskBar.h"
TaskBar::TaskBar()
{
	//draw_BorderTask(game_width, 1, full_width - game_width - 1, 20, 15);
}
TaskBar::~TaskBar()
{
	Graphic::ClearScr();
}

void TaskBar::draw_BorderTask(int x, int y, int width, int height, int col)
{
	
	for (int i = x ; i < x + width ; i++)
	{
		Graphic::Draw(i, y, 196, 15);
		Graphic::Draw(i, y + height -1 , 196, 15);
	}
	for (int i = y; i < y + height; i++)
	{
		Graphic::Draw(x, i, 179, 15);
		Graphic::Draw(x + width -1, i, 179, 15);
	}
	Graphic::Draw(x, y, 218 , col);//top left corner
	Graphic::Draw(x + width - 1, y, 191, col);//top right corner
	Graphic::Draw(x, y + height - 1, 192, col);//Bottom Left
	Graphic::Draw(x + width - 1, y + height - 1, 217, col);//Bottom Right
}
void TaskBar::draw_TaskBar()
{
	draw_BorderTask(game_width, 1, full_width - game_width - 1, 22, 15);
	draw_BorderTask(game_width, 23, full_width - game_width - 1, 5, 15);
	draw_BorderTask(game_width, 28, full_width - game_width - 1, 5, 15);
	draw_BorderTask(game_width, 33, full_width - game_width - 1, 27, 15);
}
