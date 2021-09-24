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

void GameScene::RunScene() const	// 运行游戏界面
{
	/*const int WIDTH = 720;
	const int LENGTH = 1068;
	const int GRID_NUM_X = 7;
	const int GRID_NUM_Y = 3;
	const vector<int> GRID_BOUNDY = { 40, 200, 360, 520 };
	const vector<int> GRID_BOUNDX = { 0, 140, 280, 420, 560, 700,840,980 };
	const vector<int> GRID_BOUNDYX = { 80,120,160,240,280,320,400,440,480 };
	const wchar_t title[] = L"植物大战僵尸";
	const wchar_t store_title[] = L"【商店】 阳光总数：";
	const wchar_t score_title[] = L"【您的得分】";
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
		background.put(0, 0);		// 显示游戏画面
		//BGM.playRepeatedly();		// 播放游戏音乐
		kuang.put(0, 0);			// 显示植物栏
		//jiangshitupian.put(590, 0); // 显示“剩余僵尸数”
		shootercard.put(95, 10);	// 显示射手卡片
		flowercard.put(155, 10);	// 显示向日葵卡片
		nutcard.put(215, 10);
		snowpea.put(275, 10);		// 显示寒冰射手卡片
		cherrybomb.put(335, 10);	// 显示樱桃炸弹卡片
		Repeatercard.put(395, 10);  // 显示双发射手
		Tallnutcard.put(455, 10);  //显示高坚果
		PumpkinCard.put(515, 10); //显示南瓜卡片
		SquashCard.put(575, 10);  //显示窝瓜卡片
		GarlicCard.put(635, 10);
}

GameScene::~GameScene()
{
}


