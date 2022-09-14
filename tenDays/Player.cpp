#include "Player.h"
#include "General.h"
#include "./Input/Controller.h"
#include<cmath>
Player::Player() :
	locusEffect{},
	clashEffect{},
	boundSound(-1)
{
}

Player::~Player()
{
	if (DeleteSoundMem(boundSound) == 0)
	{
		boundSound = -1;
	}
}

void Player::Init()
{
	playerGraph = LoadGraph("Resources/piyomaru.png");
	locusEffect.Init();

	if (boundSound == -1)
	{
		boundSound = LoadSoundMem("./Resources/sound/SE/jump.wav");
		ChangeVolumeSoundMem(0x80, boundSound);
	}
}

void Player::Update()
{
	oldPos = pos;
	speed = {};
	Bound();
	Move();
	WalkSpeedAccel();
	if (isBoundFlag)
	{
		PlaySoundMem(boundSound, DX_PLAYTYPE_BACK);
	}
	isBoundFlag = false;
	pos += speed;
}

void Player::Draw(Vec2 scroll)
{
	locusEffect.Draw(0, static_cast<int>(-scroll.y));
	clashEffect.Draw(0, static_cast<int>(-scroll.y));

	DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y) - static_cast<int>(scroll.y), 0.5, playerDrawAngle, playerGraph, TRUE);
}

void Player::Reset(const int stageNum)
{
	switch (stageNum)
	{
	case 1:
	case 2:
		pos.x = General::WIN_WIDTH / 2.0f;
		pos.y = 100.0f;
		break;
	case 3:
		pos.x = 800.0f;
		pos.y = 400.0f;
		break;
	case 4:
		pos = { 400.0f,200.0f };
		break;
	case 5:
		pos = { 150.0f,570.0f };
		break;
	case 6:

		break;
	default:
		break;
	}
	bound = 0.0f;
	gravity = gravityPower;
	walkSpeed = speedNormal;
	if (walkSpeed < 0)
	{
		walkSpeed *= -1.0f;
	}

	locusEffect.Init();
	clashEffect.Init();
}

void Player::ChangeFlag()
{
	// 衝突時のエフェクト生成
	clashEffect.Create(pos, speed);

	walkSpeed *= -1.0f;

	boundPower = boundPowerMax;
	bound = -boundPower * fabs(walkSpeed / speedNormal);
	gravity = gravityPower;
}

void Player::ChangeHitRod(const float rodAngle, const Vec2 rodSpeed)
{
	// 衝突時のエフェクト生成
	clashEffect.Create(pos, speed);

	if (walkSpeed > 0)
	{
		walkSpeed += rodSpeed.x;
		if (walkSpeed > speedMax)
		{//スピードを上げすぎないように
			walkSpeed = speedMax;
		}
	}
	else
	{
		walkSpeed -= rodSpeed.x;
		if (walkSpeed < -speedMax)
		{//スピードを上げすぎないように
			walkSpeed = -speedMax;
		}
		walkSpeed *= -1.0f;
		pos.x = oldPos.x;
		pos.x += rodSpeed.x;
	}
	float deg = rodAngle * (180.0f / 3.14f);

	boundPower = boundPowerMax * (fabs(walkSpeed) / speedNormal);
	bound = -boundPower * (1.0f - deg / 80.0f);
	walkSpeed += speedNormal * (deg / 90.0f);
	gravity = gravityPower;
}

void Player::WalkSpeedAccel()
{
	//地面についている間普通のスピードに戻っていく
	if (isBoundFlag == true)
	{
		if (walkSpeed > 0 && walkSpeed > speedNormal)
		{
			walkSpeed -= 0.1f;
			if (walkSpeed <= speedNormal)
			{
				walkSpeed = speedNormal;
			}
		}
		else if (walkSpeed < 0 && walkSpeed < -speedNormal)
		{
			walkSpeed += 0.1f;
			if (walkSpeed >= -speedNormal)
			{
				walkSpeed = -speedNormal;
			}
		}
	}
}

void Player::EffectUpdate()
{
	if ((General::Frame::GetFrame() % 5) == 0)
	{
		locusEffect.Update(pos);
	}
	clashEffect.Update();
}

void Player::SlopeSpeed()
{
	//上り坂
	if (walkSpeed > 0)
	{
		walkSpeed -= 0.05f;
	}//下り坂
	else
	{
		walkSpeed -= 0.05f;
	}
}

void Player::BoundPowerZero()
{
	gravity -= bound;
	bound = 0.0f;
	clashEffect.Create(pos, speed);
}

void Player::Move()
{
	if (isBoundFlag == true)
	{
		gravityMemory = gravity;
		gravity = gravityPower;
	}
	else
	{
		gravity += gravityAdd;
	}
	if (gravity >= 10.0f)
	{
		gravity = 10.0f;
	}
	//重力
	speed.y += gravity;
	speed.x += walkSpeed;


	//描画
	if (speed.x > 0)
	{
		playerDrawAngle += 0.07f;
	}
	else
	{
		playerDrawAngle -= 0.07f;
	}
}

void Player::Bound()
{
	if (isBoundFlag)
	{
		if (gravityMemory - gravityPower >= 1.0f)
		{
			bound = -((gravityMemory - gravityPower) * 5.0f);
			gravityMemory = gravity;
		}
	}

	if (bound < 2.0f)
	{
		bound *= boundDecay;
		if (bound > -2.0f)
		{
			bound = 0;
		}
	}

	speed.y += bound;
}
