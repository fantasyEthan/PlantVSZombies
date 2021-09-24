#include <graphics.h>
#include<stdio.h>
#include "Sun.h"
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include <math.h>
#include <time.h>
#include <typeinfo>
#include "globalvariables.h"
#include "BasicZombie.h"
#include "NewspaperZombie.h"
#include "NoNewspaperZombie.h"
#include "ScreenZombie.h"
#include "JackZombie.h"
#include "same_row_col.h"
#include "globalVariables-objects.h"
#pragma comment(lib,"Winmm.lib")

void updateZombies();
void updatePlants();
void updateCars();
void updateShots();
void updateBalls();
void bulletsHitZombies();
void carHitZombies();
void ballsHitPlant();
void zomiesEatPlants();
void playSound1();

// 一轮更新只播放一次音效，以标记函数表明需要播放的音乐
bool has_hit = false;	// 标志本轮更新是否有子弹击中僵尸
bool has_eat = false;	// 标志本轮更新是否有僵尸吃植物

// 与输入无关的更新
void updateWithoutInput()
{
	if (zombie.empty()) {
		gameFlag = 1;
		return;
	}
	has_hit = false;
	has_eat = false;

	// 更新太阳
	Sun::getSun()->update();									

	// 更新僵尸
	updateZombies();

	// 更新植物
	updatePlants();

	// 更新小车
	updateCars();

	carHitZombies();

	// 更新子弹
	updateShots();

	updateBalls();

	
	// 子弹打僵尸	
	bulletsHitZombies();

	ballsHitPlant();

	// 僵尸吃植物
	zomiesEatPlants();

	  
	// 必要的延迟
	Sleep(170);

	// 判定游戏失败
	
	for (std::vector<Zombie*>::iterator iter = zombie.begin(); iter != zombie.end(); ) {
		if ((*iter)->getPozition_x() < 10) {		// 遍历僵尸，若有僵尸越过防线，僵尸消失，基地血量减一
			std::vector<Car*>::iterator iterC;
			for (iterC = car.begin(); iterC != car.end(); ++iterC)
			{
				if (is_same_row((*iter)->getPozition_y(),(*iterC)->getPozition_y()))
				{
					(*iterC)->setAnimationStatus(1);
					(*iterC)->setMoveStatus(1);
					(*iterC)->setSpeed_x(10);
					break;
				}
			}
			if (iterC == car.end())
			{
				gameFlag = -1;
				return;
			}
			Zombie::killNum++;
			iter = zombie.erase(iter);
			Car::BaseHp--;
		} else {
			++iter;
		}
		if ((Zombie::killNum >= rankingList[9] && Car::BaseHp <= 0) ) {
			gameFlag = 1;
		}
		if (Zombie::killNum < rankingList[9] && Car::BaseHp <= 0) {
			gameFlag = -1;
		}
	}
	return;
}

