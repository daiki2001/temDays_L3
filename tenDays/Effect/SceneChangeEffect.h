#pragma once

class SceneChangeEffect
{
private: //�����o�ϐ�
	bool isStart;  //�V�[���J�ڂ̃A�j���[�V�������s���Ă��邩�ǂ���
	bool isChange; //�V�[���J�ڂ��邩�ǂ���

	int radius; //���a

public: //�����o�֐�
	SceneChangeEffect();
	~SceneChangeEffect();

	void Init();
	void Update();
	void Draw();

	bool GetChange() { return isChange; }
};
