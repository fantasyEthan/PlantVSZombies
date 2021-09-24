#pragma once
#include "Zombie.h"
#include "Basketball.h"
class CatapultZombie :public Basketball
{
public:
	CatapultZombie(int as = 0, int ms = 0, int po_x = 0, int po_y = 0);
	virtual void update();
	~CatapultZombie();
private:
	int workCounter = 100;
};
