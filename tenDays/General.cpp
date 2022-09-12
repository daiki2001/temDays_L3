#include "General.h"
#include <DxLib.h>

namespace General
{
int Frame::frame = 0;

void AllReset(Player* player, Goal* goal, Rod* rod)
{
	player->Reset();
	goal->Reset();
	rod->Reset();
}

void TiringDraw(const Vec2& pos, const Vec2& drawSize, const int& graph, const Vec2& graphSize)
{
	static int left = 0;
	static int up = 0;
	static int width = 0;
	static int height = 0;

	width = static_cast<int>(graphSize.x);
	height = static_cast<int>(graphSize.y);

	for (size_t y = 0; y * height < drawSize.y * 2; y++)
	{
		up = pos.y + (y * height);
		bool isRect = (up + height) > (pos.y + drawSize.y);

		for (size_t x = 0; x * width < drawSize.x * 2; x++)
		{
			int drawWidth = width;
			int drawHeight = height;

			left = pos.x + (x * width);
			isRect |= (left + width) > (pos.x + drawSize.x);

			if (isRect)
			{
				if ((left + width) > static_cast<int>(pos.x + drawSize.x))
				{
					drawWidth -= (left + width) - static_cast<int>(pos.x + drawSize.x);
				}
				if ((up + height) > static_cast<int>(pos.y + drawSize.y))
				{
					drawHeight -= (up + height) - static_cast<int>(pos.y + drawSize.y);
				}

				DrawRectGraph(left, up, 0, 0, drawWidth, drawHeight, graph, true);
			}
			else
			{
				DrawGraph(left, up, graph, true);
			}
		}
	}
}
} //General
