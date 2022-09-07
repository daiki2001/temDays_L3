#pragma once

class BaseScene
{
public: //メンバ関数
	BaseScene() = default;
	virtual ~BaseScene() = default;

	// 初期化処理
	virtual void Init() = 0;
	// 更新処理
	virtual void Updata() = 0;
	// 描画処理
	virtual void Draw() = 0;
};