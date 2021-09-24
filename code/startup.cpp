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

// 全局变量、全局对象定义（注释见两个全局变量头文件）
bool map[5][9];
int sunshineNum = 50;		
int gameFlag = 0;	
const vector<int> GRID_BOUNDY = { 40, 200, 360, 520 };
const vector<int> GRID_BOUNDX = { 0, 140, 280, 420, 560, 700,840,980 };
const vector<int> GRID_BOUNDYX = { 80,120,160,240,280,320,400,440,480 };


int car_x[Carnum] = { -5,-5,-5,-5,-5 };
int car_y[Carnum] = { 85,185,285,385,485 };

std::vector<Zombie *>zombie;
std::vector<Bullet *>bullet;
std::vector<Plant*> plant;
std::vector<Car*> car;
std::vector<Ball*> ball;
std::map<int, int> map_x;
std::map<int, int> map_y;
Plant* plantFollowMouse = NULL;
MOUSEMSG m;
const Sound* jpmusic1 = &(Bullet::hitSound);
const Sound* jpmusic2 = &(Bullet::hitSound);

extern void loadRankingList();

// 全局变量、全局对象初始化
void startup() {

	memset(map, 0, sizeof(map));

	loadRankingList();

	// 小车装入小车指针数组
	for (int i = 0; i < Carnum; i++) {
		car.push_back(new Car(1, 0, car_x[i], car_y[i]));
	}

	// 定义坐标数到草坪行/列数的映射，方便射手判断本行是否有僵尸
	for (int i = 0; i < size1; i++)						// 定义植物纵坐标到草坪行数的映射
		map_y.insert(std::pair<int, int>(PY + sizehigh * i, i));
	for (int j = 0; j < size2; j++)						// 定义植物横坐标到草坪列数的映射
		map_x.insert(std::pair<int, int>(PX + sizewidth * j, j));
	map_y.insert(std::pair<int, int>(80, 0));			// 定义僵尸纵坐标到草坪行数的映射
	map_y.insert(std::pair<int, int>(150, 1));
	map_y.insert(std::pair<int, int>(250, 2));
	map_y.insert(std::pair<int, int>(350, 3));
	map_y.insert(std::pair<int, int>(450, 4));

	// 定义图形窗口
	initgraph(Width, High);							   // 初始化图形窗口
	HWND hWnd = GetHWnd();							   // 获取窗口句柄
	SetWindowText(hWnd, _T("植物大战僵尸"));			   // 设定窗口名：“植物大战僵尸”
	BeginBatchDraw();								   //开启批量绘图模式
}