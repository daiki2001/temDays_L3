#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "Vec.h"

class TitleScene : public BaseScene
{
private: //メンバ関数
	Player player;
	Vec2 cloudPos;
	int volume;

	int back[8]; //背景
	int cloud;   //雲

public: //メンバ関数
	TitleScene(SceneChanger* sceneChanger);
	~TitleScene() override;

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
