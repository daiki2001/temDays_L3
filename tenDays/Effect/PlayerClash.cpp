#include "PlayerClash.h"
#include <DxLib.h>
#include "General.h"

const int PlayerClash::aliveTime = 15;
const int PlayerClash::createNum = 50;

PlayerClash::PlayerClash() :
	particle{}
{
	Init();
}

void PlayerClash::Init()
{
	for (size_t i = 0; i < sizeof(particle) / sizeof(particle[0]); i++)
	{
		particle[i].Init();
	}
}

void PlayerClash::Update()
{
	for (size_t i = 0, j = 0; i < sizeof(particle) / sizeof(particle[0]); i++)
	{
		particle[i].Update(aliveTime);
	}
}

void PlayerClash::Draw(const int& offsetX, const int& offsetY)
{
	for (size_t i = 0; i < sizeof(particle) / sizeof(particle[0]); i++)
	{
		if (particle[i].GetAlive() == false)
		{
			continue;
		}

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0xC0 - particle[i].GetTime());

		DrawBox(static_cast<int>(particle[i].GetPos().x - (particle[i].GetSize().x / 2.0f)) + offsetX,
				static_cast<int>(particle[i].GetPos().y - (particle[i].GetSize().y / 2.0f)) + offsetY,
				static_cast<int>(particle[i].GetPos().x + (particle[i].GetSize().x / 2.0f)) + offsetX,
				static_cast<int>(particle[i].GetPos().y + (particle[i].GetSize().y / 2.0f)) + offsetY,
				GetColor(0xFF, 0xFF, 0x00),
				true);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0xFF);
}

void PlayerClash::Create(const Vec2& playerPos, const Vec2& playerSpeed)
{
	static const int speedMax = 10;
	static const int speedMin = 1;
	static const int speedAngleRange = 30;
	static float speedLength = 1.0f;
	static float speedRate = 1.0f;
	static int speedAngle = 0;
	static Vec2 normVec = {};

	static const int sizeMax = 8;
	static const int sizeMin = 2;
	static Vec2 size = {};

	speedLength = playerSpeed.length();

	for (size_t i = 0, j = 0; i < sizeof(particle) / sizeof(particle[0]) && j < createNum; i++)
	{
		if (particle[i].GetAlive() == true)
		{
			continue;
		}

		speedRate = static_cast<float>((rand() % (speedMax - speedMin + 1)) + speedMin);
		speedRate *= 5.0f / 10.0f;
		speedAngle = (rand() % (speedAngleRange / 2 - (-speedAngleRange / 2) + 1)) + (-speedAngleRange / 2);
		normVec = playerSpeed;
		normVec.normalize();
		normVec.x = cosf(speedAngle * General::degree) * normVec.x - sinf(speedAngle * General::degree) * normVec.y;
		normVec.y = sinf(speedAngle * General::degree) * normVec.x + cosf(speedAngle * General::degree) * normVec.y;

		size.x = static_cast<float>((rand() % (sizeMax - sizeMin + 1)) + sizeMin);
		size.y = static_cast<float>((rand() % (sizeMax - sizeMin + 1)) + sizeMin);

		particle[i].Create(playerPos, size, normVec * speedLength * speedRate);
		j++;
	}
}
