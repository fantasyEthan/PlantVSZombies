#include "NoNewspaperZombie.h"

NoNewspaperZombie::NoNewspaperZombie(int as, int ms, int po_x, int po_y) :Zombie(as, ms, -8, po_x, po_y, 200, 100, "NoNewspaperZombie")
{
	Animation::loadAnimation("Zombie//NoNewspaperZombie//", 14, true);
	randomAnimation();
}

NoNewspaperZombie::~NoNewspaperZombie()
{
}