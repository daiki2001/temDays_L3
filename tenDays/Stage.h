#pragma once
#include "Vec.h"
#include <DxLib.h>
#include <vector>

enum StageType
{
	BOX,
	TRIANGLE,
	FLOOR,
	MOVEBOX,
};
enum AreaType
{
	FOREST,   //森面
	STATION,  //駅面
	FUJI,     //富士山面
	UNIVERSE, //宇宙面
};
struct BoxData
{
	Vec2 pos;
	Vec2 size;
	int type = 0;
	Vec2 minPos = {};
	Vec2 maxPos = {};
	bool isMoveFlag = false;
};

class Stage
{
private: //静的メンバ変数
	//現在のステージ番号
	static int stageNum;
	static AreaType areaType;

public: //静的メンバ関数
	static void SetStageNum(const int& stageNum);
	static int GetStageNum() { return stageNum; }
	static AreaType GetAreaType() { return areaType; }
public:
	Stage();

	~Stage();

	void Init();

	void CreateStage();

	void Update();

	void Draw(Vec2 scroll);

	void StageAddOne();
private:

	// ファイルの読み込み
	void Load();
private://メンバ関数
	//１ステージ目
	void StageOne();
	//2ステージ目
	void StageTwo();
	//３ステージ目
	void StageThree();
	//４ステージ目
	void StageFour();
	//５ステージ目
	void StageFive();
	//６ステージ目
	void StageSix();
public:
	Vec2 GetBoxPos(int i) { if (boxData.size() > i) { return boxData[i]->pos; } return Vec2(); }

	Vec2 GetBoxSize(int i) { if (boxData.size() > i) { return boxData[i]->size; }return Vec2(); }

	int GetBoxDataNum() { return boxData.size(); }


	int GetType(int i) { if (boxData.size() > i) { return boxData[i]->type; }return 0; }

private://メンバ変数

	std::vector<BoxData*>boxData;

	int cubeBlock = -1; //ブロックの画像(正方形)
	int triangleBlock = -1; //ブロックの画像(三角形)
	//場所２
	int cubeBlock2 = -1; //ブロックの画像(正方形)
	int triangleBlock2 = -1; //ブロックの画像(三角形)
	//場所３
	int cubeBlock3 = -1; //ブロックの画像(正方形)
	int triangleBlock3 = -1; //ブロックの画像(三角形)
	//場所４
	int cubeBlock4 = -1; //ブロックの画像(正方形)
	int triangleBlock4 = -1; //ブロックの画像(三角形)
};

