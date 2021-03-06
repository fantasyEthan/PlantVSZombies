#include <graphics.h>
#include<iostream>
#include<stdio.h>
#include "Sun.h"
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include <math.h>
#include <time.h>
#include "PeaShooter.h"
#include "SunFlower.h"
#include "Squash.h"
#include "WallNut.h"
#include"Repeater.h"
#include "SnowPea.h"
#include "CherryBomb.h"
#include "GameScene.h"
#include "Pumpkin.h"
#include "Garlic.h"
#include"HighWallNuts.h"
#include "globalvariables.h"
#include "globalVariables-objects.h"

void selectPlant();
void plantPlant();
void giveupPlant();
void catchSun();
void playSound2();
void updateCooltime();
void stop();
void start();

// 一轮更新只播放一次音效，以标记函数表明需要播放的音乐
bool has_select = false;		// 标志本轮更新是否有植物被选中
bool has_plant = false;			// 标志本轮更新是否有植物被种植
bool has_catch = false;			// 标志本轮更新是否有阳光被捕捉
bool has_stopped = false;       // 标志本轮更新是否有暂停

void updateWithInput() 
{
	//has_stopped = false;
	has_select = false;
	has_plant = false;
	has_catch = false;
	updateCooltime();
	while (MouseHit()) {					
		m = GetMouseMsg();

		if (m.uMsg != WM_LBUTTONDOWN) {				// 检测有效鼠标点击（左键点击）
			continue;
		}

		if ((m.x >= 700) && (m.x <= 800) && (m.y >= 15) && (m.y <= 65))
		{
			has_stopped = !has_stopped;
			
			if (has_stopped)
			{
				has_stopped = true;
				stop();
				continue;
			}
			else
			{
				start();
			}
			
		}



		// 若左键点击太阳，则拾取太阳
		if ((m.x >= Sun::getSun()->getPozition_x()) && (m.x < Sun::getSun()->getPozition_x() + 100) && (m.y > Sun::getSun()->getPozition_y()) && (m.y < Sun::getSun()->getPozition_y() + 100)) {
			catchSun();
			break;						// break防止有重合的元素被一起点击 
		}

		// 若左键点击植物栏内
		if ((m.x >= 95) && (m.x < 800) && (m.y >= 10) && (m.y < 80)) {
			if (!plantFollowMouse) {	// 若当前没有选中植物，则选中植物
				selectPlant();
			}
			else {
				giveupPlant();			// 若当前已经选中植物，则把植物放回去
			}
			break;
		}

		// 若当前已选中植物且点击在草坪内，则种植植物
		if(plantFollowMouse && (m.x > PX + sizewidth * 0) && (m.x < PX + sizewidth * (size2 + 1)) && (m.y > PY + sizehigh * 0) && (m.y < PY + sizehigh * (size1 + 1))) {
			plantPlant();
			break;
		}
	}

	// 播放本轮更新音效
	playSound2();
}

