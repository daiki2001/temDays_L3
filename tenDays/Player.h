#pragma once
#include<DxLib.h>
#include"Vec.h"
class Player
{
public://メンバ関数
	Player();

	~Player();

	void Update();

	void Draw();

	void Reset();
private:

public://取得系

	Vec2 GetPos() { return pos; }

private://メンバ変数
	Vec2 pos = { 680.0f,500.0f };		//プレイヤーの位置

	float size = 10.0f;	//プレイヤーの大きさ


};

