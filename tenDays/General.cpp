#include "General.h"

namespace General
{
int Frame::frame = 0;

void AllReset(Player* player, Goal* goal, Rod* rod)
{
	player->Reset();
	goal->Reset();
	rod->Reset();
}
} //General
