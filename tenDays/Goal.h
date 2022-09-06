#pragma once
#include "Vec.h"

class Goal
{
private: //メンバ変数
	Vec2 pos;  //座標
	int graph; //画像

public: //メンバ関数
	Goal(const Vec2& pos);
	Goal(const int& posX, const int& posY);
	~Goal() = default;

	// 初期化処理
	void Init();
	// 更新処理
	void Updata();
	// 描画処理
	void Draw(const Vec2& offset = {});

	// ゴールしてるかどうか
	bool IsGoal(const Vec2& playerPos);
	// 座標の取得
	Vec2 GetPos() { return pos; }
};
