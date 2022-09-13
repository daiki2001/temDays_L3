#include "BaseScene.h"

SceneChangeAnimation BaseScene::changeAnimation = {};

BaseScene::BaseScene(SceneChanger* sceneChanger) :
	sceneChanger(sceneChanger),
	isSceneDest(false),
	nextScene(SceneChanger::Scene::Title),
	background(-1)
{
	changeAnimation.ScreenInit();
}

BaseScene::~BaseScene()
{
	sceneChanger = nullptr;
}
