#pragma once
#include <DxLib.h>
#include "Vec.h"
#include "./Effect/PlayerLocus.h"
#include "./Effect/PlayerClash.h"

class Player
{
public://メンバ関数
	Player();

	~Player();

	void Init();

	void Update();

	void Draw();

	void Reset();

	void SetPosition(Vec2 pos) { this->pos = pos; }

	void ChangeFlag();
	//棒に触れたとき
	void ChangeHitRod(float rodAngle, Vec2 rodSpeed);

	void ChangeBoundFlag() { isBoundFlag = true; }
	//プレイヤースピード変化
	void WalkSpeedAccel();

	void EffectUpdate();
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

	float size = 16.0f;	//プレイヤーの大きさ

	Vec2 oldPos = {};					//１つ前の位置

	const float gravityPower = 4.0f;	//最低限かかる重力
	float gravity = 4.0f;				//重力
	float gravityMemory = gravity;		//重力保存用
	float gravityAdd = 0.09f;			//加速度

	//スピード
	const float speedNormal = 3.0f;
	const float speedMax = 5.0f;	//最高スピード
	const float speedMin = 1.0f;	//最低スピード
	Vec2 speed = { 0.0f ,0.0f };

	//通常時
	float walkSpeed = 3.0f;

	//地面に接しているか
	bool isBoundFlag = false;
	//壁に接しているか
	bool isWallFlag = false;

	//跳ねる力
	float boundPower = 0.0f;
	float bound = 0.0f;
	float boundDecay = 0.9f;
	//描画
	int playerGraph = 0;
	float playerDrawAngle = 0.0f;

	PlayerLocus locusEffect; //軌跡
	PlayerClash clashEffect; //衝突時のエフェクト
};
