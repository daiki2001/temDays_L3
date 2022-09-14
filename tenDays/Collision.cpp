#include "Collision.h"
#include<math.h>
bool Collision::CircleCollision(Vec2 circle1, Vec2 circle2, float radius1, float radius2)
{
	double disX = static_cast<double>(circle1.x - circle2.x);
	double disY = static_cast<double>(circle1.y - circle2.y);
	double d = disX * disX + disY * disY;
	double r = static_cast<double>((radius1 + radius2) * (radius1 + radius2));
	return d < r;
}

bool Collision::BoxCollision(Vec2 box1, Vec2 box2, Vec2 size1, Vec2 size2)
{
	//x軸の判定
	if (box2.x - size2.x <= box1.x + size1.x && box1.x - size1.x <= box2.x + size2.x)
	{//y軸
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
	// 四角形の四辺に対して円の半径分だけ足したとき円が重なっていたら
	if ((circle.x > box.x - size.x - radius) &&
		(circle.x < box.x + size.x + radius) &&
		(circle.y > box.y - size.y - radius) &&
		(circle.y < box.y + size.y + radius))
	{
		nResult = true;
		float fl = radius * radius;

		// 左
		if (circle.x < box.x - size.x)
		{
			// 左上
			if ((circle.y < box.y - size.y))
			{
				if ((DistanceSqrf(box.x - size.x, box.y - size.y, circle.x, circle.y) >= fl))
				{
					nResult = false;
				}
			}
			else
			{
				// 左下
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
			// 右
			if (circle.x > box.x + size.x)
			{
				// 右上
				if ((circle.y < box.y - size.y))
				{
					if ((DistanceSqrf(box.x + size.x, box.y - size.y, circle.x, circle.y) >= fl))
					{
						nResult = false;
					}
				}
				else
				{
					// 右下
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
	//POINT_t p2  // 有向線分 e の始点
	//POINT_t p3  // 有向線分 e の終点

	// 有向線分 (p2,p1), (p2,p3) の外積の z 成分を求める
	const int n = p1x * (p2y - p3y) + p2x * (p3y - p1y) + p3x * (p1y - p2y);
	if (n > 0) return  1; // 左
	else if (n < 0) return -1; // 右
	else              return  0; // 線上
}

bool Collision::CollisionTrinangle(Vec2 pPos, Vec2 box, Vec2 size, float angle)
{
	//回転の中心からの距離
	int LX = -size.x;//左
	int UY = -size.y;//上
	int RX = size.x;//右
	int DY = size.y;//下

	float cos = cosf(-angle);
	float sin = sinf(-angle);
	//左上の箱の座標	
	float x1, x2, x3, x4, y1, y2, y3, y4;
	x1 = LX * cos - UY * sin + box.x, y1 = LX * sin + UY * cos + box.y;//左上
	x2 = RX * cos - UY * sin + box.x, y2 = RX * sin + UY * cos + box.y;//右上
	x3 = RX * cos - DY * sin + box.x, y3 = RX * sin + DY * cos + box.y;//右下
	x4 = LX * cos - DY * sin + box.x, y4 = LX * sin + DY * cos + box.y;//左下

	//外積    Z成分だけ計算すればよいです
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

bool Collision::CollisionTriangle(Vec2 pPos, Vec2 box, Vec2 size)
{
	Vec2 pos1 = { box.x + size.x,box.y - size.y };
	Vec2 pos2 = { box.x + size.x,box.y + size.y };
	Vec2 pos3 = { box.x - size.x,box.y + size.y };
	//外積    Z成分だけ計算すればよいです
	double c1 = side(pPos.x, pPos.y, pos1.x, pos1.y, pos2.x, pos2.y);//右上
	double c2 = side(pPos.x, pPos.y, pos2.x, pos2.y, pos3.x, pos3.y);//右下
	double c3 = side(pPos.x, pPos.y, pos3.x, pos3.y, pos1.x, pos1.y);//左下

	if ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0))
	{
		return true;
	}
	return false;
}
