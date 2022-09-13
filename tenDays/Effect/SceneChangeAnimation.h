#pragma once

class SceneChangeAnimation
{
private: //メンバ変数
	bool isAnimation;  //シーン遷移のアニメーションが行われているかどうか
	bool isChange; //シーン遷移するかどうか

	int radius; //半径

	int maskScreen; //マスク用のスクリーン
	int tempScreen; //一時保存用のスクリーン

public: //メンバ関数
	SceneChangeAnimation();
	~SceneChangeAnimation();

	void Init();
	void Update();
	void Draw();
	void Start();

	void ScreenInit();

	bool GetChange() { return isChange; }
};
