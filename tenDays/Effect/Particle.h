#pragma once
#include "Vec.h"

class Particle
{
private:
	Vec2 pos;
	Vec2 speed;
	Vec2 size;
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
	void Create(const Vec2& startPos, const Vec2& size, const Vec2& startSpeed = { 0.0f, 0.0f });

	Vec2 GetPos() const { return pos; }
	Vec2 GetSpeed() const { return speed; }
	Vec2 GetSize() const { return size; }
	int GetTime() const { return time; }
	bool GetAlive() const { return isAlive; }
};