#pragma once
#include "Box.h"
#include "Graphic.h"
#include "Ball.h"
#include <vector>
using namespace std;
class BoxManager
{
	vector<Box> boxes;
	int box_width;
	int box_height;
public:
	BoxManager();
	void CreateNewBox(int, int, int,int,int);//Create new box with x,y,health
	void GenerateRandomBoxes(int);//Generate n boxes
	void Draw();
	bool positionFree(int, int);//Return true if x,y free
	void BallHitBoxes(Ball&);
};
