#pragma once

#include "Zombie.h"
class NoNewspaperZombie :public Zombie
{
public:
	NoNewspaperZombie(int as = 0, int ms = 0, int po_x = 0, int po_y = 0);
	~NoNewspaperZombie();
};
