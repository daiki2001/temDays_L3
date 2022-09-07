#include "Player.h"
#include "General.h"
#include "./Input/Controller.h"

Player::Player()
{
}

Player::~Player()
{
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
	DrawCircle(pos.x, pos.y, size, GetColor(255, 0, 0));
}

void Player::Reset()
{
	pos.x = General::WIN_WIDTH / 2.0f;
	pos.y = 100.0f;
}

void Player::ChangeFlag()
{
	if (isMoveFlag == true)
	{
		isMoveFlag = false;
	}
	else
	{
		isMoveFlag = true;
	}
	speed.x *= -1.0f;

	boundPower = 30.0f;
	bound = -boundPower;
	gravity = gravityPower;
}

void Player::Move()
{
	if (isBoundFlag == true)
	{
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
}

void Player::Bound()
{
	if (isBoundFlag)
	{
		boundPower *= 0.7f;
		//跳ねる力が残っていたら
		if (boundPower > 5.0f)
		{
			bound = -boundPower;
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
