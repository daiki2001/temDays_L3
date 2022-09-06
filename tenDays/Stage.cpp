#include "Stage.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Init()
{
	//è∞
	boxData[0].pos = { 680.0f,560.0f };
	boxData[0].size = { 1000.0f,20.0f };
	boxData[1].pos = { 1000.0f,440.0f };
	boxData[1].size = { 120.0f,100.0f };
}

void Stage::Update()
{
}

void Stage::Draw()
{
	for (int i = 0; i < boxMax; i++)
	{
		DrawBox(boxData[i].pos.x - boxData[i].size.x, boxData[i].pos.y - boxData[i].size.y,
			boxData[i].pos.x + boxData[i].size.x, boxData[i].pos.y + boxData[i].size.y,
			GetColor(255, 255, 255), true);
	}
}