void updateZombies() {
	for (std::vector<Zombie*>::iterator iter = zombie.begin(); iter != zombie.end(); ) {
		(*iter)->update();													// 遍历更新僵尸对象

		if ((*iter)->getHealthPoint() <= 0)									// 判定僵尸是否死亡，若死亡则移出动态数组
		{
			if ((*iter)->getType() == "BasicZombie" || (*iter)->getType() == "NoNewspaperZombie" || (*iter)->getType() == "JackZombie" || (*iter)->getType() == "CatapultZombie"){
				Zombie::killNum++;
				delete (*iter);
				iter = zombie.erase(iter);
			}
			else
			{
				if ((*iter)->getType() == "Basketball")
				{
					delete (*iter);
					iter = zombie.erase(iter);
				}
				else if ((*iter)->getType() == "ScreenZombie") {
					BasicZombie* newBody = new BasicZombie(1, 1, (*iter)->getPozition_x() + 10, (*iter)->getPozition_y());
					{
						newBody->setSpeed_x(-2);
						newBody->setAttack(100);
					}
					delete (*iter);
					iter = zombie.erase(iter);
					zombie.push_back(newBody);
				}
				else if ((*iter)->getType() == "ConeZombie")
				{
					BasicZombie* newBody = new BasicZombie(1, 1, (*iter)->getPozition_x() + 10, (*iter)->getPozition_y());
					{
						newBody->setSpeed_x(-2);
						newBody->setAttack(100);
					}
					delete (*iter);
					iter = zombie.erase(iter);
					zombie.push_back(newBody);
				}
				else if ((*iter)->getType() == "BucketheadZombie")
				{
					BasicZombie* newBody = new BasicZombie(1, 1, (*iter)->getPozition_x() + 10, (*iter)->getPozition_y());
					{
						newBody->setSpeed_x(-2);
						newBody->setAttack(100);
					}
					delete (*iter);
					iter = zombie.erase(iter);
					zombie.push_back(newBody);
				}
				else if ((*iter)->getType() == "VaultingZombie")
				{
					BasicZombie* newBody = new BasicZombie(1, 1, (*iter)->getPozition_x() + 10, (*iter)->getPozition_y());
					{
						newBody->setSpeed_x(-2);
						newBody->setAttack(100);
					}
					delete (*iter);
					iter = zombie.erase(iter);
					zombie.push_back(newBody);
				}
				else if ((*iter)->getType() == "NewspaperZombie")
				{
					NoNewspaperZombie* newBody = new NoNewspaperZombie(1, 1, (*iter)->getPozition_x() + 10, (*iter)->getPozition_y());
					{
						newBody->setSpeed_x(-8);
						newBody->setAttack(100);
					}
					delete (*iter);
					iter = zombie.erase(iter);
					zombie.push_back(newBody);
				}
			}
			
		}
		else {
			iter++;
		}
	}
}
void updatePlants() {
	for (std::vector<Plant*>::iterator iter = plant.begin(); iter != plant.end();) {
		(*iter)->update();													 // 遍历更新植物对象
		
		if ((*iter)->getHealthPoint() <= 0) {									 // 判定植物是否被吃掉，若被吃掉则移出动态数组
			map[((*iter)->getPozition_y() - PY) / sizehigh][((*iter)->getPozition_x() - PX) / sizewidth] = false;
			delete (*iter);
			iter = plant.erase(iter);
		}
		else {
			iter++;
		}
	}
	if (plantFollowMouse)													 // 更新跟随鼠标的植物
		plantFollowMouse->update();
}

void updateCars()
{
	for (std::vector<Car*>::iterator iter = car.begin(); iter != car.end();) {
		(*iter)->update();													 // 遍历更新小车对象
		if ((*iter)->getPozition_x() > Width)
		{
			delete (*iter);
			iter = car.erase(iter);
		}
		else
		{
			++iter;
		}
		
	}
}

void carHitZombies()
{
	for (std::vector<Car*>::iterator iterB = car.begin(); iterB != car.end();++iterB) {
		for (std::vector<Zombie*>::iterator iterZ = zombie.begin(); iterZ != zombie.end(); ) {

			// 若子弹和僵尸同一行且在击中范围内则视为击中
			if ((*iterB)->getmoveStatus() == 1 && (is_same_row((*iterZ)->getPozition_y(),(*iterB)->getPozition_y())) && (*iterB)->getPozition_x() >= (*iterZ)->getPozition_x() - 20 && (*iterB)->getPozition_x() <= (*iterZ)->getPozition_x() + 20) {
				(*iterZ)->setHealthPoint(0);													
				delete (*iterZ);															    
				iterZ = zombie.erase(iterZ);
			}
			else {
				iterZ++;
			}
		}
	}
}
void updateShots() {
	for (std::vector<Bullet*>::iterator iter = bullet.begin(); iter != bullet.end(); ) {
		(*iter)->update();													  // 遍历更新子弹对象

		if ((*iter)->getPozition_x() > Width) {							  // 判定子弹出框，若出框则移出动态数组（消失）
			delete (*iter);
			iter = bullet.erase(iter);
		}
		else {
			if ((*iter)->getbulletType() == 3)
			{
				(*iter)->setAttack((15 - Car::BaseHp) * 3 + 5);						//小车发射的子弹随基地血量减少攻击力增强
			}
			iter++;
		}
	}
}


void updateBalls()
{
	for (std::vector<Ball*>::iterator iter = ball.begin(); iter != ball.end(); ) {
		(*iter)->update();													  // 遍历更新子弹对象

		if ((*iter)->getPozition_x() < 10 ) {							  // 判定子弹出框，若出框则移出动态数组（消失）
			delete (*iter);
			iter = ball.erase(iter);
		}
		else
		{
			++iter;
		}
	}
}


