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

	DrawRotaGraph(pos.x, pos.y, 1.0f, 3.14 - angle, rodGraph, true);
}

void Rod::Reset()
{
	pos = { 100.0f,382.5f };
	angle = 0.0f;
	isResetAngleFlag = false;
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
		angle += 0.015f;
		if (0.7854 <= angle)
		{
			angle = 0.7854;
		}

	}
	if (Controller::RB())
	{
		isResetAngleFlag = true;
	}
	//Šp“x‚ð–ß‚·
	if (isResetAngleFlag == true && angle > 0.0f)
	{
		angle -= 0.025f;
		if (angle <= 0.0f)
		{
			isResetAngleFlag = false;
			angle = 0.0f;
		}
	}

}
