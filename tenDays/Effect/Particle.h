#pragma once
#include "Vec.h"

class Particle
{
private:
	Vec2 pos;
	int time;
	bool isAlive;

public:
	Particle();
	~Particle() = default;

	// 初期化処理
	void Init();
	// 更新処理
	void Update(const int& maxTime);
	// 生成処理
	void Create(const Vec2& startPos);

	Vec2 GetPos() { return pos; }
	int GetTime() { return time; }
	bool GetAlive() { return isAlive; }
};