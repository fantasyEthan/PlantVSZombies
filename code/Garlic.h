#pragma once
#include "Plant.h"

class Garlic :public Plant
{
public:
	Garlic(int as, int ms, int po_x, int po_y);
	~Garlic();
	virtual void update();							
	static int getPlantPrice();
	static int getCooltime();
	static int cooltime;
private:
	static const int plantPrice;
};
