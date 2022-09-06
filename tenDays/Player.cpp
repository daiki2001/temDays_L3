#include "Player.h"
#include"Controller.h"
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
