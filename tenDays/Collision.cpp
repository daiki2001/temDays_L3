#include "Collision.h"
#include<math.h>
bool Collision::CircleCollision(Vec2 circle1, Vec2 circle2, float radius1, float radius2)
{
	double disX = circle1.x - circle2.x;
	double disY = circle1.y - circle2.y;
	double d = disX * disX + disY * disY;
	double r = (radius1 + radius2) * (radius1 + radius2);
	return d < r;
}

bool Collision::BoxCollision(Vec2 box1, Vec2 box2, Vec2 size1, Vec2 size2)
{
	//x���̔���
	if (box2.x - size2.x <= box1.x + size1.x && box1.x - size1.x <= box2.x + size2.x)
	{//y��
		if (box2.y - size2.y <= box1.y + size1.y && box1.y - size1.y <= box2.y + size2.y)
		{
			return 1;
		}
	}
	return 0;
}
float Collision::DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2)
{
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}
bool Collision::Circle2Box(Vec2 circle, float radius, Vec2 box, Vec2 size)
{
	bool nResult = false;
	// �l�p�`�̎l�ӂɑ΂��ĉ~�̔��a�������������Ƃ��~���d�Ȃ��Ă�����
	if ((circle.x > box.x - size.x - radius) &&
		(circle.x < box.x + size.x + radius) &&
		(circle.y > box.y - size.y - radius) &&
		(circle.y < box.y + size.y + radius))
	{
		nResult = true;
		float fl = radius * radius;

		// ��
		if (circle.x < box.x - size.x)
		{
			// ����
			if ((circle.y < box.y - size.y))
			{
				if ((DistanceSqrf(box.x - size.x, box.y - size.y, circle.x, circle.y) >= fl))
				{
					nResult = false;
				}
			}
			else
			{
				// ����
				if ((circle.y > box.y + size.y))
				{
					if ((DistanceSqrf(box.x - size.x, box.y + size.y, circle.x, circle.y) >= fl))
					{
						nResult = false;
					}
				}
			}
		}
		else
		{
			// �E
			if (circle.x > box.x + size.x)
			{
				// �E��
				if ((circle.y < box.y - size.y))
				{
					if ((DistanceSqrf(box.x + size.x, box.y - size.y, circle.x, circle.y) >= fl))
					{
						nResult = false;
					}
				}
				else
				{
					// �E��
					if ((circle.y > box.y + size.y))
					{
						if ((DistanceSqrf(box.x + size.x, box.y + size.y, circle.x, circle.y) >= fl))
						{
							nResult = false;
						}
					}
				}
			}
		}
	}
	return nResult;
}



int side(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y)
{
	//POINT_t p1 
	//POINT_t p2  // �L������ e �̎n�_
	//POINT_t p3  // �L������ e �̏I�_

	// �L������ (p2,p1), (p2,p3) �̊O�ς� z ���������߂�
	const int n = p1x * (p2y - p3y) + p2x * (p3y - p1y) + p3x * (p1y - p2y);
	if (n > 0) return  1; // ��
	else if (n < 0) return -1; // �E
	else              return  0; // ����
}

bool Collision::CollisionTrinangle(Vec2 pPos, Vec2 box, Vec2 size, float angle)
{
	//��]�̒��S����̋���
	int LX = -size.x;//��
	int UY = -size.y;//��
	int RX = size.x;//�E
	int DY = size.y;//��

	float cos = cosf(-angle);
	float sin = sinf(-angle);
	//����̔��̍��W	
	float x1, x2, x3, x4, y1, y2, y3, y4;
	x1 = LX * cos - UY * sin + box.x, y1 = LX * sin + UY * cos + box.y;//����
	x2 = RX * cos - UY * sin + box.x, y2 = RX * sin + UY * cos + box.y;//�E��
	x3 = RX * cos - DY * sin + box.x, y3 = RX * sin + DY * cos + box.y;//�E��
	x4 = LX * cos - DY * sin + box.x, y4 = LX * sin + DY * cos + box.y;//����

	//�O��    Z���������v�Z����΂悢�ł�
	double c1 = side(pPos.x, pPos.y, x1, y1, x2, y2);
	double c2 = side(pPos.x, pPos.y, x2, y2, x3, y3);
	double c3 = side(pPos.x, pPos.y, x3, y3, x4, y4);
	double c4 = side(pPos.x, pPos.y, x4, y4, x1, y1);

	if ((c1 > 0 && c2 > 0 && c3 > 0 && c4 > 0) || (c1 < 0 && c2 < 0 && c3 < 0 && c4 < 0))
	{
		return true;
	}
	return false;
}
