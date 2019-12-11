#pragma once
#include "Graphic.h"
class TaskBar
{
public:
	TaskBar();
	~TaskBar();
	static void draw_BorderTask(int, int, int, int, int);
	static void draw_TaskBar();
	static void draw_TaskBar_Game();
	static void draw_Game_Level(int);
	static void draw_BigNumber(int, int, int);
};

