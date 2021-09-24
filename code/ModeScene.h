#pragma once
#pragma once
#include "Scene.h"

/*
 *  ModeScene 模式选择界面类声明
 *  文件名：ModeScene.h
 *  相关文件：Scene.h, ModeScene.cpp
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
