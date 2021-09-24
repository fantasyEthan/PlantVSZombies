#pragma once
#include "Zombie.h"
class VaultingZombie :public Zombie
{
public:
	VaultingZombie(int as = 0, int ms = 0, int po_x = 0, int po_y = 0);
	~VaultingZombie();
	virtual void update();
private:
	bool iscross = false;
}; 

