#pragma once
#include "Zombie.h"
class ScreenZombie :public Zombie
{
public:
	ScreenZombie(int as = 0, int ms = 0, int po_x = 0, int po_y = 0);
	~ScreenZombie();
};

