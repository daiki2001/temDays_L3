#include "Rod.h"

Rod::Rod()
{
}

Rod::~Rod()
{
}

void Rod::Init()
{
}

void Rod::Update()
{
	Move();
}

void Rod::Draw()
{
	DrawBox(pos.x - size.x, pos.y - size.y,
		pos.x + size.x, pos.y + size.y,
		GetColor(255, 255, 0), true);
}

void Rod::Move()
{
	if (Controller::Left())
	{
		pos.x -= speed.x;
	}
	if (Controller::Right())
	{
		pos.x += speed.x;
	}
}
