#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "Goal.h"
#include "Stage.h"
#include "Rod.h"

class GameScene : public BaseScene
{
private: //メンバ変数
	Player player; //プレイヤー
	Rod rod;       //棒
	Goal goal;     //ゴール
	Stage stage;   //ステージ

public: //メンバ関数
	GameScene(SceneChenger* sceneChenger);
	~GameScene() override;

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
