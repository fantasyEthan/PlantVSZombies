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

// ȫ�ֱ�����ȫ�ֶ����壨ע�ͼ�����ȫ�ֱ���ͷ�ļ���
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

// ȫ�ֱ�����ȫ�ֶ����ʼ��
void startup() {

	memset(map, 0, sizeof(map));

	loadRankingList();

	// С��װ��С��ָ������
	for (int i = 0; i < Carnum; i++) {
		car.push_back(new Car(1, 0, car_x[i], car_y[i]));
	}

	// ��������������ƺ��/������ӳ�䣬���������жϱ����Ƿ��н�ʬ
	for (int i = 0; i < size1; i++)						// ����ֲ�������굽��ƺ������ӳ��
		map_y.insert(std::pair<int, int>(PY + sizehigh * i, i));
	for (int j = 0; j < size2; j++)						// ����ֲ������굽��ƺ������ӳ��
		map_x.insert(std::pair<int, int>(PX + sizewidth * j, j));
	map_y.insert(std::pair<int, int>(80, 0));			// ���彩ʬ�����굽��ƺ������ӳ��
	map_y.insert(std::pair<int, int>(150, 1));
	map_y.insert(std::pair<int, int>(250, 2));
	map_y.insert(std::pair<int, int>(350, 3));
	map_y.insert(std::pair<int, int>(450, 4));

	// ����ͼ�δ���
	initgraph(Width, High);							   // ��ʼ��ͼ�δ���
	HWND hWnd = GetHWnd();							   // ��ȡ���ھ��
	SetWindowText(hWnd, _T("ֲ���ս��ʬ"));			   // �趨����������ֲ���ս��ʬ��
	BeginBatchDraw();								   //����������ͼģʽ
}