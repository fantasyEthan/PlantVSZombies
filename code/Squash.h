#pragma once

#include "Plant.h"

class Squash :public Plant
{
public:
	Squash(int as, int ms, int po_x, int po_y);
	~Squash();
	virtual void update();							//Ó£ÌÒÕ¨µ¯ÏûÊ§
	static int getPlantPrice();
	static int getCooltime();
	static int cooltime;
private:
	static const int plantPrice;
};
