#include "TitleScene.h"
#include <DxLib.h>
#include "General.h"
#include "./Input/KeyInput.h"
#include "./Input/Controller.h"
#include "Collision.h"

namespace
{
int animationCount = 0;
}

TitleScene::TitleScene(SceneChenger* sceneChenger) :
	BaseScene(sceneChenger),
	back{},
	cloud(-1),
	player{}
{
	Load();
	Init();
}

TitleScene::~TitleScene()
{
	Release();
}

void TitleScene::Init()
{
	player.Init();
}

void TitleScene::Update()
{
	if ((General::Frame::GetFrame() % 5) == 0)
	{
		++animationCount %= 8;
	}

	player.Update();

	static const Vec2 groundPos = Vec2(General::WIN_WIDTH / 2, General::WIN_HEIGHT - 70);
	static const Vec2 groundSize = Vec2(General::WIN_WIDTH, 70);

	if (Collision::BoxCollision(player.GetPos(), groundPos, Vec2(player.GetSize(), player.GetSize()), groundSize))
	{
		if (player.GetPos().y + player.GetSize() > groundPos.y - groundSize.y && player.GetOldPos().y < player.GetPos().y &&
			player.GetOldPos().x + player.GetSize() > groundPos.x - groundSize.x && player.GetOldPos().x - player.GetSize() < groundPos.x + groundSize.x)
		{
			Vec2 pos = player.GetPos();
			pos.y = groundPos.y - groundSize.y - player.GetSize();
			player.SetPosition(pos);
			player.ChangeBoundFlag();
		}
	}

	// 画面外判定
	bool isIn = Collision::BoxCollision(player.GetPos(),
										Vec2(General::WIN_WIDTH / 2.0f, General::WIN_HEIGHT / 2.0f),
										Vec2(player.GetSize(), player.GetSize()),
										Vec2(General::WIN_WIDTH / 2.0f - 20.0f, General::WIN_HEIGHT / 2.0f));
	if (isIn == false)
	{
		player.ChangeFlag();
	}

	if (Controller::Decision_A() || KeyInput::IsKeyTrigger(KEY_INPUT_SPACE))
	{
		sceneChenger->SceneChenge(SceneChenger::Scene::Game, true);
	}
}

void TitleScene::Draw()
{
	// 画面クリア
	ClearDrawScreen();

	// 背景
	DrawGraph(0, 0, back[animationCount], false);
	DrawGraph(16, 0, cloud, true);

	// オブジェクト
	player.Draw();

	// (ダブルバッファ)裏面
	ScreenFlip();
}

void TitleScene::Load()
{
	if (background == -1)
	{
		background = LoadDivGraph("./Resources/Title.png", 8, 8, 1, 1280, 720, back);
	}
	if (cloud == -1)
	{
		cloud = LoadGraph("./Resources/forestback/cloud.png");
	}
}

void TitleScene::Release()
{
	for (size_t i = 0; i < 8; i++)
	{
		DeleteGraph(back[i]);
	}
}
