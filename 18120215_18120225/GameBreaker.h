#pragma once
#include "Ball.h"
#include "Bar.h"
#include "Box.h"
#include "Graphic.h"
#include "BoxManager.h"
#include <ctime>

class GameBreaker
{
	int bar_color = 9;
	int ball_color=15;
	int level = 1;
	Bar bar;
	Ball b;

	BoxManager boxManager;
	bool start;		//hieu lenh kiem tra bat dau game hay chua
	int current_time;//Time passed since start
public:
	GameBreaker();
	void Restart();
	void NextRound();
	void BeforeStart(bool&);
	void Begin();
	void BeginBOT();
};

