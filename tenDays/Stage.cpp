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
	stageNum = 2;
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
		if (boxData[i]->type == 0)
		{
			DrawBox(boxData[i]->pos.x - boxData[i]->size.x, boxData[i]->pos.y - boxData[i]->size.y,
				boxData[i]->pos.x + boxData[i]->size.x, boxData[i]->pos.y + boxData[i]->size.y,
				GetColor(255, 255, 255), true);
		}
		else if (boxData[i]->type == 1)
		{
			DrawTriangle(
				boxData[i]->pos.x + boxData[i]->size.x, boxData[i]->pos.y - boxData[i]->size.y,//右上
				boxData[i]->pos.x + boxData[i]->size.x, boxData[i]->pos.y + boxData[i]->size.y,//右下
				boxData[i]->pos.x - boxData[i]->size.x, boxData[i]->pos.y + boxData[i]->size.y,//左下
				GetColor(255, 255, 255), TRUE);
		}
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
	boxData.push_back(new BoxData);//床
	boxData[boxData.size() - 1]->pos = { 500.0f,600.0f };
	boxData[boxData.size() - 1]->size = { 1000.0f,20.0f };
	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1000.0f,490.0f };
	boxData[boxData.size() - 1]->size = { 40.0f,100.0f };
	boxData.push_back(new BoxData);//正方形
	boxData[boxData.size() - 1]->pos = { 1000.0f,290.0f };
	boxData[boxData.size() - 1]->size = { 40.0f,40.0f };
	boxData.push_back(new BoxData);//正方形
	boxData[boxData.size() - 1]->pos = { 1000.0f,140.0f };
	boxData[boxData.size() - 1]->size = { 40.0f,40.0f };
	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1080.0f,80.0f };
	boxData[boxData.size() - 1]->size = { 40.0f,100.0f };
	boxData.push_back(new BoxData);//三角形
	boxData[boxData.size() - 1]->size = { 80.0f,80.0f };
	boxData[boxData.size() - 1]->type = 1;
	boxData[boxData.size() - 1]->pos = { 880.0f,510.0f };
}
