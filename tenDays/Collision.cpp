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

//bool Collision::CollisionTrinangle(Vec2 pPos, Vec2 box, Vec2 size)
//{
//	//�p�x������W�����߂�
//
//
//	//����̔��̍��W
//	int  LX = static_cast<int>(box.x - size.x), UY = static_cast<int>(box.y - size.y);
//	int  RX = static_cast<int>(box.x + size.x), DY = static_cast<int>(box.y + size.y);
//	float x1_a, x2_a, x3_a, y1_a, y2_a, y3_a;
//	x1_a = LX, y1_a = UY;//����
//	x2_a = LX, y2_a = DY;//����
//	x3_a = RX, y3_a = DY;//�E��
//	//�O��    Z���������v�Z����΂悢�ł�
//	//1�ڂ̎O�p�`
//	double c1_a = side(pPos.x, pPos.y, x1_a, y1_a, x2_a, y2_a);
//	double c2_a = side(pPos.x, pPos.y, x2_a, y2_a, x3_a, y3_a);
//	double c3_a = side(pPos.x, pPos.y, x3_a, y3_a, x1_a, y1_a);
//	float x1_b, x2_b, x3_b, y1_b, y2_b, y3_b;
//	x1_b = RX, y1_b = UY;
//	x2_b = LX, y2_b = UY;
//	x3_b = RX, y3_b = DY;
//	//�Q�ڂ̎O�p�`
//	double c1_b = side(pPos.x, pPos.y, x1_b, y1_b, x2_b, y2_b);
//	double c2_b = side(pPos.x, pPos.y, x2_b, y2_b, x3_b, y3_b);
//	double c3_b = side(pPos.x, pPos.y, x3_b, y3_b, x1_b, y1_b);
//
//	if ((c1_a > 0 && c2_a > 0 && c3_a > 0) || (c1_a < 0 && c2_a < 0 && c3_a < 0))
//	{
//		if ((c1_b > 0 && c2_b > 0 && c3_b > 0) || (c1_b < 0 && c2_b < 0 && c3_b < 0))
//		{
//			return true;
//		}
//	}
//	return false;
//}
