#include "GameScene.h"
#include<vector>
using namespace std;

const Sound GameScene::clickCardSound(std::string("Clickcard.mp3"));

const GameScene* GameScene::getGameScene()
{
	static const GameScene instance;
	return &instance;
}

void GameScene::closeBGM() const
{ 
	BGM.close();
}

GameScene::GameScene() :Scene("lawn.jpg", "playing.mp3")
, shootercard("card//PeaShooterCard.jpg")
, flowercard("card//SunFlowerCard.jpg")
, nutcard("card//WALLnUTcARD.png")
, kuang("SunBank.png")
, jiangshitupian("ZombiesRemaining.jpg")
, snowpea("card//snowShooterCard.png")
, cherrybomb("card//CherryBomb.png")
, Repeatercard("card//RepeaterCard.png")
, Tallnutcard("card//TallNutCard.png")
, PumpkinCard("card//PumpkinCard.png")
, SquashCard("card//SquashCard.png")
, GarlicCard("card//GarlicCard.png")
{
}

void GameScene::RunScene() const	// ������Ϸ����
{
	/*const int WIDTH = 720;
	const int LENGTH = 1068;
	const int GRID_NUM_X = 7;
	const int GRID_NUM_Y = 3;
	const vector<int> GRID_BOUNDY = { 40, 200, 360, 520 };
	const vector<int> GRID_BOUNDX = { 0, 140, 280, 420, 560, 700,840,980 };
	const vector<int> GRID_BOUNDYX = { 80,120,160,240,280,320,400,440,480 };
	const wchar_t title[] = L"ֲ���ս��ʬ";
	const wchar_t store_title[] = L"���̵꡿ ����������";
	const wchar_t score_title[] = L"�����ĵ÷֡�";
	outtextxy(500, 10, title);
	for (int j = 0; j < GRID_BOUNDY.size(); ++j)
	{
		for (int i = 0; i < 1068; i = i + 10)
		{
			outtextxy(i, GRID_BOUNDY[j], '#');
			outtextxy(i, 560, '-');
		}
	}
	for (int i = 0; i < GRID_BOUNDYX.size(); ++i)
	{
		for (int j = 0; j < GRID_BOUNDX.size(); ++j)
		{
			outtextxy(GRID_BOUNDX[j], GRID_BOUNDYX[i], '#');
		}
	}


	outtextxy(0, 600, store_title);

	outtextxy(400, 600, score_title);

	FlushBatchDraw();*/
		background.put(0, 0);		// ��ʾ��Ϸ����
		//BGM.playRepeatedly();		// ������Ϸ����
		kuang.put(0, 0);			// ��ʾֲ����
		//jiangshitupian.put(590, 0); // ��ʾ��ʣ�ཀྵʬ����
		shootercard.put(95, 10);	// ��ʾ���ֿ�Ƭ
		flowercard.put(155, 10);	// ��ʾ���տ���Ƭ
		nutcard.put(215, 10);
		snowpea.put(275, 10);		// ��ʾ�������ֿ�Ƭ
		cherrybomb.put(335, 10);	// ��ʾӣ��ը����Ƭ
		Repeatercard.put(395, 10);  // ��ʾ˫������
		Tallnutcard.put(455, 10);  //��ʾ�߼��
		PumpkinCard.put(515, 10); //��ʾ�ϹϿ�Ƭ
		SquashCard.put(575, 10);  //��ʾ�ѹϿ�Ƭ
		GarlicCard.put(635, 10);
}

GameScene::~GameScene()
{
}


