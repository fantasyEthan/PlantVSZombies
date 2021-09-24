#include "Ball.h"
#include "Basketball.h"
#include "globalVariables-objects.h"
#include <cstdio>
#include "same_row_col.h"

Basketball::Basketball(int  as, int  ms, int vx, int  po_x, int  po_y, int hp, int atk, std::string type, int b) :Zombie(as, ms, vx, po_x, po_y, hp, atk, "Basketball"), bulletType(b), isempty(false)
{
}

Basketball::~Basketball()
{
}

void Basketball::update()
{
	bool hasPlant = false;			// ǰ���Ƿ���ֲ��
	
	for (std::vector<Plant*>::iterator iterZ = plant.begin(); iterZ != plant.end(); iterZ++) {
		if (is_same_row(getPozition_y(),(*iterZ)->getPozition_y())) {
			hasPlant = true;
		}
	}
	if (hasPlant && (!workCounter) && (!isempty)) {
		switch (bulletType) {
		case 1:
			ball.push_back(new Ball(position_x, position_y + 5));
			ballNum++;
			break;
		default:
			break;
		}
		workCounter = 8;
	}
	if (ballNum > 3)
	{
		isempty = true;
	}
	if (workCounter)				// �㶹��������ж�ͬ�н�ʬ+����ʱ�ƣ�
		workCounter--;				// ������ʱΪ����ǰ���н�ʬ�������㶹����ʼ�µĵ���ʱ��
									// ������ʱΪ����ǰ���޽�ʬ�����ֵ���ʱΪ��ֱ��ǰ�����ֽ�ʬ��
}
