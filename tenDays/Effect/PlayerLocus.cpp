#include "PlayerLocus.h"
#include <DxLib.h>

const int PlayerLocus::aliveTime = 20;

PlayerLocus::PlayerLocus() :
	particle{}
{
	Init();
}

PlayerLocus::~PlayerLocus()
{
}

void PlayerLocus::Init()
{
	for (size_t i = 0; i < sizeof(particle) / sizeof(particle[0]); i++)
	{
		particle[i].Init();
	}
}

void PlayerLocus::Update(const Vec2& playerPos)
{
	for (size_t i = 0, j = 0; i < sizeof(particle) / sizeof(particle[0]); i++)
	{
		particle[i].Update(aliveTime);

		if (particle[i].GetAlive() == false && j < 1)
		{
			particle[i].Create(playerPos);
			j++;
		}
	}
}

void PlayerLocus::Draw(const int& offsetX, const int& offsetY)
{
	for (size_t i = 0; i < sizeof(particle) / sizeof(particle[0]); i++)
	{
		if (particle[i].GetAlive() == false)
		{
			continue;
		}

		float par = (particle[i].GetTime() == 0) ? 0.0f : (static_cast<float>(particle[i].GetTime()) / static_cast<float>(aliveTime));
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0xFF - (0xFF * par));

		DrawCircle(static_cast<int>(particle[i].GetPos().x) + offsetX,
				   static_cast<int>(particle[i].GetPos().y) + offsetY,
				   4,
				   GetColor(0xFF, 0xFF, 0xFF),
				   true);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0xFF);
}
