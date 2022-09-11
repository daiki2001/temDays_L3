#include "PushCollision.h"

Vec2 PushCollision::PushPlayer2Box(Vec2 pPos, float pSize, Vec2 oldPos,
	Vec2 boxPos, Vec2 boxSize, int boxType,
	bool& isHit, bool& isHitGround, bool& isHitTriangle)
{
	Vec2 pos = pPos;
	//プレイヤーと箱
	if (boxType == 0)
	{
		if (Collision::BoxCollision(pPos, boxPos, Vec2(pSize, pSize), boxSize))
		{
			//上の面
			if (pPos.y + pSize > boxPos.y - boxSize.y && oldPos.y < pPos.y &&
				oldPos.x + pSize > boxPos.x - boxSize.x && oldPos.x - pSize < boxPos.x + boxSize.x)
			{
				pos.y = boxPos.y - boxSize.y - pSize;
				isHitGround = true;

			}
			//下の面
			else if (pPos.y - pSize < boxPos.y + boxSize.y && oldPos.y > pPos.y &&
				oldPos.x + pSize > boxPos.x - boxSize.x && oldPos.x - pSize < boxPos.x + boxSize.x)
			{
				pos.y = boxPos.y + boxSize.y + pSize;

			}
			//左の面
			if (pPos.x + pSize > boxPos.x - boxSize.x && oldPos.x<pPos.x &&//speed.x > 0 &&
				oldPos.y + pSize > boxPos.y - boxSize.y && oldPos.y - pSize < boxPos.y + boxSize.y)
			{
				pos.x = boxPos.x - boxSize.x - pSize;
				isHit = true;
			}
			//右の面
			else if (pPos.x - pSize < boxPos.x + boxSize.x && oldPos.x>pPos.x &&//speed.x < 0 &&
				oldPos.y + pSize > boxPos.y - boxSize.y && oldPos.y - pSize < boxPos.y + boxSize.y)
			{
				pos.x = boxPos.x + boxSize.x + pSize;
				isHit = true;
			}
		}
	}
	else if (boxType == 1)
	{
		Vec2 trianglePos = pPos;
		while (Collision::CollisionTriangle(trianglePos, boxPos, boxSize) == true)
		{
			trianglePos.y -= 0.5f;
			isHitGround = true;
			isHitTriangle = true;
		}
		pos = trianglePos;
	}
	return pos;
}
