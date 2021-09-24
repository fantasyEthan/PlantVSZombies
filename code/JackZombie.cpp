#include"JackZombie.h"
#include "globalVariables.h"
#include "globalVariables-objects.h"


JackZombie::JackZombie(int as, int ms, int po_x, int po_y) :Zombie(as, ms, -2, po_x, po_y, 580, 100, "JackZombie")
{
	Animation::loadAnimation("Zombie//JackZombie//", 1, true);
	randomAnimation();
}

JackZombie::~JackZombie()
{
}

void JackZombie::update()
{
	Zombie::update();
	if (getPozition_x() <= 700)
	{
		if (workCounter == 0)
		{
			healthPoint = 0;
			for (std::vector<Plant*>::iterator iter = plant.begin(); iter != plant.end();)
			{
				if (((*iter)->getPozition_x() - this->getPozition_x()) <= 120 && ((*iter)->getPozition_x() - this->getPozition_x()) >= -120 && ((*iter)->getPozition_y() - this->getPozition_y()) <= 150 && ((*iter)->getPozition_y() - this->getPozition_y()) >= -150)
				{
					delete (*iter);
					iter = plant.erase(iter);
				}
				else {
					iter++;
				}
			}
				
		}
		if (workCounter != 0)
		{
			workCounter--;
		}
			
	}
	
	
	
}
