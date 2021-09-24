#pragma once
#include "Shooter.h"

//–°≥µ¿‡
class Car:public Object, public Movable, public Animation
{
public:
	Car(int  as, int  ms, int  po_x, int  po_y);
	virtual void update();
	virtual void show();
	~Car();
	static int BaseHp;
};

