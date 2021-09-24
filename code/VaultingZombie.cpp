#include "VaultingZombie.h"
#include "same_row_col.h"
#include "globalVariables.h"
#include "globalVariables-objects.h"

VaultingZombie::VaultingZombie(int as, int ms, int po_x, int po_y) :Zombie(as, ms, -2, po_x, po_y, 320, 100, "VaultingZombie")
{
	Animation::loadAnimation("Zombie//VaultingZombie//", 2, true);
	randomAnimation();
}

VaultingZombie::~VaultingZombie()
{
}

void VaultingZombie::update()
{
	Zombie::update();
	if (!iscross)
	{
		for (std::vector<Plant*>::iterator iter = plant.begin(); iter != plant.end();++iter)
		{
			if ((*iter)->getType() != "HighWallNut")
			{
				if (is_same_row(getPozition_y(), (*iter)->getPozition_y()))//Í¬Ò»ÐÐ
				{
					if (getPozition_x() - (*iter)->getPozition_x() <= 40)
					{
						setPozition_x(getPozition_x() - 4 * PX);
						iscross = true;
					}
				}
			}
		}
	}
	
}

