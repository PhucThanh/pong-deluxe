#pragma once
#include "Graphic.h"
#include <time.h>
class Animate
{
public:
	static void draw_Snow();//Hieu ung tuyet
	static void draw_Land();//Mat dat
	static void draw_Tree(int, int);//Ve 1 cai cay voi toa do ngon x,y
	static void draw_AniString(int, int, string, int);
};

