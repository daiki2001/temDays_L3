#include "TitleScene.h"
#include <DxLib.h>
#include "General.h"
#include "./Input/KeyInput.h"
#include "./Input/Controller.h"
#include "Collision.h"

namespace
{
int backAnimation = 0;
}

TitleScene::TitleScene(SceneChanger* sceneChanger) :
	BaseScene(sceneChanger),
	player{},
	cloudPos{},
	volume(0x80),
	back{},
	cloud(-1)
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
	ChangeVolumeSoundMem(volume, General::defaultSound);
	if (CheckSoundMem(General::defaultSound) == 0)
	{
		PlaySoundMem(General::defaultSound, DX_PLAYTYPE_LOOP);
	}
}

void TitleScene::Update()
{
	if ((General::Frame::GetFrame() % 5) == 0)
	{
		++backAnimation %= 8;
	}

	cloudPos.x += 1.0f;
	if (cloudPos.x >= 1280.0f)
	{
		cloudPos.x -= 1280.0f;
	}

	player.Update();
	player.EffectUpdate();

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
			nextScene = SceneChanger::Scene::Select;
			changeAnimation.Start();
		}
	}
}

void TitleScene::Draw()
{
	// 背景
	DrawGraph(0, 0, back[backAnimation], false);
	DrawGraph(static_cast<int>(cloudPos.x), static_cast<int>(cloudPos.y), cloud, true);
	DrawGraph(static_cast<int>(cloudPos.x) - 1280, static_cast<int>(cloudPos.y), cloud, true);

	// オブジェクト
	player.Draw(Vec2());
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
	if (General::defaultSound == -1)
	{
		General::defaultSound = LoadSoundMem("./Resources/sound/BGM/0titlestageoption.mp3");
	}
}

void TitleScene::Release()
{
	background = -1;
	for (size_t i = 0; i < 8; i++)
	{
		if (DeleteGraph(back[i]) == 0)
		{
			back[i] = -1;
		}
	}
	if (DeleteGraph(cloud) == 0)
	{
		cloud = -1;
	}
}
