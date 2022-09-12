#pragma once

class SceneChanger
{
public: // サブクラス
	enum Scene
	{
		Title,
		Game,
		Select
	};

public: // メンバ関数
	SceneChanger() = default;
	~SceneChanger() = default;

	virtual void SceneChange(const SceneChanger::Scene scene, const bool stackClear) = 0;
	virtual int PopScene() = 0;
};
