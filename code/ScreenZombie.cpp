#include "ScreenZombie.h"

ScreenZombie::ScreenZombie(int as, int ms, int po_x, int po_y) :Zombie(as, ms, -2, po_x, po_y, 150, 89, "ScreenZombie")
{
	Animation::loadAnimation("Zombie//ScreenZombie//", 8, true);
	randomAnimation();
}

ScreenZombie::~ScreenZombie()
{
}
