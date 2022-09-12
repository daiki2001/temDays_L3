#pragma once
#include "Vec.h"
#include <DxLib.h>
#include <vector>
enum StageType
{
	BOX,
	TRIANGLE,
	FLOOR,
};
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
private:

	// ファイルの読み込み
	void Load();
private://メンバ関数
	//１ステージ目
	void StageOne();
	//2ステージ目
	void StageTwo();
public:
	Vec2 GetBoxPos(int i) { if (boxData.size() > i) { return boxData[i]->pos; } return Vec2(); }

	Vec2 GetBoxSize(int i) { if (boxData.size() > i) { return boxData[i]->size; }return Vec2(); }

	int GetBoxDataNum() { return boxData.size(); }


	int GetType(int i) { if (boxData.size() > i) { return boxData[i]->type; }return 0; }
private:

private://メンバ変数

	std::vector<BoxData*>boxData;
	//現在のステージ番号
	int stageNum = 1;

	int cubeBlock = -1; //ブロックの画像(正方形)
	int triangleBlock = -1; //ブロックの画像(三角形)
};

