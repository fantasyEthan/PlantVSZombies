#pragma once
#pragma once
#include "Scene.h"

/*
 *  ModeScene ģʽѡ�����������
 *  �ļ�����ModeScene.h
 *  ����ļ���Scene.h, ModeScene.cpp
 */
class ModeScene :public Scene
{
public:
	static const ModeScene* getModeScene();
	virtual void RunScene() const;
	virtual ~ModeScene();
private:
	ModeScene();
};