void bulletsHitZombies() {
	// 遍历僵尸、子弹判定子弹击中僵尸
	for (std::vector<Zombie *>::iterator iterZ = zombie.begin(); iterZ != zombie.end(); iterZ++) {
		for (std::vector<Bullet *>::iterator iterB = bullet.begin(); iterB != bullet.end(); ) {
			// 若子弹和僵尸同一行且在击中范围内则视为击中
			if (map_y.at((*iterB)->getPozition_y() - 5) == map_y.at((*iterZ)->getPozition_y()) && (*iterB)->getPozition_x() >= (*iterZ)->getPozition_x() + 35 && (*iterB)->getPozition_x() <= (*iterZ)->getPozition_x() + 100) {
				(*iterZ)->setHealthPoint((*iterZ)->getHealthPoint()-((*iterB)->getAttack()));	// 僵尸掉血
				if ((*iterB)->getbulletType() == 2)
				{
					(*iterZ)->setslowDown(1);
				}																				//新逻辑，寒冰豌豆减速僵尸
				delete (*iterB);															    // 子弹移出动态数组（消失）
				iterB = bullet.erase(iterB);								
				has_hit = true;
			} else {
				iterB++;
			}
		}
	}
}

void ballsHitPlant() {
	// 遍历僵尸、子弹判定子弹击中僵尸
	for (std::vector<Plant*>::iterator iterZ = plant.begin(); iterZ != plant.end(); iterZ++) {
		for (std::vector<Ball*>::iterator iterB = ball.begin(); iterB != ball.end(); ) {
			// 若子弹和僵尸同一行且在击中范围内则视为击中
			if (map_y.at((*iterB)->getPozition_y() - 5) == map_y.at((*iterZ)->getPozition_y()) && (*iterB)->getPozition_x() <= (*iterZ)->getPozition_x() + 20 ) {
				(*iterZ)->setHealthPoint((*iterZ)->getHealthPoint() - ((*iterB)->getAttack()));	// 植物掉血
				delete (*iterB);															    // 子弹移出动态数组（消失）
				iterB = ball.erase(iterB);
				//has_hit = true;
			}
			else {
				iterB++;
			}
		}
	}
}

void zomiesEatPlants() {
	// 遍历僵尸、植物判定僵尸吃植物

	for (std::vector<Plant*>::iterator iterP = plant.begin(); iterP != plant.end(); iterP++) {
		for (std::vector<Zombie*>::iterator iterZ = zombie.begin(); iterZ != zombie.end(); iterZ++) {
			if (map_y.at((*iterP)->getPozition_y()) == map_y.at((*iterZ)->getPozition_y()) && ((*iterZ)->getPozition_x() > (*iterP)->getPozition_x() + 10) && ((*iterZ)->getPozition_x() < (*iterP)->getPozition_x() + 30)) {
				has_eat = 1;
				(*iterZ)->setMoveStatus(0);														// 僵尸吃植物期间不动
				(*iterP)->setHealthPoint((*iterP)->getHealthPoint() - ((*iterZ)->getAttack())); // 植物掉血 
			}
		}

		if ((*iterP)->getHealthPoint() <= 0) {													
			for (std::vector<Zombie*>::iterator iterZ = zombie.begin(); iterZ != zombie.end(); iterZ++) {
				if (map_y.at((*iterP)->getPozition_y()) == map_y.at((*iterZ)->getPozition_y()) && ((*iterZ)->getPozition_x() > (*iterP)->getPozition_x() + 10) && ((*iterZ)->getPozition_x() < (*iterP)->getPozition_x() + 30)) {											// 若吃掉，僵尸恢复移动
						(*iterZ)->setMoveStatus(1);
				}
				
			}
		}
	}
}
void playSound1() {
	// 播放本次更新的音效，啃咬声优先于击打声
	if (has_eat) {
		jpmusic1->close();
		jpmusic1 = &(Zombie::eatSound);
		jpmusic1->play();
	} else if (has_hit) {
		jpmusic1->close();
		jpmusic1 = &(Bullet::hitSound);
		jpmusic1->play();
	}
}

