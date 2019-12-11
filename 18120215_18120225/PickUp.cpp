#include "PickUp.h"
PickUp::PickUp() 
{
	destroyed = false;
}
void PickUp::setPosition(int x, int y, int width, int height)
{
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
}
void PickUp::Draw() 
{
	if (!destroyed)
	{
		//Delete old pos
		Graphic::DrawRec(xp, yp, xp + 6, yp,' ',0);
		if (type == Special::LONGER)
		{
			col = 2;//green
			Graphic::Draw(x, y, 174, col);
			Graphic::Draw(x + 1, y, ' ', 0);
			Graphic::DrawRec(x + 2, y, x + 4, y, 219, col);
			Graphic::Draw(x + 5, y, ' ', 0);
			Graphic::Draw(x+6, y, 175, col);
		}else if (type == Special::SHORTER)
		{
			col = 4;//red
			Graphic::Draw(x, y, 175, col);
			Graphic::Draw(x + 1, y, ' ', 0);
			Graphic::DrawRec(x + 2, y, x + 4, y, 219, col);
			Graphic::Draw(x + 5, y, ' ', 0);
			Graphic::Draw(x + 6, y, 174, col);
		}
		else if (type == Special::SLOWER) //Make ball slower
		{
			col = 7;
			Graphic::Draw(x, y, 174, col);
			Graphic::DrawString(x+2, y, "Slow", col);
			Graphic::Draw(x, y+1, 174, col);
			Graphic::DrawString(x + 2, y+1, "Ball", col);
		}
	}
	else 
	{
		Graphic::DrawRec(xp, yp, xp + 6, yp+1, ' ', 0);//Remove after destroyed
	}
	xp = x;
	yp = y;
}
void PickUp::PickUpHitBar(Ball& b,Bar& bar) 
{
	if (!destroyed) 
	{
		if ((int)y == (int)bar.y) 
		{
			if ((x > bar.x - bar.size && x < bar.x + bar.size) || (x+width > bar.x - bar.size && x+width < bar.x + bar.size))
			{
				//Bar touch pickup
				destroyed = true;
				if (type == Special::LONGER)
				{
					Graphic::DrawRec(int(bar.x) - bar.size, int(bar.y), int(bar.x) + bar.size - 1, int(bar.y), ' ', 0);//Xoa bar tam thoi
					if (bar.size < 12)
					{
						if (bar.x > game_width / 2) //Bar at right half
						{
							bar.xp--;
							bar.x--;
						}
						else//left half
						{
							bar.x++;
							bar.xp++;
						}

						bar.size++;
					}
				}else if (type == Special::SHORTER)
				{
					Graphic::DrawRec(int(bar.x) - bar.size, int(bar.y), int(bar.x) + bar.size - 1, int(bar.y), ' ', 0);//Xoa bar tam thoi
					if (bar.size > 1)
					{
						bar.size--;
					}
				}
				else if (type == Special::SLOWER) 
				{
					b.ticks = 50000;
				}

			}
		}
		if ((int)y == game_height - 4)
			destroyed = true;	//out of bound
		else
			y += 0.2f;
	}
}