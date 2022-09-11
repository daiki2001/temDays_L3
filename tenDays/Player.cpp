#include "Player.h"
#include "General.h"
#include "./Input/Controller.h"
#include<cmath>
Player::Player() :
	locusEffect{},
	clashEffect{}
{
}

Player::~Player()
{
}

void Player::Init()
{
	playerGraph = LoadGraph("Resources/piyomaru.png");
	locusEffect.Init();
}

void Player::Update()
{
	oldPos = pos;
	speed = {};
	Bound();
	Move();
	isBoundFlag = false;
	pos += speed;
}

void Player::Draw()
{
	locusEffect.Draw();
	clashEffect.Draw();

	DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), 0.5, playerDrawAngle, playerGraph, TRUE);
}

void Player::Reset()
{
	pos.x = General::WIN_WIDTH / 2.0f;
	pos.y = 100.0f;
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

	boundPower = 30.0f;
	bound = -boundPower;
	gravity = gravityPower;
}

void Player::ChangeHitRod(float rodAngle, Vec2 rodSpeed)
{
	// 衝突時のエフェクト生成
	clashEffect.Create(pos, speed);

	if (walkSpeed > 0)
	{

	}
	else
	{
		walkSpeed *= -1.0f;
		pos.x += rodSpeed.x + walkSpeed;
	}
	float deg = rodAngle * (180 / 3.14);
	boundPower = 30.0f * (fabs(walkSpeed) / speedNormal);
	bound = -boundPower * (1 - deg / 80.0);
	gravity = gravityPower;
}

void Player::WalkSpeedAccel()
{
	/*if (walkSpeed > 0)
	{
		walkSpeed -= 0.1f;
		if (fabs(walkSpeed) <= speedMin)
		{
			walkSpeed = speedMin;
		}
	}
	else
	{
		walkSpeed -= 0.1f;
		if (fabs(walkSpeed) >= speedMax)
		{
			walkSpeed = speedMax;
		}
	}*/
}

void Player::EffectUpdate()
{
	if ((General::Frame::GetFrame() % 5) == 0)
	{
		locusEffect.Update(pos);
	}
	clashEffect.Update();
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
