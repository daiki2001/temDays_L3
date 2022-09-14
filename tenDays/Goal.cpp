#include "Goal.h"
#include <DxLib.h>
#include "Collision.h"

Goal::Goal(const Vec2& pos) :
	pos(pos),
	isGoal(false),
	graph(-1),
	sound(-1)
{
	Init();
}

Goal::Goal(const int& posX, const int& posY) :
	pos(static_cast<float>(posX), static_cast<float>(posY)),
	isGoal(false),
	graph(-1),
	sound(-1)
{
	Init();
}

void Goal::Init()
{
	if (graph == -1)
	{
		graph = LoadGraph("./Resources/goal/goal0912.png");
	}
	if (sound == -1)
	{
		sound = LoadSoundMem("./Resources/sound/SE/goal.mp3");
		ChangeVolumeSoundMem(0x80, sound);
	}
}

void Goal::Update(const Vec2& playerPos)
{
	if (isGoal)
	{
		return;
	}

	static const int goalSize = 16;
	static const int playerSize = 16;

	isGoal = Collision::BoxCollision(pos, playerPos, { goalSize, goalSize }, { playerSize, playerSize });
	if (isGoal)
	{
		PlaySoundMem(sound, DX_PLAYTYPE_BACK);
	}
}

void Goal::Draw(const Vec2& offset)
{
	Vec2 drawPos = pos - offset;

	if (graph == -1)
	{
		DrawTriangle(static_cast<int>(drawPos.x) - 10, static_cast<int>(drawPos.y) - 10,
					 static_cast<int>(drawPos.x) - 10, static_cast<int>(drawPos.y) + 10,
					 static_cast<int>(drawPos.x) + 20, static_cast<int>(drawPos.y) + 0,
					 GetColor(0xFF, 0xFF, 0x00), true);
	}
	else
	{
		DrawGraph(static_cast<int>(drawPos.x) - 32, static_cast<int>(drawPos.y) - 32, graph, true);
	}
}

void Goal::SetGoalPos(int stageNum)
{
	if (stageNum == 1)
	{
		pos = { 1000.0f,360.0f };
	}
	else if (stageNum == 2)
	{
		pos = { 1000.0f,50.0f };
	}
	else if (stageNum == 3)
	{
		pos = { 1050.0f,120.0f };
	}
	else if (stageNum == 4)
	{
		pos = { 300.0f,-420.0f };
	}
	else if (stageNum == 5)
	{
		pos = { 1100.0f,-510.0f };
	}
	else if (stageNum == 6)
	{
		pos = { 1160.0f,-620.0f };
	}
}
