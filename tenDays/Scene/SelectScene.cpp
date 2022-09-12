#include "SelectScene.h"
#include <DxLib.h>

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
}

void SelectScene::Draw()
{
	// 画面クリア
	ClearDrawScreen();

	// 背景

	// オブジェクト

	// シーン遷移
	changeEffect.Draw();

	// (ダブルバッファ)裏面
	ScreenFlip();
}

void SelectScene::Load()
{
}

void SelectScene::Release()
{
}
