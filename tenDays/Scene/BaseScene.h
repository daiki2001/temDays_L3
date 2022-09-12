#pragma once
#include "SceneChange.h"
#include "./Effect/SceneChangeEffect.h"

class BaseScene
{
protected: //静的メンバ変数
	static SceneChangeEffect changeEffect;

public: //静的メンバ関数
	static void ChangeEffectUpdate() { changeEffect.Update(); }

protected: //メンバ変数
	SceneChanger* sceneChanger;
	int background; //背景画像

public: //メンバ関数
	BaseScene(SceneChanger* sceneChanger);
	virtual ~BaseScene();

	// 初期化処理
	virtual void Init() = 0;
	// 更新処理
	virtual void Update() = 0;
	// 描画処理
	virtual void Draw() = 0;

	// 必要なファイルを全て読み込み
	virtual void Load() = 0;
	// 読み込んだファイルを全て開放
	virtual void Release() = 0;
};