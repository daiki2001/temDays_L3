#include "SelectScene.h"
#include <DxLib.h>
#include "./Input/KeyInput.h"
#include "./Input/Controller.h"

SelectScene::SelectScene(SceneChanger* sceneChanger) :
	BaseScene(sceneChanger)
{
}

SelectScene::~SelectScene()
{
}

void SelectScene::Init()
{
}

void SelectScene::Update()
{
	if (Controller::Decision_A() || KeyInput::IsKeyTrigger(KEY_INPUT_SPACE))
	{
		isSceneDest = true;
		nextScene = SceneChanger::Scene::Game;
		changeAnimation.Start();
	}

	if (isSceneDest && changeAnimation.GetChange())
	{
		sceneChanger->SceneChange(nextScene, true);
	}
}

void SelectScene::Draw()
{
	// 背景

	// オブジェクト
}

void SelectScene::Load()
{
}

void SelectScene::Release()
{
}
