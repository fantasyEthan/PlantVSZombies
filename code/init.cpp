#include "globalVariables.h"
#include "globalVariables-objects.h"
#include "Shooter.h"
#include "SunFlower.h"
#include "BasicZombie.h"
#include "ConeZombie.h"
#include "BucketheadZombie.h"
#include "NewspaperZombie.h"
#include "JackZombie.h"
#include "VaultingZombie.h"
#include "CatapultZombie.h"
#include "ScreenZombie.h"
#include "Random.h"
#if 1
#include<algorithm>
#include<iostream>
#endif

vector<int> zombie_x(Zombienum);
vector<int> zombie_y(Zombienum);
void make_zombies()
{
	if (mode == 2)
	{
		zombie_x = { 800,900,1000,2500,2100,2500,2800,3300,3400,3600,3500,3700,3550,3800,3900,3500,3700,3600,3500,3700,3600 };
		zombie_y = { 80,150,350,80,350,450,150,250,450,350,80,250,150,350,450,250,350,450,80,250,150 };  // 僵尸位置
	}
	if (mode == 1)//随机生成僵尸
	{
		int zombie_y_p[5] = { 80,150,250,350,450 };
		zombie_x = Random(1000, 3000, Zombienum);
		vector<int> zombie_y_idx = Random(0, 5, Zombienum);
		for (int i = 0; i < Zombienum; ++i)
		{
			zombie_y[i] = zombie_y_p[zombie_y_idx[i]];
		}
		for_each(zombie_x.begin(), zombie_x.end(), [](int x) {std::cout << x << " "; });
	}
}

void init() {

	make_zombies();

	// 僵尸装入僵尸指针数组
	//zombie.push_back(new BasicZombie(1, 1, zombie_x[0], zombie_y[0]));
	for (int i = 0; i < Zombienum; i++) {
		Zombie* tmp;
		if (i < 1) {
			tmp = new CatapultZombie(1, 1, zombie_x[i], zombie_y[i]);
		}
		else if (i < 6) {
			tmp = new BasicZombie(1, 1, zombie_x[i], zombie_y[i]);
		}
		else if (i < 8) {
			tmp = new VaultingZombie(1, 1, zombie_x[i], zombie_y[i]);
		}
		else if (i < 11) {
			tmp = new ConeZombie(1, 1, zombie_x[i], zombie_y[i]);
		}
		else if (i < 13)
		{
			tmp = new BucketheadZombie(1, 1, zombie_x[i], zombie_y[i]);
		}
		else if (i < 18)
		{
			tmp = new BasicZombie(1, 1, zombie_x[i], zombie_y[i]);
		}
		else
		{
			tmp = new ScreenZombie(1, 1, zombie_x[i], zombie_y[i]);
		}

		zombie.push_back(tmp);
	}

}