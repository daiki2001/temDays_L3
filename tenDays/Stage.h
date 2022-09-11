#pragma once
#include"Vec.h"
#include<DxLib.h>
#include<vector>
struct BoxData
{
	Vec2 pos;
	Vec2 size;
	int type = 0;
};

class Stage
{
public:
	Stage();

	~Stage();

	void Init();

	void CreateStage();

	void Update();

	void Draw();

	void StageAddOne();

	int GetStageNum() { return stageNum; }
private://�����o�֐�
	//�P�X�e�[�W��
	void StageOne();
	//2�X�e�[�W��
	void StageTwo();
public:
	Vec2 GetBoxPos(int i) { if (boxData.size() > i) { return boxData[i]->pos; } return Vec2(); }

	Vec2 GetBoxSize(int i) { if (boxData.size() > i) { return boxData[i]->size; }return Vec2(); }

	int GetBoxDataNum() { return boxData.size(); }

	int GetType(int i) { if (boxData.size() > i) { return boxData[i]->type; }return 0; }
private://�����o�ϐ�
	std::vector<BoxData*>boxData;
	//���݂̃X�e�[�W�ԍ�
	int stageNum = 1;
};

