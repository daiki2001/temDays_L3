#include "Scenemanager.h"

#include "TitleScene.h"
#include "GameScene.h"
#include "SelectScene.h"

SceneManager::SceneManager()
{
	sceneStack.push(std::make_shared<TitleScene>(this));
}

void SceneManager::Loop() const
{
	sceneStack.top()->Update();
	sceneStack.top()->Draw();
}

void SceneManager::SceneChenge(const SceneChenger::Scene scene, const bool stackClear)
{
	using namespace std;

	if (stackClear)
	{
		while (sceneStack.empty() == false)
		{
			sceneStack.pop();
		}
	}

	switch (scene)
	{
	case SceneChenger::Scene::Title:
		sceneStack.push(make_shared<TitleScene>(this));
		break;
	case SceneChenger::Scene::Game:
		sceneStack.push(make_shared<GameScene>(this));
		break;
	case SceneChenger::Scene::Select:
		sceneStack.push(make_shared<SelectScene>(this));
		break;
	default:
		OutputDebugStringA("存在しないシーンが呼ばれました\n");
		break;
	}
}

int SceneManager::PopScene()
{
	if (sceneStack.size() <= 1)
	{
		return -1;
	}

	sceneStack.pop();

	return 0;
}