void selectPlant() {
	// 当前没有选中植物，选中植物
	has_select = true;
	// 若点到豌豆射手卡片且钱足够
	if (sunshineNum >= PeaShooter::getPlantPrice() && (m.x >= 95) && (m.x < 145) && (m.y >= 10) && (m.y < 80)) {
		if (PeaShooter::getCooltime() <= 0)
		{
			plantFollowMouse = new PeaShooter(0, 2, m.x - 30, m.y - 30);
			PeaShooter::cooltime = 40;
		}
		else
		{
			std::cout << "Cooling" << std::endl;
		}
		
	}
	// 若点到向日葵卡片且钱足够
	else if (sunshineNum >= SunFlower::getPlantPrice() && (m.x >= 155) && (m.x < 205) && (m.y >= 10) && (m.y < 80)) {
		if (SunFlower::getCooltime() <= 0)
		{
			plantFollowMouse = new SunFlower(0, 2, m.x - 30, m.y - 30);
			SunFlower::cooltime = 20;
		}
		else
		{
			std::cout << "Cooling" << std::endl;
		}
		
	}
	//若点到双发射手且钱足够
	
	//若点到坚果且钱足够
	else if (sunshineNum >= WallNut::getPlantPrice() && (m.x >= 215) && (m.x < 265) && (m.y >= 10) && (m.y < 80)) {
		if (WallNut::getCooltime() <= 0)
		{
			plantFollowMouse = new WallNut(0, 2, m.x - 30, m.y - 30);
			WallNut::cooltime = 50;
		}
		else
		{
			std::cout << "Cooling" << std::endl;
		}
		
	}
	// 若点到寒冰射手卡片并且钱足够
	else if (sunshineNum >= SnowPea::getPlantPrice() && (m.x >= 275) && (m.x < 325) && (m.y >= 10) && (m.y < 80)) {
		if (SnowPea::getCooltime() <= 0)
		{
			plantFollowMouse = new SnowPea(0, 2, m.x - 30, m.y - 30);
			SnowPea::cooltime = 60;
		}
		else
		{
			std::cout << "Cooling" << std::endl;
		}
		
	}
	// 若点到樱桃炸弹卡片并且钱足够
	else if (sunshineNum >= CherryBomb::getPlantPrice() && (m.x >= 335) && (m.x < 385) && (m.y >= 10) && (m.y < 80)) {
		if (CherryBomb::getCooltime() <= 0)
		{
			plantFollowMouse = new CherryBomb(0, 2, m.x - 30, m.y - 30);
			CherryBomb::cooltime = 80;
		}
		else
		{
			std::cout << "Cooling" << std::endl;
		}
		
	}
	else if (sunshineNum >= Repeater::getPlantPrice() && (m.x >= 395) && (m.x < 445) && (m.y >= 10) && (m.y < 80))
	{
		if (Repeater::getCooltime() <= 0)
		{
			plantFollowMouse = new Repeater(0, 2, m.x - 30, m.y - 30);
			Repeater::cooltime = 60;
		}
		else
		{
			std::cout << "Cooling" << std::endl;
		}
		
	}
	else if (sunshineNum >= HighWallNut::getPlantPrice() && (m.x >= 455) && (m.x < 505) && (m.y >= 10) && (m.y < 80)) {
		if (HighWallNut::getCooltime() <= 0)
		{
			plantFollowMouse = new HighWallNut(0, 2, m.x - 30, m.y - 30);
			HighWallNut::cooltime = 70;
		}
		else
		{
			std::cout << "Cooling" << std::endl;
		}
		
	}
	else if (sunshineNum >= Pumpkin::getPlantPrice() && (m.x >= 515) && (m.x < 565) && (m.y >= 10) && (m.y < 80)) {
		if (Pumpkin::getCooltime() <= 0)
		{
			plantFollowMouse = new Pumpkin(0, 2, m.x - 30, m.y - 30);
			Pumpkin::cooltime = 60;
		}
		else
		{
			std::cout << "Cooling" << std::endl;
		}
	}
	else if (sunshineNum >= Squash::getPlantPrice() && (m.x >= 575) && (m.x < 625) && (m.y >= 10) && (m.y < 80)) {
		if (Squash::getCooltime() <= 0)
		{
			plantFollowMouse = new Squash(0, 2, m.x - 30, m.y - 30);
			Squash::cooltime = 80;
		}
		else
		{
			std::cout << "Cooling" << std::endl;
		}
	}
	else if (sunshineNum >= Garlic::getPlantPrice() && (m.x >= 635) && (m.x < 685) && (m.y >= 10) && (m.y < 80)) {
		if (Garlic::getCooltime() <= 0)
		{
			plantFollowMouse = new Garlic(0, 2, m.x - 30, m.y - 30);
			Garlic::cooltime = 80;
		}
		else
		{
			std::cout << "Cooling" << std::endl;
		}
	}
}

