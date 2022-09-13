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
	bigLeaf(-1),
	smallLeaf(-1),
	groundAndTree(-1),
	bigLeafPos(740.0f, 404.0f),
	smallLeafPos(776.0f, 364.0f),
	clear(-1)
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
}

void GameScene::Update()
{
	BigLeafAnimation();
	SmallLeafAnimation();

	if (goal.GetGoal())
	{
		if (Controller::Decision_A() || KeyInput::IsKeyTrigger(KEY_INPUT_SPACE))
		{
			if (stage.GetStageNum() == 3)
			{
				sceneChanger->SceneChange(SceneChanger::Scene::Title, true);
			}
			else
			{
				stage.StageAddOne();
				stage.CreateStage();
				goal.SetGoalPos(stage.GetStageNum());
				evaluate.SetEvaluate(stage.GetStageNum());
				General::AllReset(&player, &goal, &rod, stage.GetStageNum());
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
				sceneChanger->SceneChange(SceneChanger::Scene::Title, true);
				/*stage.StageAddOne();
				stage.CreateStage();*/
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
}

void GameScene::Draw()
{
	// 画面クリア
	ClearDrawScreen();

	// 背景
	DrawGraph(0, 0, background, false);
	DrawGraph(static_cast<int>(bigLeafPos.x), static_cast<int>(bigLeafPos.y), bigLeaf, true);
	DrawGraph(static_cast<int>(smallLeafPos.x), static_cast<int>(smallLeafPos.y), smallLeaf, true);
	DrawGraph(0, 0, groundAndTree, true);

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

	// シーン遷移
	changeEffect.Draw();

	// (ダブルバッファ)裏面
	ScreenFlip();
}

void GameScene::Load()
{
	if (background == -1)
	{
		background = LoadGraph("./Resources/forestback/forestback.png");
	}
	if (bigLeaf == -1)
	{
		bigLeaf = LoadGraph("./Resources/forestback/BigLeaf.png");
	}
	if (smallLeaf == -1)
	{
		smallLeaf = LoadGraph("./Resources/forestback/SmallLeaf.png");
	}
	if (groundAndTree == -1)
	{
		groundAndTree = LoadGraph("./Resources/forestback/ground_tree.png");
	}
	if (clear == -1)
	{
		clear = LoadGraph("./Resources/Clear.png");
	}
}

void GameScene::Release()
{
	DeleteGraph(background);
	DeleteGraph(bigLeaf);
	DeleteGraph(smallLeaf);
	DeleteGraph(groundAndTree);
	DeleteGraph(clear);
}

void GameScene::BigLeafAnimation()
{
	static const int maxCount = 16;
	static int animationCount = 0;

	if ((General::Frame::GetFrame() % 6) == 0)
	{
		animationCount++;

		if (animationCount >= maxCount)
		{
			bigLeafPos.x = 740.0f;
			bigLeafPos.y = 404.0f;
			animationCount -= maxCount;
		}
		else
		{
			bigLeafPos.x -= 14.0f;
			bigLeafPos.y += 8.0f;
		}
	}
}

void GameScene::SmallLeafAnimation()
{
	static const int maxCount = 16;
	static int animationCount = 0;

	if ((General::Frame::GetFrame() % 6) == 0)
	{
		animationCount++;

		if (animationCount >= maxCount)
		{
			smallLeafPos.x = 776.0f;
			smallLeafPos.y = 364.0f;
			animationCount -= maxCount;
		}
		else
		{
			if ((animationCount % 4) == 0)
			{
				smallLeafPos.x += 2.0f * animationCount;
			}
			else
			{
				smallLeafPos.x -= 2.0f * animationCount;
			}
			if ((animationCount % 2) == 0)
			{
				smallLeafPos.y += 14.0f;
			}
			else
			{
				smallLeafPos.y += 26.0f;
			}
		}
	}
}
