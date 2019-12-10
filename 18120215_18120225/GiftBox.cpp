#include "GiftBox.h"
void GiftBox::Draw() 
{
	if (!destroyed)
	{
		Graphic::DrawRec(x, y, x + width - 1, y + height - 1, 219, 4);
		Graphic::DrawRec(x, y + height / 2, x + width - 1, y + height / 2, 219, 9);
		Graphic::DrawRec(x + width / 2, y, x + width / 2, y + height - 1, 219, 9);\
		//Graphic::DrawRec(x + 2, y + 1,x+4,y+3, 219, 15);
	}
}