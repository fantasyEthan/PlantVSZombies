#include "Car.h"
#include "Zombie.h"
#include "globalVariables-objects.h"
#include "globalvariables.h"

int Car::BaseHp = 15;
Car::Car(int as, int ms, int po_x, int po_y) :Animation(as), Movable(ms),Object(po_x,po_y,0)
{
	Animation::loadAnimation("Plant\\Car\\",1,1);
}

void Car::show()
{
	Animation::play(Object::position_x, Object::position_y);											//·â×°playº¯Êý
}

void Car::update()
{
	move(position_x, position_y);
}

Car::~Car()
{
}

