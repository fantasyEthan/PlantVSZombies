#pragma once
#include "Plant.h"
class WallNut : public Plant
{
public:
	WallNut(int as, int ms, int po_x, int po_y);
	~WallNut();
	virtual void update();							// 向日葵产阳光
	static int getPlantPrice();
	static int getCooltime();
	static int cooltime;
private:
	static const int plantPrice;
};

