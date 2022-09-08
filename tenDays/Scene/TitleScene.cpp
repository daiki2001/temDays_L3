#include "TitleScene.h"
#include <DxLib.h>
#include "./Input/KeyInput.h"
#include "./Input/Controller.h"

TitleScene::TitleScene(SceneChenger* sceneChenger) :
	BaseScene(sceneChenger)
{
	Init();
}

TitleScene::~TitleScene()
{
	Release();
}

void TitleScene::Init()
{
	Load();
}

void TitleScene::Update()
{
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
	DrawGraph(0, 0, background, false);

	// (ダブルバッファ)裏面
	ScreenFlip();
}

void TitleScene::Load()
{
	if (background == -1)
	{
		background = LoadGraph("./Resources/Title.png");
	}
}

void TitleScene::Release()
{
	DeleteGraph(background);
}
