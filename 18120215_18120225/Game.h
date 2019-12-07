#pragma once
#include "Ball.h"
#include "Bar.h"
#include "Console.h"
#include "Graphic.h"
#include <ctime>
//Game Set

class Game
{
	
private:
	Bar p1,p2;		//thanh truot player 1, player 2
	Ball b;			//bong
	bool start;		//hieu lenh kiem tra bat dau game hay chua
	int score1, score2;		//diem player 1, player 2
	int current_time;
	int bar_color = 9;
	int ball_color = 15;
public:
	Game();		//constructor Game
	void Restart();	//choi lai
	void Win();		//xu li thang thua
	void BeforeStart(bool &);	//man hinh truoc khi bat dau choi, truyen vao tin hieu nguoi choi co muon choi tiep hay khong
	void Begin();	//khoi dong game PvP
	void BeginBOT();	//khoi dong game PvBOT
	//void Draw(int);	//Ve man hinh chao mung
};

