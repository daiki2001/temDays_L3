#include "Goal.h"
#include <DxLib.h>

Goal::Goal(const Vec2& pos) :
	pos(pos),
	graph(-1)
{
}

Goal::Goal(const int& posX, const int& posY) :
	pos(static_cast<float>(posX), static_cast<float>(posY)),
	graph(-1)
{
}

void Goal::Init()
{
}

void Goal::Updata()
{
}

void Goal::Draw(const Vec2& offset)
{
	Vec2 drawPos = pos + offset;

	if (graph)
	{
		DrawTriangle(drawPos.x - 10, drawPos.y - 10,
					 drawPos.x - 10, drawPos.y + 10,
					 drawPos.x + 20, drawPos.y + 0,
					 GetColor(0xFF, 0xFF, 0x00), true);
	}
	else
	{
		DrawGraph(drawPos.x, drawPos.y, graph, true);
	}
}

bool Goal::IsGoal(const Vec2& playerPos)
{
	static const int goalSize = 20;
	static const int playerSize = 10;
	Vec2 distance = playerPos - pos;

	return sqrtf((distance.x * distance.x) + (distance.y * distance.y)) < (goalSize + playerSize);
}
