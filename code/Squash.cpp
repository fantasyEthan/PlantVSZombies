#include "Squash.h"
#include "globalVariables.h"
#include "globalVariables-objects.h"
#include "same_row_col.h"

const int Squash::plantPrice = 50;
int Squash::cooltime = 0;

Squash::Squash(int as, int ms, int po_x, int po_y):Plant(as, ms, po_x, po_y, 300, 50, "Squash")
{
	Animation::loadAnimation("Plant\\Squash\\Squash\\", 50, true);					
}

Squash::~Squash()
{ 
}

void Squash::update()
{
	Plant::update();

	if (moveStatus == 0 && animationStatus == 1)
	{
			
		for (std::vector<Zombie*>::iterator iter = zombie.begin(); iter != zombie.end();)
		{
			if (is_same_row((*iter)->getPozition_y(), getPozition_y()))
			{
				if (getPozition_x() - (*iter)->getPozition_x() <= 40 && getPozition_x() - (*iter)->getPozition_x() >= -40)
				{
					healthPoint = 0;
					Zombie::killNum++;
					delete (*iter);
					iter = zombie.erase(iter);
				}
				else {
					iter++;
				}
			}
			else {
				iter++;
			}
		}
	
			
	}
}

int Squash::getPlantPrice() {
	return plantPrice;
}

int Squash::getCooltime()
{
	return cooltime;
}