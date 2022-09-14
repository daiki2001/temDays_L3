#include "SelectScene.h"
#include <DxLib.h>
#include "General.h"
#include "./Input/KeyInput.h"
#include "./Input/Controller.h"
#include "Stage.h"

SelectScene::SelectScene(SceneChanger* sceneChanger) :
	BaseScene(sceneChanger),
	selectStage(1),
	scroll(General::WIN_HEIGHT * 3),
	cursor(-1)
{
	Load();
	Init();
}

SelectScene::~SelectScene()
{
	Release();
}

void SelectScene::Init()
{
	selectStage = Stage::GetStageNum();
	scroll = General::WIN_HEIGHT * 3;
}

void SelectScene::Update()
{
	if (Controller::SelectDown() || KeyInput::IsKeyTrigger(KEY_INPUT_DOWN))
	{
		selectStage--;
		if (selectStage < 1)
		{
			selectStage = 1;
		}
	}
	if (Controller::SelectUp() || KeyInput::IsKeyTrigger(KEY_INPUT_UP))
	{
		selectStage++;
		if (selectStage > 6)
		{
			selectStage = 6;
		}
	}

	if (isSceneDest)
	{
		if (changeAnimation.GetChange())
		{
			sceneChanger->SceneChange(nextScene, true);
		}
	}
	else
	{
		if (Controller::Decision_A() || KeyInput::IsKeyTrigger(KEY_INPUT_SPACE))
		{
			isSceneDest = true;
			nextScene = SceneChanger::Scene::Game;
			changeAnimation.Start();
		}
	}
}

void SelectScene::Draw()
{
	// 背景
	DrawGraph(0, 0 - scroll, background, true);

	// オブジェクト
}

void SelectScene::Load()
{
	if (background == -1)
	{
		background = LoadGraph("./Resources/select/stagechoice.png");
	}
	if (cursor == -1)
	{
		cursor = LoadGraph("./Resources/select/teacherclick.png");
	}
}

void SelectScene::Release()
{
	if (DeleteGraph(background) == 0)
	{
		background = -1;
	}
	if (DeleteGraph(cursor) == 0)
	{
		cursor = -1;
	}
}
