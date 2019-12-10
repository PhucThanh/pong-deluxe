#include "BoxManager.h"
BoxManager::BoxManager() 
{
	box_width = 7;
	box_height = 4;
}
void BoxManager::CreateNewBox(int x, int y, int health,int width,int height) 
{
	//Box b;
	//b.setPosition(x, y, health,width,height);
	//boxes.push_back(b);
}
void BoxManager::Draw() 
{
	for (int i = 0;i < boxes.size();i++) 
	{
		(*boxes[i]).Draw();
	}
}
void BoxManager::GenerateRandomBoxes(int n) 
{
	boxes.clear();
	//Gift Box
	number_of_gift = 2;
	for (int i = 0;i < number_of_gift;i++)
	{
		Box* b = new GiftBox;
		//Generate random health and positon
		int box_x = 1 + box_width * (rand() % 10);//number 2 for border
		int box_y = 1 + box_height * (rand() % 2);
		int box_health = 1 + rand() % 4;

		//Loop until find free x,y
		while (!positionFree(box_x, box_y))
		{
			box_x = 1 + box_width * (rand() % 10);
			box_y = 1 + box_height * (rand() % 2);
		}
		b->setPosition(box_x, box_y, box_health, box_width, box_height);//set box postion
		b->col = 3 + rand() % 7;
		boxes.push_back(b);//push box to list

	}
	for (int i = 0;i < n-3;i++) 
	{
		
		Box *b=new Box;
		//Generate random health and positon
		int box_x = 1+ box_width * (rand() % 10);//number 2 for border
		int box_y = 1+ box_height * (rand() % 7);
		int box_health = 1+rand() % 3;

		//Loop until find free x,y
		while (!positionFree(box_x, box_y))
		{
			box_x = 1+ box_width * (rand() % 10);
			box_y = 1+ box_height * (rand() % 7);
		}
		b->setPosition(box_x, box_y, box_health, box_width, box_height);//set box postion
		b->col = 4 + rand() % 10;
		boxes.push_back(b);//push box to list

	}
}
bool BoxManager::positionFree(int x, int y) 
{
	for (int i = 0;i < boxes.size();i++)
	{
		if (((*boxes[i]).x == x) && ((*boxes[i]).y == y))
		{
			return false;
		}
	}
	return true;
}
void BoxManager::BallHitBoxes(Ball& b) 
{
	number_of_gift = 2;
	for (int i = 0;i < boxes.size();i++)
	{
		(*boxes[i]).BoxHitBall(b);
		if ((*boxes[i]).destroyed && (*boxes[i]).getType() == "Gift")
			number_of_gift--;
	}
}
void BoxManager::updateBoxes(Ball& b, Bar& bar) 
{
	for (int i = 0;i < boxes.size();i++)
	{
		(*boxes[i]).PickUpHitBar(b,bar);
	}
}
bool BoxManager::Win() 
{
	if (number_of_gift == 0)
	{
		return true;
	}
	return false;
}