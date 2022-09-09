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

// フレーム数
class Frame
{
private: //静的メンバ変数
	static int frame;

public: //静的メンバ関数
	static void Update() { ++frame %= 1024; }
	static int GetFrame() { return frame; }

private: //メンバ関数
	Frame() = default;
	~Frame() = default;
};

void AllReset(Player* player, Goal* goal, Rod* rod);
}
