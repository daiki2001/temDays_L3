#include "Player.h"
#include "General.h"
#include "./Input/Controller.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{
	playerGraph = LoadGraph("Resources/piyomaru.png");
}

void Player::Update()
{
	oldPos = pos;
	Bound();
	Move();
	isBoundFlag = false;
}

void Player::Draw()
{
	//DrawCircle(pos.x, pos.y, size, GetColor(255, 0, 0));
	DrawRotaGraph(pos.x, pos.y, 0.5, playerDrawAngle, playerGraph, TRUE);
}

void Player::Reset()
{
	pos.x = General::WIN_WIDTH / 2.0f;
	pos.y = 100.0f;
	bound = 0.0f;
	gravity = gravityPower;
	if (speed.x < 0)
	{
		speed.x *= -1.0f;
	}
}

void Player::ChangeFlag()
{
	speed.x *= -1.0f;

	boundPower = 30.0f;
	bound = -boundPower;
	gravity = gravityPower;
}

void Player::ChangeHitRod(float rodAngle)
{
	if (speed.x > 0)
	{
		pos.x += 3.0f;
	}
	else
	{
		speed.x *= -1.0f;
		pos.x -= 3.0f;
	}
	float deg = rodAngle * (180 / 3.14);
	boundPower = 30.0f;
	bound = -boundPower * (1- deg / 80.0);
	gravity = gravityPower;
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
	pos.y += gravity;
	pos.x += speed.x;

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

	pos.y += bound;
}
