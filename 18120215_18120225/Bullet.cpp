#include "Bullet.h"
void Bullet::Draw(int col) 
{
	Graphic::Draw(round(x_previous), round(y_previous), ' ', 0);//Xóa vị trí cũ	
	Graphic::Draw(round(x_previous), round(y_previous) + 1, ' ', 0);//Xóa vị trí cũ	
	//Trait
	//Graphic::Draw(round(pastPost[0].first), round(pastPost[0].second), ' ', 0);//Xóa vị trí cũ
	//Graphic::Draw(round(pastPost[7].first), round(pastPost[7].second), 248, 12);//Xóa vị trí cũ

	Graphic::Draw(round(x), round(y), 239, 14);//233 : Bullet
	Graphic::Draw(round(x), round(y)+1, 219, 14);//233 : Bullet
											   //Display speed
	//Graphic::DrawRec(round(x_previous)+1, round(y_previous),round(x_previous)+2,round(y_previous), ' ', 0);//Xóa vị trí cũ	
	//Graphic::DrawString(round(x) + 1, round(y), to_string(ticks), 15);

	pastPost.push_back(pair<float, float>(x, y));
	pastPost.erase(pastPost.begin());
}