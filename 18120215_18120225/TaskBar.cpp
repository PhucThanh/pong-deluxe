﻿#include "TaskBar.h"
TaskBar::TaskBar()
{
	
	//draw_BorderTask(game_width, 1, full_width - game_width - 1, 20, 15);
}
TaskBar::~TaskBar()
{
	Graphic::ClearScr();
}

/*void TaskBar::draw_BorderTask(int x, int y, int width, int height, int col)
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
}*/
void TaskBar::draw_TaskBar()
{

	//**************************
	//			PHIA DUOI
	//**************************
	//Clear taskbar background
	Graphic::DrawRec(0, game_height, game_width, game_height, ' ', 0);
	//Vach phan chia
	Graphic::Draw(0, game_height, 186, 15);
	Graphic::Draw(game_width / 3, game_height, 186, 15);
	Graphic::Draw(game_width * 2 / 3, game_height, 186, 15);
	Graphic::Draw(game_width - 1, game_height, 186, 15);

	//Bottom bar :
	Graphic::Draw(0, game_height + 1, 200, 15);//Corner
	Graphic::DrawRec(1, game_height + 1, game_width - 2, game_height + 1, 205, 15);//line
	Graphic::Draw(game_width / 3, game_height + 1, 202, 15);//Nga ba
	Graphic::Draw(game_width * 2 / 3, game_height + 1, 202, 15);//Nga ba
	Graphic::Draw(game_width - 1, game_height + 1, 188, 15);//Corner

	//Ket noi game va task bar :
	Graphic::Draw(0, game_height - 1, 204, 15);//BOT_LEFT
	Graphic::Draw(game_width / 3, game_height - 1, 203, 15);
	Graphic::Draw(game_width * 2 / 3, game_height - 1, 203, 15);
	Graphic::Draw(game_width - 1, game_height - 1, 185, 15);//BOT_RIGHT
}
//void TaskBar::draw_TaskBar_Game() 
//{
//	draw_TaskBar();
//	Graphic::DrawString(game_width + 7, 3, " _                   _ ", 15);
//	Graphic::DrawString(game_width + 7, 4, "| |                 | |", 15);
//	Graphic::DrawString(game_width + 7, 5, "| |    _____   _____| |", 15);
//	Graphic::DrawString(game_width + 7, 6, "| |   / _ \\ \\ / / _ \\ |", 15);
//	Graphic::DrawString(game_width + 7, 7, "| |__|  __/\\ V /  __/ |", 15);
//	Graphic::DrawString(game_width + 7, 8, "|_____\\___| \\_/ \\___|_|", 15);
//
//	draw_BigNumber(2, game_width + 13, 10);
//	draw_BigNumber(1, game_width + 21, 10);
//
//	Graphic::DrawString(game_width + 2, 34, " _____                       _   ", 12);
//	Graphic::DrawString(game_width + 2, 35, "|_   _|__ _  _ _  __ _  ___ | |_ ", 12);
//	Graphic::DrawString(game_width + 2, 36, "  | | / _` || '_|/ _` |/ -_)|  _|", 12);
//	Graphic::DrawString(game_width + 2, 37, "  |_| \\__,_||_|  \\__, |\\___| \\__|", 12);
//	Graphic::DrawString(game_width + 2, 38, "                 |___/           ", 12);
//	
//	 
//}
//void TaskBar::draw_Game_Level(int level) 
//{
//	
//}
//void TaskBar::draw_BigNumber(int number, int x, int y) 
//{
//	//http://patorjk.com/software/taag/#p=display&v=1&f=Big&t=1%0A2%0A3%0A4%0A5%0A6%0A7%0A8%0A9%0A0%0A
//	switch (number) 
//	{
//	case 0:
//		
//		break;
//	case 1:
//		Graphic::DrawString(x, y + 0, " __     ");
//		Graphic::DrawString(x, y + 1, "/_ |    ");
//		Graphic::DrawString(x, y + 2, " | |    ");
//		Graphic::DrawString(x, y + 3, " | |    ");
//		Graphic::DrawString(x, y + 4, " | |    ");
//		Graphic::DrawString(x, y + 5, " |_|    ");
//		break;
//	case 2:
//		Graphic::DrawString(x, y + 0, " ___    ");
//		Graphic::DrawString(x, y + 1, "|__ \\   ");
//		Graphic::DrawString(x, y + 2, "   ) |  ");
//		Graphic::DrawString(x, y + 3, "  / /   ");
//		Graphic::DrawString(x, y + 4, " / /_   ");
//		Graphic::DrawString(x, y + 5, "|____|  ");
//		break;
//	case 3:
//		break;
//	case 4:
//		break;
//	case 5:
//		break;
//	case 6:
//		break;
//	case 7:
//		break;
//	case 8:
//		break;
//	case 9:
//		break;
//	}
//}*/