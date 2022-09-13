#pragma once
#include<DxLib.h>
#include"Vec.h"
#include"Input/Controller.h"
//棒
class Rod
{
public:
	Rod();

	~Rod();

	void Init();

	void Update(Vec2 scroll);

	void Draw(Vec2 scroll);

	void Reset();
public:
	Vec2 GetPos() { return pos; }
	Vec2 GetSize() { return size; }
	float GetAngle() { return angle; }
	Vec2 GetSpeedMemory() { return speedMemory; }
private:
	void Move();
private:
	Vec2 pos = { 100.0f,382.5f };

	const Vec2 ofset = { 100.0f,382.5f };

	Vec2 size = { 20.0f,500.0f };

	Vec2 speed = { 8.0f,2.0f };

	Vec2 speedMemory = {};

	float angle = 0.0f;//角度

	int rodGraph = 0;

	bool isResetAngleFlag = false;
};

