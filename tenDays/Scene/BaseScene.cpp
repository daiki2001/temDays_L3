#include "BaseScene.h"

BaseScene::BaseScene(SceneChenger* sceneChenger) :
	sceneChenger(sceneChenger),
	background(-1)
{
}

BaseScene::~BaseScene()
{
	sceneChenger = nullptr;
}
