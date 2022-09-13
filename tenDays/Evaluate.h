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
	//�J�n����
	void Start();
	//�X�e�[�W���Ƃ̕]���b���ݒ�
	void SetEvaluate(int stageNum);

	int GetStarNum() { return starNum; }
private:
	void Load();
private:
	//�J�n�̎���
	std::chrono::system_clock::time_point  start;
	//�I�����̎���
	std::chrono::system_clock::time_point end;
	//���݂̎���
	double time = 0.0;
	//�ő�]����
	static const int evaNumMax = 2;
	//�X�e�[�W���Ƃ̕]������
	float  stageEvaTime[evaNumMax];
	//�l���ł��鐯�̐�
	int starNum = 0;
	//���v�̉摜
	int watchGraph = -1;
	//�N���A���̉摜
	int clearGraph[3] = { -1,-1,-1 };
	//�����摜
	int numberGraph[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	//:�̉摜
	int colonGraph = -1;
};

