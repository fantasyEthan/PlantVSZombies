#include "PeaShooter.h"

const int PeaShooter::plantPrice = 100;
int PeaShooter::cooltime = 0;

PeaShooter::PeaShooter(int as, int ms, int po_x, int po_y):Shooter(as,ms,po_x,po_y,300, 100, 1)
{
	Animation::loadAnimation("Plant\\PeaShooter\\", 12);
}

int PeaShooter::getPlantPrice() {
	return plantPrice;
}

int PeaShooter::getCooltime()
{
	return cooltime;
}