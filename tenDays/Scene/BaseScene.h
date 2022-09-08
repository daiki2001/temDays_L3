#pragma once
#include "SceneChenge.h"

class BaseScene
{
protected: //メンバ変数
	SceneChenger* sceneChenger;
	int background; //背景画像

public: //メンバ関数
	BaseScene(SceneChenger* sceneChenger);
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