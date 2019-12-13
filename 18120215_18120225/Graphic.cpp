#include "Graphic.h"

CHAR_INFO* Graphic::m_bufScreen;
SMALL_RECT Graphic::m_rectWindow;
HANDLE Graphic::m_hConsole;
Graphic::Graphic()
{
	m_bufScreen = new CHAR_INFO[game_width * full_height];//Cung cap bo nho
	memset(m_bufScreen, 0, sizeof(CHAR_INFO)* game_width * full_height);//Set tat ca cac ô thành số 0: kí tự rỗng
	m_rectWindow = { 0,0,short(game_width),short(full_height) };//Kich thuoc game
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}
void Graphic::Update()
{
	//HANDLE m_hConsole;

	WriteConsoleOutput(m_hConsole, m_bufScreen, { short(game_width),short(full_height) }, { 0,0 }, &m_rectWindow);
}
void Graphic::ClearScr() 
{
	for (int i = 1; i < game_width - 1; i++)
	{
		for (int j = 1; j < game_height-1; j++)
		{
			Graphic::Draw(i, j, static_cast<char>(255), 0);
		}
	}	
}
void Graphic::Draw(int x, int y, short c = 0x2588, short col = 0x000F)
{
	if (x >= 0 && x < game_width && y >= 0 && y < full_height)
	{
		m_bufScreen[y * game_width + x].Char.AsciiChar = c;
		m_bufScreen[y * game_width + x].Attributes = col;
	}
}
void Graphic::DrawString(int x, int y, string s, short col)
{
	for (int i = 0; i < s.length(); i++)
	{
		Draw(x + i, y, s[i], col);
	}
}
void Graphic::DrawRec(int x1, int y1, int x2, int y2, short c = 0x2588, short col = 0x000F)
{
	for (int i = x1; i <= x2; i++)
	{
		for (int j = y1; j <= y2; j++)
		{
			Draw(i, j, c, col);
		}
	}
}
void Graphic::goToXY(int x, int y)
{
	//HANDLE h = NULL;
	//if (!h)
		//h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(m_hConsole, c);
}
void Graphic::DrawBox(int x, int y, int x2, int y2, int col)
{
	Graphic::DrawRec(x, y, x2, y2, ' ',0);//fill black

	Graphic::DrawRec(x, y, x2, y, 205, col);//top
	Graphic::DrawRec(x, y2, x2, y2, 205, col);//bottom
	Graphic::DrawRec(x, y, x, y2, 186, col);//left
	Graphic::DrawRec(x2, y, x2, y2, 186, col);//right
	/*for (int i = x; i < x + width; i++)
	{
		Graphic::Draw(i, y, 196, 15);
		Graphic::Draw(i, y + height - 1, 196, 15);
	}
	for (int i = y; i < y + height; i++)
	{
		Graphic::Draw(x, i, 179, 15);
		Graphic::Draw(x + width - 1, i, 179, 15);
	}*/
	Graphic::Draw(x, y, 201, col);//top left corner
	Graphic::Draw(x2, y, 187, col);//top right corner
	Graphic::Draw(x, y2, 200, col);//Bottom Left
	Graphic::Draw(x2, y2, 188, col);//Bottom Right
}