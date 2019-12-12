#pragma once
#include "Box.h"
#include "GiftBox.h"
#include "Graphic.h"
#include "Ball.h"
#include <vector>
using namespace std;
class BoxManager
{
	vector<Box*> boxes;
	int number_of_gift;
	int box_width;
	int box_height;
public:
	BoxManager();
	~BoxManager();
	void CreateNewBox(int, int, int,int,int);//Create new box with x,y,health
	void GenerateRandomBoxes(int n,int level);//Generate n boxes
	void Draw();
	bool positionFree(int, int);//Return true if x,y free
	void BallHitBoxes(Ball&);
	void updateBoxes(Ball&, Bar&);
	bool Win();
};

