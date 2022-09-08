#pragma once
#include "Vec.h"

class Goal
{
private: //メンバ変数
	Vec2 pos;    //座標
	bool isGoal; //ゴールしてるかどうか
	int graph;   //画像

public: //メンバ関数
	Goal(const Vec2& pos);
	Goal(const int& posX, const int& posY);
	~Goal() = default;

	// 初期化処理
	void Init();
	// 更新処理
	void Update(const Vec2& playerPos);
	// 描画処理
	void Draw(const Vec2& offset = {});

	void Reset() { isGoal = false; }

	// 座標の取得
	Vec2 GetPos() { return pos; }
	// 座標の取得
	bool GetGoal() { return isGoal; }
};
