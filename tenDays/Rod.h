#pragma once
#include<DxLib.h>
#include"Vec.h"
#include"Input/Controller.h"
//–_
class Rod
{
public:
	Rod();

	~Rod();

	void Init();

	void Update();

	void Draw();

	void Reset();
public:
	Vec2 GetPos() { return pos; }
	Vec2 GetSize() { return size; }
private:
	void Move();
private:
	Vec2 pos = { 100.0f,382.5f };

	Vec2 size = { 20.0f,500.0f };

	Vec2 speed = { 2.0f,2.0f };

	float angle = {};//Šp“x

	int rodGraph = 0;
};

