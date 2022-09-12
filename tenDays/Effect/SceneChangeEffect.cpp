#include "SceneChangeEffect.h"
#include <DxLib.h>
#include "General.h"

SceneChangeEffect::SceneChangeEffect() :
	isStart(false),
	isChange(false),
	radius(1)
{
	Init();
}

SceneChangeEffect::~SceneChangeEffect()
{
}

void SceneChangeEffect::Init()
{
	isStart = false;
	isChange = false;
	radius = 1;
}

void SceneChangeEffect::Update()
{
	if (isStart == false)
	{
		return;
	}

}

void SceneChangeEffect::Draw()
{
	if (isStart == false)
	{
		return;
	}

	//DrawCircle(General::WIN_WIDTH / 2, General::WIN_HEIGHT / 2, 750, GetColor(0xFF, 0xFF, 0xFF), true);
}
