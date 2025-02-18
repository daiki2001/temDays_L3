﻿#pragma once
#include "BaseScene.h"

class SelectScene : public BaseScene
{
private: //メンバ変数
	int selectStage; //選択しているステージ
	int oldSelect;   //前フレームに選択していたステージ
	int scroll;      //スクロール値

	int cursor;
	int selectSound;

public: //メンバ関数
	SelectScene(SceneChanger* sceneChanger);
	~SelectScene() override;

	// 初期化処理
	void Init() override;
	// 更新処理
	void Update() override;
	// 描画処理
	void Draw() override;

	// 必要なファイルを全て読み込み
	void Load() override;
	// 読み込んだファイルを全て開放
	void Release() override;
};
