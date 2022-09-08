#include "General.h"

void General::AllReset(Player* player, Goal* goal, Rod* rod)
{
	player->Reset();
	goal->Reset();
	rod->Reset();
}
