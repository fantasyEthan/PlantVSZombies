#include"ConeZombie.h"


ConeZombie::ConeZombie(int as, int ms, int po_x, int po_y) :Zombie(as, ms, -2, po_x, po_y, 480, 109, "ConeZombie")
{
	Animation::loadAnimation("Zombie//ConeZombie//", 21, true);
	randomAnimation();
}

ConeZombie::~ConeZombie()
{
}


