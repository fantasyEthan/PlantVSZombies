#include "ModeScene.h"
#include"globalvariables.h"

int mode;
const ModeScene* ModeScene::getModeScene() {
	static const ModeScene instance;
	return &instance;
}

ModeScene::ModeScene() :Scene("ModeScene.jpg", "StartMusic.mp3") {
}

void ModeScene::RunScene() const {
	// œ‘ æª∂”≠ΩÁ√ÊÕº∆¨
	background.put(0, 0);
	/*outtextxy(30, 65, _T("≈≈––∞Ò"));
	for (int i = 0; i < 10; i++) {
		outtextxy(30, 65 + (i + 1) * 20, stringToTCHAR(std::to_string(rankingList[i])));
	}*/
	/*rectangle(500, 100, 780, 200);
	rectangle(490, 250, 770, 350);*/
	FlushBatchDraw();

	// ≤•∑≈±≥æ∞“Ù¿÷
	BGM.playRepeatedly();

	
	do 
	{
		m = GetMouseMsg();
		if (m.x >=500 && m.x<=780 && m.y>=100 && m.y <= 200)
		{
			mode = 1;
		}
		if (m.x >= 490 && m.x <= 770 && m.y >= 250 && m.y <= 350)
		{
			mode = 2;
		}
	} while (m.uMsg != WM_LBUTTONDOWN);

	BGM.close();							//πÿ±’BGM
}

ModeScene::~ModeScene()
{
}
