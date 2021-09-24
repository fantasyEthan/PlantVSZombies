#include "Garlic.h"
#include "globalVariables.h"
#include "globalVariables-objects.h"
#include"same_row_col.h"

const int Garlic::plantPrice = 50;
int Garlic::cooltime = 0;

Garlic::Garlic(int as, int ms, int po_x, int po_y) :Plant(as, ms, po_x, po_y, 500, 50, "Garlic")
{
	Animation::loadAnimation("Plant\\Garlic\\", 1, true);
}

Garlic::~Garlic()
{
}

void Garlic::update()
{
	Plant::update();

	if (moveStatus == 0 && animationStatus == 1)
	{
		for (std::vector<Zombie*>::iterator iter = zombie.begin(); iter != zombie.end();)
		{
			if (is_same_row((*iter)->getPozition_y(),this->getPozition_y()))
			{
				if (getPozition_x() - (*iter)->getPozition_x() <= 40 && getPozition_x() - (*iter)->getPozition_x() >= -40)
				{
					int y = (*iter)->getPozition_y();
					healthPoint = 0;
					if (y == 80)
					{
						(*iter)->setPozition_y(y + 70);
					}
					else if (y == 150)
					{
						(*iter)->setPozition_y(y - 70);
					}
					else
					{
						(*iter)->setPozition_y(y - 100);
					}
				}

			}
			++iter;
		}

	}
}

int Garlic::getPlantPrice() {
	return plantPrice;
}



int Garlic::getCooltime()
{
	return cooltime;
}
