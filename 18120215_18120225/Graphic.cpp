﻿#include "Graphic.h"

CHAR_INFO* Graphic::m_bufScreen;
SMALL_RECT Graphic::m_rectWindow;
HANDLE Graphic::m_hConsole;
Graphic::Graphic()
{
	m_bufScreen = new CHAR_INFO[full_width * full_height];//Cung cap bo nho
	memset(m_bufScreen, 0, sizeof(CHAR_INFO)* full_width * full_height);//Set tat ca cac ô thành số 0: kí tự rỗng
	m_rectWindow = { 0,0,short(full_width),short(full_height) };//Kich thuoc game
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}
void Graphic::Update()
{
	//HANDLE m_hConsole;

	WriteConsoleOutput(m_hConsole, m_bufScreen, { short(full_width),short(full_height) }, { 0,0 }, &m_rectWindow);
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
	if (x >= 0 && x < full_width && y >= 0 && y < full_height)
	{
		m_bufScreen[y * full_width + x].Char.AsciiChar = c;
		m_bufScreen[y * full_width + x].Attributes = col;
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
	HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
