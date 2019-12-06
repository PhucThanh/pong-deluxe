#include "Menu.h"
Menu::Menu()
{
	menu_title = "- MAIN MENU -";
	select = 0;
	menu_list[0] = "BREAKER GAME";
	menu_list[1] = "PONG GAME";
	menu_list[2] = "HOW TO PLAY";
	menu_list[3] = "EXIT";
}
Menu::~Menu()
{
	delete[] menu_list;
}
int Menu::run_Menu()// ham chinh goi chay menu
{
	//Intro();
	input key = GetKey();;
	int timeSinceBeginSnow = 0;
	int timeSinceBeginMenu = 0;
	while (key!=ENTER)
	{
		
		key = GetKey();
		current_time = GetTickCount();
		if (current_time > timeSinceBeginSnow)
		{
			Graphic::ClearScr();
			Animate::draw_Land();
			Animate::draw_Snow();
			
			timeSinceBeginSnow = current_time +120;
		}
		if (current_time > timeSinceBeginMenu)
		{
			DrawMenu();
			update_Menu(key);
			Graphic::Update();
			timeSinceBeginMenu = current_time + 100;
		}
		
	}
	return select;


}
input Menu::GetKey()// nhan phim bam nguoi dung
{
	//Sleep(40); // de khong bi lap lien tuc
	if (!pressed)
	{
		pressed = true;
		if (GetAsyncKeyState(VK_UP))
		{
				return UP;
		}
		if (GetAsyncKeyState(VK_DOWN))
			return DOWN;
		if (GetAsyncKeyState(VK_RETURN))
			return ENTER;
		return NONE;
	}
	else
		pressed = false;
}
void Menu::update_Menu(input in)// thiet lap viec chon
{
	switch (in)
	{
	case UP:
		if (select == 0)
			select = 3;
		else
			select--;
		//DrawSelectMenu();
		break;
	case DOWN:
		if (select == 3)
			select = 0;
		else
			select++;
		//DrawSelectMenu();
		break;
	default:
		break;
	}

}

