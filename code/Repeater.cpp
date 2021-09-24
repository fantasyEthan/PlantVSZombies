#include "Repeater.h"

const int Repeater::plantPrice = 200;
int Repeater::cooltime = 0;

Repeater::Repeater(int as, int ms, int po_x, int po_y) :Shooter(as, ms, po_x, po_y, 300, 200, 4)
{
	Animation::loadAnimation("Plant\\Repeater\\", 15, true);
}

int Repeater::getPlantPrice() {
	return plantPrice;
}

int Repeater::getCooltime()
{
	return cooltime;
}
