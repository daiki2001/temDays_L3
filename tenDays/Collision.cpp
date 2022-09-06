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
				if ((DistanceSqrf(box.x - size.x , box.y - size.y , circle.x, circle.y) >= fl))
				{
					nResult = false;
				}
			}
			else
			{
				// 左下
				if ((circle.y > box.y + size.y))
				{
					if ((DistanceSqrf(box.x - size.x , box.y + size.y, circle.x, circle.y) >= fl))
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
				if ((circle.y < box.y - size.y ))
				{
					if ((DistanceSqrf(box.x + size.x, box.y - size.y , circle.x, circle.y) >= fl))
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


