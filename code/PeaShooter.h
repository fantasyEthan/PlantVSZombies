#pragma once
#include "Shooter.h"
class PeaShooter : public Shooter
{
public:
	PeaShooter(int  as, int  ms, int  po_x, int  po_y);
	static int getPlantPrice();
	static int getCooltime();
	static int cooltime;
private:
	static const int plantPrice;
};

