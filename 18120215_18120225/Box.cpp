#include "Box.h"
Box::Box() 
{
	destroyed = false;
}
void Box::setPosition(int x, int y,int health,int width,int height) 
{
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	this->health = health;
}
void Box::Draw(int col) 
{
	if (!destroyed)
	{
		Graphic::Draw(x, y, 201, col);//top left corner
		Graphic::DrawRec(x + 1, y, x + width-2, y, 205, col);//Top
		Graphic::Draw(x + width-1, y, 187, col);//top right corner

		Graphic::DrawRec(x, y + 1,x,y+height-2, 186, col);//Left border

		Graphic::Draw(x + 4, y + 2, ' ', col);//Erase health
		Graphic::DrawString(x + 3, y + 2, std::to_string(health), col);//Draw health

		Graphic::DrawRec(x + width-1, y + 1,x+width-1,y+height-1, 186, col);//Right border

		Graphic::Draw(x, y + height-1, 200, col);//Bottom Left
		Graphic::DrawRec(x + 1, y + height-1, x + width - 1, y + height-1, 205, col);//Botom box
		Graphic::Draw(x + width-1, y + height-1, 188, col);//Bottom Right
	}
}
void Box::BoxHitBall(Ball& b) 
{
	if (!destroyed)
	{
		int b_y = b.y;
		int b_x = b.x;

		/*
		1====2
		|####|
		|#xx#|
		|####|
		3====4
		*/

		//Cạnh
		if ((b_y == y) && (b_x >= x + 1) && (b_x <= x + width-2))//Top
		{
			b.sy *= -1;
			b.y--;
			health--;
		}
		else if ((b_y == y+height-1) && (b_x >= x + 1) && (b_x <= x+width-2))//Bot
		{
			b.sy *= -1;
			b.y++;
			health--;
		}
		else if ((b_x == x) && (b_y >= y + 1)&&(b_y<=y+height-2)) //Left
		{
			b.sx *= -1;
			b.x--;
			health--;
		}
		else if ((b_x == x+width-1) && (b_y >= y + 1) && (b_y <= y + height - 2))//Right
		{
			b.sx *= -1;
			b.x++;
			health--;
		}
		//Góc
		if (b_x == x && b_y == y) //Góc trái trên
		{
			b.sx = -1;
			b.sy = -1;
			health--;
		}

		if (b_x == x+width-1 && b_y == y) //Góc phải trên
		{
			b.sx = 1;
			b.sy = -1;
			health--;
		}

		if (b_x == x && b_y == y+height-1) //Góc trái dưới
		{
			b.sx = -1;
			b.sy = 1;
			health--;
		}

		if (b_x == x+width-1 && b_y == y+height-1) //Góc phải dưới
		{
			b.sx = 1;
			b.sy = 1;
			health--;
		}
	}


	if (health <= 0)
	{
		destroyed = true;
		//Remove image
		Graphic::DrawRec(x, y, x + width-1, y + height-1, ' ', 0);
	}
}