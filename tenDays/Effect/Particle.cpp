#include "Particle.h"

Particle::Particle() :
	pos(0.0f, 0.0f),
	time(0),
	isAlive(false)
{
	Init();
}

void Particle::Init()
{
	pos = { 0.0f, 0.0f };
	time = 0;
	isAlive = false;
}

void Particle::Update(const int& maxTime)
{
	if (isAlive == false)
	{
		return;
	}

	if (time >= maxTime)
	{
		isAlive = false;
		return;
	}

	time++;
}

void Particle::Create(const Vec2& startPos)
{
	pos = startPos;
	time = 0;
	isAlive = true;
}
