#pragma once
#pragma once
#include "Plant.h"
class HighWallNut : public Plant
{
public:
	HighWallNut(int as, int ms, int po_x, int po_y);
	~HighWallNut();
	virtual void update();							// 向日葵产阳光
	static int getPlantPrice();
	static int getCooltime();
	static int cooltime;
private:
	static const int plantPrice;
};

