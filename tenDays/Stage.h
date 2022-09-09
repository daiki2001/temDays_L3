#pragma once
#include"Vec.h"
#include<DxLib.h>
struct BoxData
{
	Vec2 pos;
	Vec2 size;
};

class Stage
{
public:
	Stage();

	~Stage();

	void Init();

	void Update();

	void Draw();
public:
	Vec2 GetBoxPos(int i) { return boxData[i].pos; }

	Vec2 GetBoxSize(int i) { return boxData[i].size; }
public:
	static const int boxMax = 4;
private:
	BoxData boxData[boxMax];
	
};

