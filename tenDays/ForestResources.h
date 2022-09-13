#pragma once
#include "Vec.h"

class ForestResources
{
private: //メンバ変数
	/*背景の小物の情報*/
	Vec2 bigLeafPos;   //大きい葉の座標
	Vec2 smallLeafPos; //小さい葉の座標

	/*背景の小物の画像*/
	int bigLeaf;   //大きい葉
	int smallLeaf; //小さい葉
	int groundAndTree;

	int bgm;

public: //メンバ関数
	ForestResources();
	~ForestResources();

	// 初期化処理
	void Init(int* background);
	// 更新処理
	void Update();
	// 描画処理
	void Draw();

	// 必要なファイルを全て読み込み
	void Load();
	// 読み込んだファイルを全て開放
	void Release();
private:
	// 大きい葉のアニメーション
	void BigLeafAnimation();
	// 小さい葉のアニメーション
	void SmallLeafAnimation();
};
