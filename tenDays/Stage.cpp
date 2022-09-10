#include "Stage.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	for (int i = (int)boxData.size() - 1; i >= 0; i--)
	{
		delete boxData[i];
		boxData.erase(boxData.begin() + i);
	}
}

void Stage::Init()
{
	stageNum = 1;
	CreateStage();
}

void Stage::CreateStage()
{
	for (int i = (int)boxData.size() - 1; i >= 0; i--)
	{
		delete boxData[i];
		boxData.erase(boxData.begin() + i);
	}

	switch (stageNum)
	{
	case 1:
		StageOne();
		break;
	case 2:
		StageTwo();
		break;
	default:
		break;
	}
}

void Stage::Update()
{
}

void Stage::Draw()
{
	for (int i = 0; i < boxData.size(); i++)
	{
		DrawBox(boxData[i]->pos.x - boxData[i]->size.x, boxData[i]->pos.y - boxData[i]->size.y,
			boxData[i]->pos.x + boxData[i]->size.x, boxData[i]->pos.y + boxData[i]->size.y,
			GetColor(255, 255, 255), true);
	}
}

void Stage::StageAddOne()
{
	stageNum++;
}

void Stage::StageOne()
{
	boxData.push_back(new BoxData);
	boxData[boxData.size() - 1]->pos = { 680.0f,560.0f };
	boxData[boxData.size() - 1]->size = { 1000.0f,20.0f };
	boxData.push_back(new BoxData);
	boxData[boxData.size() - 1]->pos = { 1000.0f,440.0f };
	boxData[boxData.size() - 1]->size = { 120.0f,100.0f };
}

void Stage::StageTwo()
{
	boxData.push_back(new BoxData);
	boxData[boxData.size() - 1]->pos = { 80.0f,560.0f };
	boxData[boxData.size() - 1]->size = { 1000.0f,20.0f };
	boxData.push_back(new BoxData);
	boxData[boxData.size() - 1]->pos = { 100.0f,440.0f };
	boxData[boxData.size() - 1]->size = { 120.0f,100.0f };
}
