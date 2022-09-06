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

	void SetPosition(Vec2 pos) { Player::pos = pos; }

	void ChangeFlag();

	void ChangeBoundFlag() { isBoundFlag = true; }
private:
	//移動
	void Move();
	//弾む
	void Bound();
public://取得系

	Vec2 GetPos() { return pos; }
	Vec2 GetOldPos() { return oldPos; }

	float GetSize() { return size; }

	Vec2 GetSpeed() { return speed; }
private://メンバ変数
	Vec2 pos = { 680.0f,500.0f };		//プレイヤーの位置

	float size = 10.0f;	//プレイヤーの大きさ

	Vec2 oldPos = {};					//１つ前の位置

	float gravity = 3.0f;				//重力

	//スピード
	const float speedMax = 5.0f;
	Vec2 speed = { 3.0f ,0.0f };

	//進む方向
	bool isMoveFlag = false;
	//地面に接しているか
	bool isBoundFlag = false;

	//跳ねる力
	float boundPower = 0.0f;
	float bound = 0.0f;
	float boundDecay = 0.8f;
};

