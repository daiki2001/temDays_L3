#pragma once
#include "Particle.h"

class PlayerLocus
{
public: //定数
	static const int aliveTime; //パーティクルの生存時間

private: //メンバ変数
	Particle particle[100];

public: //メンバ関数
	PlayerLocus();
	~PlayerLocus();

	// 初期化処理
	void Init();
	// 更新処理
	void Update(const Vec2& playerPos);
	// 描画処理
	void Draw(const int& offsetX = 0, const int& offsetY = 0);
};
