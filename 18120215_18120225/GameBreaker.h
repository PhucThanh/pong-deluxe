#pragma once
#include "Ball.h"
#include "Bar.h"
#include "Box.h"
#include "Graphic.h"
#include "BoxManager.h"
#include "TaskBar.h"
#include "Bullet.h"
#include <chrono>


class GameBreaker
{
	int bar_color = 9;
	int ball_color=15;

	int level = 10;
	int scores = 0;
	int lives = 3;
	

	Bar bar;
	Ball b;

	//Ball bullet;
	Ball* bullet = new Bullet;
	bool bullet_firing = false;

	BoxManager boxManager;
	
	bool playing;		//hieu lenh kiem tra bat dau game hay chua
	unsigned long long int current_time;//Time passed since start
public:
	GameBreaker();
	void Restart();
	void NextRound();
	void BeforeStart(bool&);
	void Begin();
	void BeginBOT();

	void Lose();

	void DrawHealthAmmoes();
};
