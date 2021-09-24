#include "Pumpkin.h"
#include "globalVariables.h"

const int Pumpkin::plantPrice = 50;
int Pumpkin::cooltime = 0;


Pumpkin::Pumpkin(int as, int ms, int po_x, int po_y) :Plant(as, ms, po_x, po_y, 2000, 125,"Pumpkin")
{
	Animation::loadAnimation("Plant\\Pumpkin\\", 1, true);					//º”‘ÿº·π˚Õº∆¨
}

Pumpkin::~Pumpkin()
{
}

void Pumpkin::update()
{
	Plant::update();
}

int Pumpkin::getPlantPrice() {
	return plantPrice;
}

int Pumpkin::getCooltime()
{
	return cooltime;
}

