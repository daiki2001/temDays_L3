#pragma once
#include<DxLib.h>
#include"Vec.h"
class Player
{
public://�����o�֐�
	Player();

	~Player();

	void Update();

	void Draw();
private:

public://�擾�n

	Vec2 GetPos() { return pos; }

private://�����o�ϐ�
	Vec2 pos = { 680.0f,500.0f };		//�v���C���[�̈ʒu

	float size = 10.0f;	//�v���C���[�̑傫��


};

