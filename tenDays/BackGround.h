#pragma once
#include "Vec.h"
class BackGround
{
public:
	BackGround();

	~BackGround();

	void Load(const int& stageNum);

	void Update(int stageNum);

	void Draw(int stageNum, Vec2 scroll);

	void Release();
private:
	void StationAnimation();

	void SakuraAnimation();
private:
	//�Q�X�e�[�W��
	int ekihoka[5] = { -1,-1,-1,-1,-1 };
	int ekilight[5] = { -1,-1,-1,-1,-1 };;
	int train = -1;
	int trainPos = 0.0f;
	int stationNum = 0;
	//�R�X�e�[�W��
	int huji[21] = {};
	int sakuraNum = 0;
	//�S�X�e�[�W��
	int monnGround = -1;
	int monnsky = -1;
	int moonLoop = -1;

	int ekiBgm = -1;
	int fujiBgm = -1;
	int moonBgm = -1;
};

