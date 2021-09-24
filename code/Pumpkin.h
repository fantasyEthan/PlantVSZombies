#pragma once
#include"Plant.h"
class Pumpkin :public Plant
{
public:
	Pumpkin(int as, int ms, int po_x, int po_y);
	~Pumpkin();
	virtual void update();							// 向日葵产阳光
	static int getPlantPrice();
	static int getCooltime();
	static int cooltime;
private:
	static const int plantPrice;
};