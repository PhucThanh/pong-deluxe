#pragma once
#include "Box.h"
class GiftBox :
	public Box
{
	void Draw();
	virtual string getType()
	{
		return "Gift";
	}
};

