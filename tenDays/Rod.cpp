#include "Rod.h"

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

void Rod::Update()
{
	Move();
}

void Rod::Draw()
{
	/*DrawBox(pos.x - size.x, pos.y - size.y,
		pos.x + size.x, pos.y + size.y,
		GetColor(255, 0, 0), true);*/

		//
	DrawRotaGraph(pos.x, pos.y, 1.0f, 3.14 - angle, rodGraph, true);
}

void Rod::Reset()
{
	pos = { 100.0f,382.5f };
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

	//‰ñ“]
	if (Controller::LB())
	{
		angle += 0.01f;
		if (0.7854 <= angle)
		{
			angle = 0.7854;
		}

	}
	if (Controller::RB())
	{
		angle = 0.0f;
	}

}
