#include "PushCollision.h"

Vec2 PushCollision::PushPlayer2Box(Vec2 pPos, float pSize, Vec2 oldPos, Vec2 boxPos, Vec2 boxSize, bool& isHit, bool& isHitGround)
{
	Vec2 pos = pPos;
	//�v���C���[�Ɣ�
	if (Collision::BoxCollision(pPos, boxPos, Vec2(pSize, pSize), boxSize))
	{
		//��̖�
		if (pPos.y + pSize > boxPos.y - boxSize.y && oldPos.y < pPos.y &&
			oldPos.x + pSize > boxPos.x - boxSize.x && oldPos.x - pSize < boxPos.x + boxSize.x)
		{
			pos.y = boxPos.y - boxSize.y - pSize;
			isHitGround = true;

		}
		//���̖�
		else if (pPos.y - pSize < boxPos.y + boxSize.y && oldPos.y > pPos.y &&
			oldPos.x + pSize > boxPos.x - boxSize.x && oldPos.x - pSize < boxPos.x + boxSize.x)
		{
			pos.y = boxPos.y + boxSize.y + pSize;

		}
		//���̖�
		if (pPos.x + pSize > boxPos.x - boxSize.x && oldPos.x<pPos.x &&//speed.x > 0 &&
			oldPos.y + pSize > boxPos.y - boxSize.y && oldPos.y - pSize < boxPos.y + boxSize.y)
		{
			pos.x = boxPos.x - boxSize.x - pSize ;
			isHit = true;
		}
		//�E�̖�
		else if (pPos.x - pSize < boxPos.x + boxSize.x && oldPos.x>pPos.x &&//speed.x < 0 &&
			oldPos.y + pSize > boxPos.y - boxSize.y && oldPos.y - pSize < boxPos.y + boxSize.y)
		{
			pos.x = boxPos.x + boxSize.x + pSize ;
			isHit = true;
		}
	}

	return pos;
}
