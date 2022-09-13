#pragma once
#include"Vec.h"
class Scroll
{
public:
	Scroll();

	~Scroll();

	void Update(Vec2 playerPos, int stageNum);
private:

public:
	Vec2 GetScroll() { return scrollPos; }
private:
	Vec2 scrollPos = {};

	Vec2 maxScroll = {};

	Vec2 minScroll = {0.0f,0.0f};
};

