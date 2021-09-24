#include"HighWallNuts.h"

#include "globalVariables.h"

const int HighWallNut::plantPrice = 100;
int HighWallNut::cooltime = 0;


HighWallNut::HighWallNut(int as, int ms, int po_x, int po_y) :Plant(as, ms, po_x, po_y, 4000, 100,"HighWallNut")
{
	Animation::loadAnimation("Plant\\TallNut\\", 1, true);					//加载高坚果图片
}

HighWallNut::~HighWallNut()
{
}

void HighWallNut::update()
{
	Plant::update();
}

int HighWallNut::getPlantPrice() {
	return plantPrice;
}

int HighWallNut::getCooltime()
{
	return cooltime;
}