void plantPlant() {
	// 当前已有选中的植物，放置植物

	bool is_find = 0;													// 标记有没有找到对应的草坪块
	for (int i = 0; i < size1 && !is_find; i++) {
		for (int j = 0; j < size2 && !is_find; j++) {
			if ((m.x > PX + sizewidth * j) && (m.x < PX + sizewidth * (j + 1)) && (m.y > PY + sizehigh * i) && (m.y < PY + sizehigh * (i + 1))) {
				// 若找到对应的草坪块，则放置植物
				if (!map[i][j] || plantFollowMouse->getType() == "Pumpkin") {
					plantFollowMouse->setPozition_x(PX + sizewidth * j);	// 设定x坐标
					plantFollowMouse->setPozition_y(PY + sizehigh * i);		// 设定y坐标
					plantFollowMouse->setMoveStatus(0);					// 设定运动状态为静止
					plantFollowMouse->setAnimationStatus(1);				// 设定动画状态为动态
					plant.push_back(plantFollowMouse);						// 加入植物动态数组
					sunshineNum = sunshineNum - plantFollowMouse->getPrice();			// 消耗相应阳光数
					map[i][j] = true;
					has_plant = true;
					is_find = 1;
					plantFollowMouse = NULL;								// plantFollowMouse切换为未选中植物，这步很重要！
				}
			}
		}
	}
}

void catchSun() {
	//点中太阳，太阳重新生成，分数加50
	has_catch = true;
	Sun::getSun()->setPozition_x(rand() % (Width - 100)) ;
	Sun::getSun()->setPozition_y(-400);
	sunshineNum = sunshineNum + 50;
}

void giveupPlant() { // 放弃种植
	plantFollowMouse = NULL;
}

void playSound2() {
	if (has_select) {
		jpmusic2->close();
		jpmusic2 = &(GameScene::getGameScene()->clickCardSound);
		jpmusic2->play();
	}
	else if (has_plant) {
		jpmusic2->close();
		jpmusic2 = &(Plant::plantSound);
		jpmusic2->play();
	}
	else if (has_catch) {
		jpmusic2->close();
		jpmusic2 = &(Sun::catchSound);
		jpmusic2->play();
	}
}

void updateCooltime()
{
	if (PeaShooter::getCooltime() > 0)
	{
		PeaShooter::cooltime--;
	}
	if (SunFlower::getCooltime() > 0)
	{
		SunFlower::cooltime--;
	}
	if (WallNut::getCooltime() > 0)
	{
		WallNut::cooltime--;
	}
	if (SnowPea::getCooltime() > 0)
	{
		SnowPea::cooltime--;
	}
	if (CherryBomb::getCooltime() > 0)
	{
		CherryBomb::cooltime--;
	}
	if (Repeater::getCooltime() > 0)
	{
		Repeater::cooltime--;
	}
	if (HighWallNut::getCooltime() > 0)
	{
		HighWallNut::cooltime--;
	}
	if (Pumpkin::getCooltime() > 0)
	{
		Pumpkin::cooltime--;
	}
	if (Squash::getCooltime() > 0)
	{
		Squash::cooltime--;
	}
	if (Garlic::getCooltime() > 0)
	{
		Garlic::cooltime--;
	}
}

void stop()
{
	for (auto iter = zombie.begin(); iter != zombie.end(); ++iter)
	{
		(*iter)->setMoveStatus(0);
		(*iter)->setAnimationStatus(0);
	}
	for (auto iter = ball.begin(); iter != ball.end(); ++iter)
	{
		(*iter)->setMoveStatus(0);
	}
	for (auto iter = bullet.begin(); iter != bullet.end(); ++iter)
	{
		(*iter)->setMoveStatus(0);
	}
	for (auto iter = plant.begin(); iter != plant.end(); ++iter)
	{
		(*iter)->setAnimationStatus(0);
	}
}

void start()
{
	for (auto iter = zombie.begin(); iter != zombie.end(); ++iter)
	{
		(*iter)->setMoveStatus(1);
		(*iter)->setAnimationStatus(1);
	}
	for (auto iter = bullet.begin(); iter != bullet.end(); ++iter)
	{
		(*iter)->setMoveStatus(1);
	}
	for (auto iter = plant.begin(); iter != plant.end(); ++iter)
	{
		(*iter)->setAnimationStatus(1);
	}
}