#include "BoxManager.h"
BoxManager::BoxManager() 
{
	box_width = 7;
	box_height = 4;
}
void BoxManager::CreateNewBox(int x, int y, int health,int width,int height) 
{
	Box b;
	b.setPosition(x, y, health,width,height);
	boxes.push_back(b);
}
void BoxManager::Draw() 
{
	for (int i = 0;i < boxes.size();i++) 
	{
		boxes[i].Draw(6);
	}
}
void BoxManager::GenerateRandomBoxes(int n) 
{
	for (int i = 0;i < n;i++) 
	{
		Box b;
		//Generate random health and positon
		int box_x = 2+ box_width * (rand() % 9);//number 2 for border
		int box_y = 2+ box_height * (rand() % 7);
		int box_health = 1+rand() % 10;

		//Loop until find free x,y
		while (!positionFree(box_x, box_y))
		{
			box_x = 2+ box_width * (rand() % 9);
			box_y = 2+ box_height * (rand() % 7);
		}
		b.setPosition(box_x, box_y, box_health, box_width, box_height);//set box postion
		
		boxes.push_back(b);//push box to list
	}
}
bool BoxManager::positionFree(int x, int y) 
{
	for (int i = 0;i < boxes.size();i++)
	{
		if ((boxes[i].x == x) && (boxes[i].y == y))
		{
			return false;
		}
	}
	return true;
}
void BoxManager::BallHitBoxes(Ball& b) 
{
	for (int i = 0;i < boxes.size();i++)
	{
		boxes[i].BoxHitBall(b);
	}
}