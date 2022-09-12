#pragma once
#include "SceneChange.h"
#include "BaseScene.h"
#include <memory>
#include <stack>

class SceneManager : public SceneChanger
{
public: // メンバ関数
	SceneManager();
	~SceneManager() {}

	void Loop() const;
	void SceneChange(const SceneChanger::Scene scene, const bool stackClear) override;
	int PopScene() override;

private: // メンバ変数
	std::stack<std::shared_ptr<BaseScene>> sceneStack;
};
