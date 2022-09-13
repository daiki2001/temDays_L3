#include "SceneChangeAnimation.h"
#include <DxLib.h>
#include "General.h"
#include <math.h>

namespace
{
constexpr int maxSize = 880;
}

SceneChangeAnimation::SceneChangeAnimation() :
	isAnimation(false),
	isChange(false),
	radius(1),
	maskScreen(-1),
	tempScreen(-1),
	sound(-1)
{
	Init();
}

SceneChangeAnimation::~SceneChangeAnimation()
{
	Release();
}

void SceneChangeAnimation::Init()
{
	isAnimation = false;
	isChange = false;
	radius = maxSize;

	Load();
}

void SceneChangeAnimation::Update()
{
	if (isAnimation == false)
	{
		return;
	}

	static const int changeSpeed = 10;

	if (isChange)
	{
		radius += changeSpeed;
		if (radius > maxSize)
		{
			isAnimation = false;
		}
	}
	else
	{
		radius -= changeSpeed;
		if (radius < -50)
		{
			isChange = true;
		}
	}
}

void SceneChangeAnimation::Draw()
{
	using namespace General;

	static const int color = GetColor(0xFF, 0xFF, 0xFF);

	if (isAnimation)
	{
		// マスク用の画面に円を描画
		SetDrawScreen(maskScreen);
		ClearDrawScreen();

		if (radius > 0)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0x80);
			DrawCircle(WIN_WIDTH / 2, WIN_HEIGHT / 2, radius, color, true);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0xFF);
			DrawCircle(WIN_WIDTH / 2, WIN_HEIGHT / 2, radius - 128, color, true);
		}
	}

	// 裏画面に描画先を変更
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();

	if (isAnimation)
	{
		// 描画時の合成画像にマスク画面を設定
		SetBlendGraphParam(maskScreen, DX_BLENDGRAPHTYPE_ALPHA);

		DrawBox(0, 0, WIN_WIDTH, WIN_HEIGHT, color, true);
	}

	// 裏画面に一時保存用のスクリーンを描画
	DrawGraph(0, 0, tempScreen, true);

	// 合成設定を解除
	SetBlendGraphParam(-1, DX_BLENDGRAPHTYPE_NORMAL);
	// 一時保存用のスクリーンに描画先を変更
	SetDrawScreen(tempScreen);
}

void SceneChangeAnimation::Start()
{
	isAnimation = true;
	isChange = false;
	radius = maxSize;
	PlaySoundMem(sound, DX_PLAYTYPE_BACK);
}

void SceneChangeAnimation::Load()
{
	ScreenInit();
	if (sound == -1)
	{
		sound = LoadSoundMem("./Resources/sound/SE/changescene.mp3");
		ChangeVolumeSoundMem(0x80, sound);
	}
}

void SceneChangeAnimation::Release()
{
	if (DeleteGraph(maskScreen) == 0)
	{
		maskScreen = -1;
	}
	if (DeleteGraph(tempScreen) == 0)
	{
		tempScreen = -1;
	}
	if (DeleteSoundMem(sound) == 0)
	{
		sound = -1;
	}
}

void SceneChangeAnimation::ScreenInit()
{
	if (maskScreen == -1)
	{
		maskScreen = MakeScreen(General::WIN_WIDTH, General::WIN_HEIGHT, true);
	}
	if (tempScreen == -1)
	{
		tempScreen = MakeScreen(General::WIN_WIDTH, General::WIN_HEIGHT, true);
		// 一時保存用のスクリーンに描画先を変更
		SetDrawScreen(tempScreen);
	}
}
