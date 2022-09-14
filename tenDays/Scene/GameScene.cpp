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
	signboard(-1),
	clear(-1),
	forestRes{},
	startSound(-1)
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
	static bool nowAnimation = changeAnimation.GetAnimation(); //現在の遷移アニメーションの有無
	static bool oldAnimation = nowAnimation; //前フレームの遷移アニメーションの有無

	oldAnimation = nowAnimation;
	nowAnimation = changeAnimation.GetAnimation();

	if ((nowAnimation == false) && (oldAnimation == true))
	{
		evaluate.Start();
		PlaySoundMem(startSound, DX_PLAYTYPE_BACK);
	}

	forestRes.Update();

	if (goal.GetGoal())
	{
		if (Controller::Decision_A() || KeyInput::IsKeyTrigger(KEY_INPUT_SPACE))
		{
			if (stage.GetStageNum() == 4)
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
		if (nowAnimation == false)
		{
			player.Update();
			rod.Update(scroll.GetScroll());
			stage.Update();
			evaluate.Update();
			scroll.Update(player.GetPos(), stage.GetStageNum());
		}

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
			Vec2(General::WIN_WIDTH / 2.0f, 0),
			Vec2(player.GetSize(), player.GetSize()),
			Vec2(General::WIN_WIDTH / 2.0f, General::WIN_HEIGHT + 50));
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
	if (stage.GetStageNum() == 1)
	{
		DrawGraph(General::WIN_WIDTH / 2 - 128, 480 - 128, signboard, true);
	}

	if (stage.GetStageNum() <= 3)
	{
		forestRes.Draw();
	}

	// オブジェクト
	goal.Draw(scroll.GetScroll());
	stage.Draw(scroll.GetScroll());

	rod.Draw(scroll.GetScroll());
	player.Draw(scroll.GetScroll());

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
	if (signboard == -1)
	{
		signboard = LoadGraph("./Resources/notice.png");
	}
	if (clear == -1)
	{
		clear = LoadGraph("./Resources/Clear.png");
	}
	if (startSound == -1)
	{
		startSound = LoadSoundMem("./Resources/sound/SE/start.mp3");
		ChangeVolumeSoundMem(0x80, startSound);
	}
}

void GameScene::Release()
{
	DeleteGraph(background);
	if (DeleteGraph(signboard) == 0)
	{
		signboard = -1;
	}
	DeleteGraph(clear);
	forestRes.Release();
	DeleteSoundMem(startSound);
}
