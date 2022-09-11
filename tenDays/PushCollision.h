#pragma once
#include"Collision.h"
class PushCollision
{
public:
	static Vec2 PushPlayer2Box(Vec2 pPos, float pSize, Vec2 oldPos,
		Vec2 boxPos, Vec2 boxSize, int boxType,
		bool& isHit, bool& isHitGround, bool& isHitTriangle);
};

