#include "SelectScene.h"
#include <DxLib.h>
#include "General.h"
#include "./Input/KeyInput.h"
#include "./Input/Controller.h"
#include "Stage.h"

SelectScene::SelectScene(SceneChanger* sceneChanger) :
	BaseScene(sceneChanger),
	selectStage(1),
	oldSelect(1),
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
	oldSelect = selectStage;
	scroll = General::WIN_HEIGHT * (3 - Stage::GetAreaType());
}

void SelectScene::Update()
{
	oldSelect = selectStage;

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

	if (selectStage != oldSelect)
	{
		Stage::SetStageNum(selectStage);
		scroll = General::WIN_HEIGHT * (3 - Stage::GetAreaType());
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
	switch (selectStage)
	{
	case 1:
		DrawGraph(General::WIN_WIDTH / 2 - 100, General::WIN_HEIGHT / 2, cursor, true);
		break;
	case 2:
		DrawGraph(General::WIN_WIDTH / 2 - 200, General::WIN_HEIGHT / 2 - 200, cursor, true);
		break;
	case 3:
		DrawGraph(General::WIN_WIDTH / 2 - 100, 0, cursor, true);
		break;
	case 4:
		DrawGraph(General::WIN_WIDTH / 2 - 100, General::WIN_HEIGHT / 2 - 200, cursor, true);
		break;
	case 5:
		DrawGraph(General::WIN_WIDTH / 2 - 150, General::WIN_HEIGHT / 2 - 190, cursor, true);
		break;
	case 6:
		DrawGraph(310, 100, cursor, true);
		break;
	default:
		break;
	}
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
