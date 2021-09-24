#pragma once
#include "Zombie.h"
#include "ball.h"
#include "Animation.h"

//#pragma comment(lib,"Winmm.lib")
class Basketball : public Zombie
{
public:
	Basketball(int  as, int  ms, int vx, int  po_x, int  po_y, int hp, int atk, std::string type, int b);
	virtual ~Basketball() = 0;
	virtual void update();						// Ö²Îï¸üÐÂ	
protected:
	int bulletType;		
	bool isempty;
	int ballNum = 0;
};