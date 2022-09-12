#pragma once

class SceneChangeEffect
{
private: //メンバ変数
	bool isStart;  //シーン遷移のアニメーションが行われているかどうか
	bool isChange; //シーン遷移するかどうか

	int radius; //半径

public: //メンバ関数
	SceneChangeEffect();
	~SceneChangeEffect();

	void Init();
	void Update();
	void Draw();

	bool GetChange() { return isChange; }
};
