#pragma once
#include "SceneChenge.h"
#include "BaseScene.h"
#include <memory>
#include <stack>

class SceneManager : public SceneChenger
{
public: // メンバ関数
	SceneManager();
	~SceneManager() {}

	void Loop() const;
	void SceneChenge(const SceneChenger::Scene scene, const bool stackClear) override;
	int PopScene() override;

private: // メンバ変数
	std::stack<std::shared_ptr<BaseScene>> sceneStack;
};
