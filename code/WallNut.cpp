#include "WallNut.h"
#include "globalVariables.h"

const int WallNut::plantPrice = 50;
int WallNut::cooltime = 0;


WallNut::WallNut(int as, int ms, int po_x, int po_y) :Plant(as, ms, po_x, po_y, 2000, 50,"WallNut")
{
	Animation::loadAnimation("Plant\\WallNut\\", 8, true);					//º”‘ÿº·π˚Õº∆¨
}

WallNut::~WallNut()
{
}

void WallNut::update()
{
	Plant::update();
}

int WallNut::getPlantPrice() {
	return plantPrice;
}

int WallNut::getCooltime()
{
	return cooltime;
}