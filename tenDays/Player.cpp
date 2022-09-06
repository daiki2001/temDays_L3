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

}

void Player::Draw()
{
	DrawCircle(pos.x, pos.y, size, GetColor(255, 255, 255));
}

void Player::Reset()
{
	pos.x = General::WIN_WIDTH / 2.0f;
	pos.y = 100.0f;
}
