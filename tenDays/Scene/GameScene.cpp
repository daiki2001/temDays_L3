#include "GameScene.h"
#include <DxLib.h>
#include "General.h"
#include "./Input/KeyInput.h"
#include "./Input/Controller.h"
#include "PushCollision.h"

GameScene::GameScene(SceneChanger* sceneChanger) :
	BaseScene(sceneChanger),
	player{},
	rod{},
	goal(General::WIN_WIDTH - 200, General::WIN_HEIGHT / 2 - 50),
	stage{},
	isNext(false),
	clear(-1),
	forestRes{}
{
	Load();
	Init();
}

GameScene::~GameScene()
{
	Release();
}

void GameScene::Init()
{
	player.Init();
	stage.Init();
	rod.Init();
	goal.SetGoalPos(stage.GetStageNum());
	evaluate.Init(stage.GetStageNum());
	evaluate.Start();

	if (stage.GetStageNum() <= 3)
	{
		forestRes.Init(&background);
	}
}

void GameScene::Update()
{
	forestRes.Update();

	if (goal.GetGoal())
	{
		if (Controller::Decision_A() || KeyInput::IsKeyTrigger(KEY_INPUT_SPACE))
		{
			if (stage.GetStageNum() == 3)
			{
				isSceneDest = true;
				nextScene = SceneChanger::Scene::Title;
				changeAnimation.Start();
			}
			else
			{
				isNext = true;
				changeAnimation.Start();
			}
		}
	}
	else
	{
		player.Update();
		rod.Update();
		evaluate.Update();
		bool IsHitWall = false;
		bool IsHitGround = false;
		bool IsHitCeiling = false;
		//挟まったかどうか
		bool IsGetCaught = false;
		bool IsHitTriangle = false;
		for (int i = 0; i < stage.GetBoxDataNum(); i++)
		{
			player.SetPosition(PushCollision::PushPlayer2Box(player.GetPos(), player.GetSize(), player.GetOldPos(),
				stage.GetBoxPos(i), stage.GetBoxSize(i), stage.GetType(i),
				IsHitWall, IsHitGround, IsHitTriangle, IsHitCeiling));
		}
		//壁にあたったら
		if (IsHitWall)
		{
			player.ChangeFlag();
		}
		if (IsHitCeiling)
		{
			player.BoundPowerZero();
		}
		if (IsHitTriangle)
		{
			//player.WalkSpeedAccel();
			player.SlopeSpeed();
		}
		//プレイヤーと棒
		if (Collision::CollisionTrinangle(player.GetPos(), rod.GetPos(), rod.GetSize(), rod.GetAngle()))
		{
			if (IsHitWall)
			{
				IsGetCaught = true;
			}
			IsHitWall = true;
			player.ChangeHitRod(rod.GetAngle(), rod.GetSpeedMemory());
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
			Vec2(General::WIN_WIDTH / 2.0f, General::WIN_HEIGHT / 2.0f + 50));
		if (isIn == false)
		{
			General::AllReset(&player, &goal, &rod, stage.GetStageNum());
		}

		if (goal.GetGoal())
		{
			if (Controller::Decision_A() || KeyInput::IsKeyTrigger(KEY_INPUT_SPACE))
			{
				isSceneDest = true;
				nextScene = SceneChanger::Scene::Title;
				changeAnimation.Start();
			}
		}
		else
		{
			// リセット
			if (KeyInput::IsKey(KEY_INPUT_R) || IsGetCaught == true)
			{
				General::AllReset(&player, &goal, &rod, stage.GetStageNum());
			}
		}
	}

	player.EffectUpdate();

	if (isNext && changeAnimation.GetChange())
	{
		stage.StageAddOne();
		stage.CreateStage();
		evaluate.SetEvaluate(stage.GetStageNum());
		goal.SetGoalPos(stage.GetStageNum());
		General::AllReset(&player, &goal, &rod, stage.GetStageNum());

		isNext = false;
	}
	if (isSceneDest && changeAnimation.GetChange())
	{
		sceneChanger->SceneChange(nextScene, true);
	}
}

void GameScene::Draw()
{
	// 背景
	DrawGraph(0, 0, background, false);
	if (stage.GetStageNum() <= 3)
	{
		forestRes.Draw();
	}

	// オブジェクト
	goal.Draw();
	stage.Draw();

	rod.Draw();
	player.Draw();

	// 前景
	if (goal.GetGoal())
	{
		evaluate.GoalDraw();
		//DrawString(0, 0, "Goal", GetColor(0xFF, 0xFF, 0xFF));
		//DrawGraph(General::WIN_WIDTH / 2 - 301, General::WIN_HEIGHT / 2 - 95, clear, true);
	}
	else
	{
		evaluate.PlayDraw();
	}
}

void GameScene::Load()
{
	if (clear == -1)
	{
		clear = LoadGraph("./Resources/Clear.png");
	}
}

void GameScene::Release()
{
	DeleteGraph(background);
	DeleteGraph(clear);
	forestRes.Release();
}
