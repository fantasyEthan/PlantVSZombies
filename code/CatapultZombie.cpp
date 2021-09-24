#include"CatapultZombie.h"
#include "globalVariables.h"
#include "globalVariables-objects.h"
#include"same_row_col.h"



CatapultZombie::CatapultZombie(int as, int ms, int po_x, int po_y) :Basketball(as, ms, -3, po_x, po_y, 580, 60, "CatapultZombie",1)
{
	Animation::loadAnimation("Zombie//CatapultZombie//", 1, true);
	randomAnimation();
}

CatapultZombie::~CatapultZombie()
{
}

void CatapultZombie::update()
{
	Zombie::update();
	std::cout << "CatapultZombie: " << getPozition_x() << " " << getPozition_y() << std::endl;
	int has_plant_ahead = 0;
	if (getPozition_x() <= 600)
	{
		for (auto iter = plant.begin(); iter != plant.end(); ++iter)
		{
			if (is_same_row(getPozition_y(), (*iter)->getPozition_y()))
			{
				has_plant_ahead = 1;
			}
		}
		if (has_plant_ahead && !isempty)
		{
			setMoveStatus(0);
			Basketball::update();
		}
		else if (!has_stopped)
		{
			setMoveStatus(1);
			setAttack(100);
			setSpeed_x(-2);
		}
	}



}
