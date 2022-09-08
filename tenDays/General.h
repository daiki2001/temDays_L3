#pragma once
#include "Player.h"
#include "Goal.h"
#include "Rod.h"

namespace General
{
// ウィンドウ横幅
const int WIN_WIDTH = 1280;
// ウィンドウ縦幅
const int WIN_HEIGHT = 720;

void AllReset(Player* player, Goal* goal, Rod* rod);
}
