#include "Scroll.h"
#include"General.h"
Scroll::Scroll()
{
}

Scroll::~Scroll()
{
}

void Scroll::Update(Vec2 playerPos, int stageNum)
{
	if (stageNum >= 4)
	{
		scrollPos.y = playerPos.y - General::WIN_HEIGHT / 2;
		if (scrollPos.y >= minScroll.y)
		{
			scrollPos.y = minScroll.y;
		}
		if (scrollPos.y <= maxScroll.y)
		{
			scrollPos.y = maxScroll.y;
		}
	}
	else
	{
		scrollPos = {};
	}
}
