#pragma once
#include "Vec.h"

class Goal
{
private: //�����o�ϐ�
	Vec2 pos;  //���W
	int graph; //�摜

public: //�����o�֐�
	Goal(const Vec2& pos);
	Goal(const int& posX, const int& posY);
	~Goal() = default;

	// ����������
	void Init();
	// �X�V����
	void Updata();
	// �`�揈��
	void Draw(const Vec2& offset = {});

	// �S�[�����Ă邩�ǂ���
	bool IsGoal(const Vec2& playerPos);
	// ���W�̎擾
	Vec2 GetPos() { return pos; }
};
