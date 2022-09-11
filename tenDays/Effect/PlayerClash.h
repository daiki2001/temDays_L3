#pragma once
#include "Particle.h"

class PlayerClash
{
public: //定数
	static const int aliveTime; //パーティクルの生存時間
	static const int createNum; //一度に生成するパーティクルの数

private: //メンバ変数
	Particle particle[200];

public: //メンバ関数
	PlayerClash();
	~PlayerClash() = default;

	// 初期化処理
	void Init();
	// 更新処理
	void Update();
	// 描画処理
	void Draw(const int& offsetX = 0, const int& offsetY = 0);
	// 生成処理
	void Create(const Vec2& playerPos, const Vec2& playerSpeed);
};
