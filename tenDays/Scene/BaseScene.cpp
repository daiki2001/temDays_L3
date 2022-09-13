#include "BaseScene.h"

SceneChangeEffect BaseScene::changeEffect = {};

BaseScene::BaseScene(SceneChanger* sceneChanger) :
	sceneChanger(sceneChanger),
	background(-1)
{
}

BaseScene::~BaseScene()
{
	sceneChanger = nullptr;
}
