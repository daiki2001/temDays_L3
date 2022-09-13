#pragma once
#include<chrono>
#include<DxLib.h>
class Evaluate
{
public:

	Evaluate();

	~Evaluate();

	void Init(int stageNum);

	void Update();

	void PlayDraw();

	void GoalDraw();
	//開始時間
	void Start();
	//ステージごとの評価秒数設定
	void SetEvaluate(int stageNum);

	int GetStarNum() { return starNum; }
private:
	void Load();
private:
	//開始の時間
	std::chrono::system_clock::time_point  start;
	//終了時の時間
	std::chrono::system_clock::time_point end;
	//現在の時間
	double time = 0.0;
	//最大評価数
	static const int evaNumMax = 2;
	//ステージごとの評価時間
	float  stageEvaTime[evaNumMax];
	//獲得できる星の数
	int starNum = 0;
	//時計の画像
	int watchGraph = -1;
	//クリア時の画像
	int clearGraph[3] = { -1,-1,-1 };
	//数字画像
	int numberGraph[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	//:の画像
	int colonGraph = -1;
};

