#pragma once
#include "Vec.h"

class Goal
{
private: //�����o�ϐ�
	Vec2 pos;    //���W
	bool isGoal; //�S�[�����Ă邩�ǂ���
	int graph;   //�摜

public: //�����o�֐�
	Goal(const Vec2& pos);
	Goal(const int& posX, const int& posY);
	~Goal() = default;

	// ����������
	void Init();
	// �X�V����
	void Updata(const Vec2& playerPos);
	// �`�揈��
	void Draw(const Vec2& offset = {});

	void Reset() { isGoal = false; }

	// ���W�̎擾
	Vec2 GetPos() { return pos; }
	// ���W�̎擾
	bool GetGoal() { return isGoal; }
};
