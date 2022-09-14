#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "Goal.h"
#include "Stage.h"
#include "Rod.h"
#include"Evaluate.h"
#include"Scroll.h"
#include "ForestResources.h"

class GameScene : public BaseScene
{
private: //メンバ変数
	Player player; //プレイヤー
	Rod rod;       //棒
	Goal goal;     //ゴール
	Stage stage;   //ステージ
	Evaluate evaluate;//評価
	Scroll scroll;	//スクロール
	bool isNext; //次のステージに行くかどうか

	int clear; //クリア時のテキスト
	ForestResources forestRes; //森ステージのリソース

	int startSound; //開始時の音

public: //メンバ関数
	GameScene(SceneChanger* sceneChanger);
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