void Menu::Intro()
{
	for (int i = 1; i < 16; i++)
	{
		DrawBorder(i);
		Sleep(70);
		Graphic::Update();
	}
	DrawBorder(7);
}
void Menu::DrawBlock32(int x, int y, int color)//Ve khoi cho chu
{
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 2; j++)
		{
			Graphic::Draw(i, j, BLOCK, color);
		}
	}

}
void Menu::DrawIcon(int startx, int starty, int color)//ve chu P.B
{

	for (int i = starty; i < starty + 14; i += 2)
		DrawBlock32(startx, i, color);
	startx += 3;
	DrawBlock32(startx, starty, color);
	DrawBlock32(startx, starty + 6, color);
	startx += 3;
	DrawBlock32(startx, starty, color);
	DrawBlock32(startx, starty + 6, color);
	startx += 3;
	DrawBlock32(startx, starty, color);
	DrawBlock32(startx, starty + 6, color);
	startx += 3;
	for (int i = starty; i < starty + 8; i += 2)
		DrawBlock32(startx, i, color);
	startx += 6;
	DrawBlock32(startx, starty + 12, color);
	startx += 8;
	for (int i = starty; i < starty + 14; i += 2)
		DrawBlock32(startx, i, color);
	startx += 3;
	DrawBlock32(startx, starty, color);
	DrawBlock32(startx, starty + 6, color);
	DrawBlock32(startx, starty + 12, color);
	startx += 3;
	DrawBlock32(startx, starty, color);
	DrawBlock32(startx, starty + 6, color);
	DrawBlock32(startx, starty + 12, color);
	startx += 3;
	DrawBlock32(startx, starty + 12, color);
	for (int i = starty; i < starty + 8; i += 2)
		DrawBlock32(startx, i, color);
	startx += 3;
	for (int i = starty + 6; i < starty + 14; i += 2)
		DrawBlock32(startx, i, color);

	//Graphic::Update();
}
void Menu::DrawMenu()
{
	DrawIcon(game_width / 5 - 1, game_height / 6, 15);
	DrawIcon(game_width / 5 - 1, game_height / 6 - 1, 4);
	DrawSelectMenu();
}
void Menu::DrawSelectMenu()
{
	Graphic::DrawString((game_width -menu_title.length())  / 2, game_height / 2 , menu_title, 10);//Tieu de menu
	for (int i = game_width / 5; i < game_width - (game_width / 5); i++)
	{
		Graphic::Draw(i, game_height / 2 - 1, ROW, 15);
		Graphic::Draw(i, game_height / 2 + 1, ROW, 15);
		Graphic::Draw(i, 5 * game_height / 7, ROW, 15);
	}
	
	//Graphic::DrawString(game_width / 3 - 7, 5 * game_height / 7, "|.|", 10);
	for (int i = game_height / 2 ; i < 5 * game_height / 7; i++)
	{
		Graphic::Draw(game_width / 5 - 1, i, COL, 15);
		Graphic::Draw(game_width - (game_width / 5), i, COL, 15);
	}

	Graphic::Draw(game_width / 5 - 1, game_height / 2 - 1, TOP_LEFT, 15);
	Graphic::Draw(game_width / 5 - 1, game_height / 2 + 1 , 204, 15);
	Graphic::Draw(game_width / 5 - 1, 5 * game_height / 7, BOT_LEFT, 15);

	Graphic::Draw(game_width - (game_width / 5), game_height / 2 - 1, TOP_RIGHT, 15);
	Graphic::Draw(game_width - (game_width / 5), game_height / 2 + 1, 185, 15);
	Graphic::Draw(game_width - (game_width / 5), 5 * game_height / 7, BOT_RIGHT, 15);

	for (int i = 0; i < MAX_MENU; i++)
	{
		if (i != select)// ve cai khung
		{
			for (int j = game_width / 4 - 3; j < game_width - (game_width / 4) + 3; j++)
			{
				for (int k = game_height / 1.75 + 2 * i - 1; k < game_height / 1.75 + 2 * i + 1; k++)
				{
					Graphic::Draw(j, k , static_cast<char>(255), 10); // deselect
				}
			}
			Graphic::DrawString((game_width - menu_list[i].length() - 4) / 2, game_height / 1.75 + 2 * i, "  " + menu_list[i] + "  ", DESELECT_COLOR);
			
		}
	}
		
	/*for (int j = game_width / 4 + 1; j < game_width - (game_width / 4); j++)
	{
		Graphic::Draw(j, game_height / 1.75 + 2 * select - 1, ROW, SELECT_COLOR);
	}
	for (int j = game_width / 4 + 1; j < game_width - (game_width / 4); j++)
	{
		Graphic::Draw(j, game_height / 1.75 + 2 * select + 1, ROW, SELECT_COLOR);
	}
	Graphic::Draw(game_width / 4, game_height / 1.75 + 2 * select, COL, SELECT_COLOR);
	Graphic::Draw(game_width / 4, game_height / 1.75 + 2 * select - 1, TOP_LEFT, SELECT_COLOR);
	Graphic::Draw(game_width / 4, game_height / 1.75 + 2 * select + 1, BOT_LEFT, SELECT_COLOR);
	Graphic::Draw(game_width - (game_width / 4), game_height / 1.75 + 2 * select, COL, SELECT_COLOR);
	Graphic::Draw(game_width - (game_width / 4), game_height / 1.75 + 2 * select - 1, TOP_RIGHT, SELECT_COLOR);
	Graphic::Draw(game_width - (game_width / 4), game_height / 1.75 + 2 * select + 1, BOT_RIGHT, SELECT_COLOR);*/
	Graphic::DrawString((game_width - menu_list[select].length() - 4) / 2, game_height / 1.75 + 2 * select, "> " + menu_list[select] + " <", SELECT_COLOR);

}
void Menu::DrawBorder(int color)		//Ve man hinh chao mung Game
{

	Graphic::Draw(0, 0, TOP_LEFT, color);
	Graphic::Draw(game_width - 1, 0, TOP_RIGHT, color);
	Graphic::Draw(0, game_height - 1, BOT_LEFT, color);
	Graphic::Draw(game_width - 1, game_height - 1, BOT_RIGHT, color);
	for (int i = 1; i < game_width - 1; ++i)
	{
		Graphic::Draw(i, 0, ROW, color);//Bien tren
		Graphic::Draw(i, game_height - 1, ROW, color);//Bien duoi
	}
	for (int i = 1; i < game_height - 1; ++i)
	{
		//Biên trái
		Graphic::Draw(0, i, static_cast<char>(COL), color);
		//Graphic::Draw(1, i, static_cast<char>(c), color);
		//Biên phải
		//Graphic::Draw(game_width , i, static_cast<char>(186), color);
		Graphic::Draw(game_width - 1, i, static_cast<char>(COL), color);
	}
	//Graphic::DrawString(game_width / 2 - 10, game_height / 2  - 5, "WELCOME TO OUR GAME!", color);
	//Graphic::Update();
	//Graphic::DrawString(game_width / 2 - 10, game_height / 2 - 5, "                       ", color);//Xoa dong
}
