#include "Rod.h"
#include"General.h"
Rod::Rod()
{
}

Rod::~Rod()
{
}

void Rod::Init()
{
	rodGraph = LoadGraph("Resources/Rod.png");
}

void Rod::Update(Vec2 scroll)
{
	pos.y = ofset.y + scroll.y;
	Move();
}

void Rod::Draw(Vec2 scroll)
{

	DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y) - static_cast<int>(scroll.y), 1.0f, -angle, rodGraph, true);
}

void Rod::Reset()
{
	pos = { 100.0f,382.5f };
	angle = 0.0f;
	isResetAngleFlag = false;
}

void Rod::Move()
{
	speedMemory = {};
	if (Controller::Left())
	{
		pos.x -= speed.x;
		speedMemory.x -= speed.x;
		if (pos.x <= size.x)
		{
			pos.x = size.x;
		}
	}
	if (Controller::Right())
	{
		pos.x += speed.x;
		speedMemory.x += speed.x;
		if (pos.x >= static_cast<float>(General::WIN_WIDTH) - size.x)
		{
			pos.x = static_cast<float>(General::WIN_WIDTH) - size.x;
		}
	}

	//回転
	if (Controller::LB())
	{
		angle += 0.030f;
		if (0.7854 <= angle)
		{
			angle = 0.7854f;
		}

	}
	if (Controller::RB())
	{
		angle -= 0.030f;
		if (angle < 0.0f)
		{
			angle = 0.0f;
		}
	}

}
