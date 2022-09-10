#pragma once
#include"Vec.h"
#include<DxLib.h>
#include<vector>
struct BoxData
{
	Vec2 pos;
	Vec2 size;
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
private://メンバ関数
	//１ステージ目
	void StageOne();
	//2ステージ目
	void StageTwo();
public:
	Vec2 GetBoxPos(int i) { if (boxData.size() > i) { return boxData[i]->pos; } return Vec2(); }

	Vec2 GetBoxSize(int i) { if (boxData.size() > i) { return boxData[i]->size; }return Vec2(); }

	int GetBoxDataNum() { return boxData.size(); }
private://メンバ変数
	std::vector<BoxData*>boxData;
	//現在のステージ番号
	int stageNum = 1;
};

