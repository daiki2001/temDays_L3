#pragma once
#include "Player.h"
#include "Goal.h"
#include "Rod.h"

namespace General
{
// ウィンドウ横幅
constexpr int WIN_WIDTH = 1280;
// ウィンドウ縦幅
constexpr int WIN_HEIGHT = 720;
// デグリー角 → ラジアン角
constexpr float degree = 3.141592f / 180.0f;

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

void AllReset(Player* player, Goal* goal, Rod* rod,const int stageNum);

void TiringDraw(const Vec2& pos, const Vec2& drawSize, const int& graph, const Vec2& graphSize);
}
