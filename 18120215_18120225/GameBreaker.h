#pragma once
#include "Ball.h"
#include "Bar.h"
#include "Box.h"
#include "Graphic.h"
#include "BoxManager.h"
#include "Score.h"
#include "TaskBar.h"
#include "Bullet.h"
#include <chrono>

class GameBreaker
{
	int bar_color = 9;
	int ball_color=15;

	int level = 1;
	int scores = 0;
	int lives = 3;
	

	Bar bar;
	Ball b;
	bool ball_pause = true;//Bong Sleep

	//Ball bullet;
	Ball* bullet = new Bullet;
	bool bullet_firing = false;

	BoxManager boxManager;
	Score _score;
	bool playing;		//hieu lenh kiem tra bat dau game hay chua
	unsigned long long int current_time;//Time passed since start
public:
	GameBreaker();
	void Restart();
	void NextRound();
	void BeforeStart(bool&);
	void Begin(bool);

	void Lose();

	void DrawHealthAmmoes();
};
