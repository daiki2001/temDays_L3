#pragma once
#include "BaseScene.h"

class TitleScene : public BaseScene
{
public: //メンバ関数
	TitleScene(SceneChenger* sceneChenger);
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
