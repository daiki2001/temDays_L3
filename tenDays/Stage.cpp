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
	Load();
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
	case 3:
		StageThree();
	default:
		break;
	}
}

void Stage::Update()
{
}

void Stage::Draw()
{
	static const int graphSize = 128;

	for (int i = 0; i < boxData.size(); i++)
	{
		//DrawBox(boxData[i]->pos.x - boxData[i]->size.x, boxData[i]->pos.y - boxData[i]->size.y,
		//	boxData[i]->pos.x + boxData[i]->size.x, boxData[i]->pos.y + boxData[i]->size.y,
		//	GetColor(255, 255, 255), true);
		if (boxData[i]->type == BOX)
		{
			for (size_t y = 0; y * graphSize < boxData[i]->size.y * 2; y++)
			{
				int up = (boxData[i]->pos.y - boxData[i]->size.y) + (y * graphSize);
				bool isRect = (up + graphSize) > (boxData[i]->pos.y + boxData[i]->size.y);

				for (size_t x = 0; x * graphSize < boxData[i]->size.x * 2; x++)
				{
					int left = (boxData[i]->pos.x - boxData[i]->size.x) + (x * graphSize);
					isRect |= (left + graphSize) > (boxData[i]->pos.x + boxData[i]->size.x);

					if (isRect)
					{
						int width = graphSize;
						int height = graphSize;

						if ((left + graphSize) > static_cast<int>(boxData[i]->pos.x + boxData[i]->size.x))
						{
							width -= (left + graphSize) - static_cast<int>(boxData[i]->pos.x + boxData[i]->size.x);
						}
						if ((up + graphSize) > static_cast<int>(boxData[i]->pos.y + boxData[i]->size.y))
						{
							height -= (up + graphSize) - static_cast<int>(boxData[i]->pos.y + boxData[i]->size.y);
						}

						DrawRectGraph(left, up, 0, 0, width, height, cubeBlock, true);
					}
					else
					{
						DrawGraph(left, up, cubeBlock, true);
					}
				}
			}
		}
		else if (boxData[i]->type == TRIANGLE)
		{
			DrawTriangle(boxData[i]->pos.x + boxData[i]->size.x, boxData[i]->pos.y - boxData[i]->size.y,
				boxData[i]->pos.x + boxData[i]->size.x, boxData[i]->pos.y + boxData[i]->size.y,
				boxData[i]->pos.x - boxData[i]->size.x, boxData[i]->pos.y + boxData[i]->size.y,
				GetColor(255, 255, 255), TRUE);
		}
	}
}

void Stage::StageAddOne()
{
	stageNum++;
}

void Stage::Load()
{
	if (cubeBlock == -1)
	{
		cubeBlock = LoadGraph("./Resources/block/cube/groundcube1.png");
	}
}

void Stage::StageOne()
{
	boxData.push_back(new BoxData);
	boxData[boxData.size() - 1]->pos = { 680.0f,600.0f };
	boxData[boxData.size() - 1]->size = { 1000.0f,20.0f };
	boxData[boxData.size() - 1]->type = FLOOR;
	boxData.push_back(new BoxData);
	boxData[boxData.size() - 1]->pos = { 1000.0f,480.0f };
	boxData[boxData.size() - 1]->size = { 120.0f,100.0f };
}

void Stage::StageTwo()
{
	boxData.push_back(new BoxData);//床
	boxData[boxData.size() - 1]->pos = { 500.0f,600.0f };
	boxData[boxData.size() - 1]->size = { 1000.0f,20.0f };
	boxData[boxData.size()-1]->type = FLOOR;
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
	boxData[boxData.size() - 1]->type = TRIANGLE;
	boxData[boxData.size() - 1]->pos = { 880.0f,510.0f };
}

void Stage::StageThree()
{
	boxData.push_back(new BoxData);//床
	boxData[boxData.size() - 1]->pos = { 500.0f,600.0f };
	boxData[boxData.size() - 1]->size = { 1000.0f,20.0f };
	boxData[boxData.size() - 1]->type = FLOOR;

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 550.0f,530.0f };
	boxData[boxData.size() - 1]->size = { 30.0f,50.0f };
	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 550.0f,300.0f };
	boxData[boxData.size() - 1]->size = { 30.0f,90.0f };


	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 870.0f,180.0f };
	boxData[boxData.size() - 1]->size = { 290.0f,30.0f };
	

	boxData.push_back(new BoxData);//三角形
	boxData[boxData.size() - 1]->pos = { 1000.0f,480.0f };
	boxData[boxData.size() - 1]->size = { 100.0f,100.0f };
	boxData[boxData.size() - 1]->type = TRIANGLE;
	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1130.0f,310.0f };
	boxData[boxData.size() - 1]->size = { 40.0f,270.0f };
}
