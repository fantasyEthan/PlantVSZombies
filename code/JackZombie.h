#pragma once

#include "Zombie.h"
class JackZombie :public Zombie
{
public:
	JackZombie(int as = 0, int ms = 0, int po_x = 0, int po_y = 0);
	virtual void update();
	~JackZombie(); 
private:
	int workCounter = 100;
};