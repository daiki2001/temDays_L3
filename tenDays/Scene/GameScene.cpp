#include "GameScene.h"
#include <DxLib.h>
#include "General.h"
#include "./Input/KeyInput.h"
#include "./Input/Controller.h"
#include "PushCollision.h"

GameScene::GameScene(SceneChenger* sceneChenger) :
	BaseScene(sceneChenger),
	player{},
	rod{},
	goal(General::WIN_WIDTH - 100, General::WIN_HEIGHT / 2),
	stage{}
{
	Init();
}

GameScene::~GameScene()
{
	Release();
}

void GameScene::Init()
{
	Load();
	stage.Init();
	rod.Init();
}

void GameScene::Update()
{
	if (goal.GetGoal())
	{
		if (Controller::Decision_A() || KeyInput::IsKeyTrigger(KEY_INPUT_SPACE))
		{
			sceneChenger->SceneChenge(SceneChenger::Scene::Title, true);
		}
	}
	else
	{
		player.Update();
		rod.Update();

		bool IsHitWall = false;
		bool IsHitGround = false;
		for (int i = 0; i < stage.boxMax; i++)
		{
			player.SetPosition(PushCollision::PushPlayer2Box(player.GetPos(), player.GetSize(), player.GetOldPos(),
															 stage.GetBoxPos(i), stage.GetBoxSize(i), IsHitWall, IsHitGround));
		}
		//プレイヤーと棒
		player.SetPosition(PushCollision::PushPlayer2Box(player.GetPos(), player.GetSize(), player.GetOldPos(),
														 rod.GetPos(), rod.GetSize(), IsHitWall, IsHitGround));

		//壁にあたったら
		if (IsHitWall)
		{
			player.ChangeFlag();
		}
		//地面に接している
		if (IsHitGround)
		{
			player.ChangeBoundFlag();
		}

		goal.Update(player.GetPos());

		// 画面外判定
		bool isIn = Collision::BoxCollision(player.GetPos(),
											Vec2(General::WIN_WIDTH / 2.0f, General::WIN_HEIGHT / 2.0f),
											Vec2(player.GetSize(), player.GetSize()),
											Vec2(General::WIN_WIDTH / 2.0f, General::WIN_HEIGHT / 2.0f));
		// リセット
		if (isIn == false || KeyInput::IsKey(KEY_INPUT_R))
		{
			General::AllReset(&player, &goal, &rod);
		}
	}
}

void GameScene::Draw()
{
	// 画面クリア
	ClearDrawScreen();

	// 背景
	//DrawGraph(0, 0, background, false);

	//オブジェクト
	goal.Draw();
	player.Draw();
	stage.Draw();

	rod.Draw();

	if (goal.GetGoal())
	{
		DrawString(0, 0, "Goal", GetColor(0xFF, 0xFF, 0xFF));
	}

	// 前景
	
	// (ダブルバッファ)裏面
	ScreenFlip();
}

void GameScene::Load()
{
	if (background == -1)
	{
		LoadGraph("./Resources/Title.png");
	}
}

void GameScene::Release()
{
	DeleteGraph(background);
}
