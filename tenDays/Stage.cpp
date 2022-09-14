#include "Stage.h"
#include "General.h"

int Stage::stageNum = 1;
AreaType Stage::areaType = AreaType::FOREST;

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
		break;
	case 4:
		StageFour();
		break;
	case 5:
		StageFive();
		break;
	case 6:
		StageSix();
		break;
	default:
		break;
	}
}

void Stage::Update()
{
	for (int i = 0; i < boxData.size(); i++)
	{
		if (boxData[i]->type == MOVEBOX)
		{
			if (boxData[i]->isMoveFlag == false)
			{
				boxData[i]->pos.x -= 2.0f;
				if (boxData[i]->pos.x < boxData[i]->minPos.x)
				{
					boxData[i]->pos.x = boxData[i]->minPos.x;
					boxData[i]->isMoveFlag = true;
				}
			}
			else
			{
				boxData[i]->pos.x += 2.0f;
				if (boxData[i]->pos.x > boxData[i]->maxPos.x)
				{
					boxData[i]->pos.x = boxData[i]->maxPos.x;
					boxData[i]->isMoveFlag = false;
				}
			}
		}
	}
}

void Stage::Draw(Vec2 scroll)
{
	for (int i = 0; i < boxData.size(); i++)
	{
		if (boxData[i]->type == BOX)
		{
			General::TiringDraw(boxData[i]->pos - boxData[i]->size - scroll, boxData[i]->size * 2.0f, cubeBlock, { 128.0f, 128.0f });
		}
		else if (boxData[i]->type == TRIANGLE)
		{
			DrawExtendGraph(static_cast<int>(boxData[i]->pos.x + boxData[i]->size.x), static_cast<int>(boxData[i]->pos.y - boxData[i]->size.y - scroll.y),
				static_cast<int>(boxData[i]->pos.x - boxData[i]->size.x), static_cast<int>(boxData[i]->pos.y + boxData[i]->size.y - scroll.y),
				triangleBlock, true);
		}
		else if (boxData[i]->type == MOVEBOX)
		{
			General::TiringDraw(boxData[i]->pos - boxData[i]->size - scroll, boxData[i]->size * 2.0f, cubeBlock, { 128.0f, 128.0f });
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
	if (triangleBlock == -1)
	{
		triangleBlock = LoadGraph("./Resources/block/triangle/wallcube2.png");
	}
}

void Stage::SetStageNum(const int& stageNum)
{
	Stage::stageNum = stageNum;
	if (Stage::stageNum <= 3)
	{
		areaType = AreaType::FOREST;
	}
	else if (Stage::stageNum <= 4)
	{
		areaType = AreaType::STATION;
	}
	else if (Stage::stageNum <= 5)
	{
		areaType = AreaType::FUJI;
	}
	else
	{
		areaType = AreaType::UNIVERSE;
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

	boxData.push_back(new BoxData);
	boxData[boxData.size() - 1]->pos = { 1150.0f,280.0f };
	boxData[boxData.size() - 1]->size = { 40.0f,300.0f };
}

void Stage::StageTwo()
{
	boxData.push_back(new BoxData);//床
	boxData[boxData.size() - 1]->pos = { 500.0f,600.0f };
	boxData[boxData.size() - 1]->size = { 1000.0f,20.0f };
	boxData[boxData.size() - 1]->type = FLOOR;
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

void Stage::StageFour()
{
	boxData.push_back(new BoxData);//床
	boxData[boxData.size() - 1]->pos = { 500.0f,600.0f };
	boxData[boxData.size() - 1]->size = { 900.0f,20.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1200.0f,360.0f };
	boxData[boxData.size() - 1]->size = { 30.0f,360.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 300.0f,0.0f };
	boxData[boxData.size() - 1]->size = { 280.0f,20.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1200.0f,-360.0f };
	boxData[boxData.size() - 1]->size = { 30.0f,360.0f };
	boxData[boxData.size() - 1]->minPos = { 700.0f,-190.0f };
	boxData[boxData.size() - 1]->maxPos = { 1200.0f,-190.0f };
	boxData[boxData.size() - 1]->type = MOVEBOX;


	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 290.0f,-350.0f };
	boxData[boxData.size() - 1]->size = { 110.0f,20.0f };


	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 200.0f,-440.0f };
	boxData[boxData.size() - 1]->size = { 20.0f,110.0f };
}

void Stage::StageFive()
{
	boxData.push_back(new BoxData);//床
	boxData[boxData.size() - 1]->pos = { 500.0f,665.0f };
	boxData[boxData.size() - 1]->size = { 900.0f,20.0f };

	boxData.push_back(new BoxData);//正方形
	boxData[boxData.size() - 1]->pos = { 350.0f,615.0f };
	boxData[boxData.size() - 1]->size = { 30.0f,30.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1230.0f,440.0f };
	boxData[boxData.size() - 1]->size = { 30.0f,220.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 670.0f,400.0f };
	boxData[boxData.size() - 1]->size = { 200.0f,35.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 460.0f,330.0f };
	boxData[boxData.size() - 1]->size = { 200.0f,35.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 110.0f,260.0f };
	boxData[boxData.size() - 1]->size = { 200.0f,35.0f };

	boxData.push_back(new BoxData);//正方形
	boxData[boxData.size() - 1]->pos = { 860.0f,110.0f };
	boxData[boxData.size() - 1]->size = { 40.0f,40.0f };

	boxData.push_back(new BoxData);//正方形
	boxData[boxData.size() - 1]->pos = { 780.0f,20.0f };
	boxData[boxData.size() - 1]->size = { 40.0f,40.0f };

	boxData.push_back(new BoxData);//正方形
	boxData[boxData.size() - 1]->pos = { 700.0f,-50.0f };
	boxData[boxData.size() - 1]->size = { 40.0f,40.0f };

	boxData.push_back(new BoxData);//正方形
	boxData[boxData.size() - 1]->pos = { 780.0f,-130.0f };
	boxData[boxData.size() - 1]->size = { 40.0f,40.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 200.0f,-15.0f };
	boxData[boxData.size() - 1]->size = { 200.0f,30.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1000.0f,-200.0f };
	boxData[boxData.size() - 1]->size = { 260.0f,30.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1280.0f,-430.0f };
	boxData[boxData.size() - 1]->size = { 30.0f,260.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1200.0f,-450.0f };
	boxData[boxData.size() - 1]->size = { 160.0f,30.0f };
}

void Stage::StageSix()
{
	boxData.push_back(new BoxData);//床
	boxData[boxData.size() - 1]->pos = { 500.0f,600.0f };
	boxData[boxData.size() - 1]->size = { 900.0f,20.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1260.0f,380.0f };
	boxData[boxData.size() - 1]->size = { 30.0f,220.0f };

	boxData.push_back(new BoxData);//三角形
	boxData[boxData.size() - 1]->pos = { 1040.0f,480.0f };
	boxData[boxData.size() - 1]->size = { 200.0f,100.0f };
	boxData[boxData.size() - 1]->type = TRIANGLE;

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 960.0f,60.0f };
	boxData[boxData.size() - 1]->size = { 30.0f,160.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 760.0f,260.0f };
	boxData[boxData.size() - 1]->size = { 30.0f,160.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 0.0f,400.0f };
	boxData[boxData.size() - 1]->size = { 480.0f,30.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 0.0f,20.0f };
	boxData[boxData.size() - 1]->size = { 500.0f,30.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 470.0f,-40.0f };
	boxData[boxData.size() - 1]->size = { 30.0f,30.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1100.0f,-200.0f };
	boxData[boxData.size() - 1]->size = { 150.0f,30.0f };
	boxData[boxData.size() - 1]->minPos = { 600.0f,-190.0f };
	boxData[boxData.size() - 1]->maxPos = { 1000.0f,-190.0f };
	boxData[boxData.size() - 1]->type = MOVEBOX;

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 500.0f,-400.0f };
	boxData[boxData.size() - 1]->size = { 150.0f,30.0f };
	boxData[boxData.size() - 1]->minPos = { 300.0f,-190.0f };
	boxData[boxData.size() - 1]->maxPos = { 900.0f,-190.0f };
	boxData[boxData.size() - 1]->type = MOVEBOX;

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1250.0f,-300.0f };
	boxData[boxData.size() - 1]->size = { 30.0f,120.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1250.0f,-660.0f };
	boxData[boxData.size() - 1]->size = { 30.0f,120.0f };

	boxData.push_back(new BoxData);//長方形
	boxData[boxData.size() - 1]->pos = { 1190.0f,-560.0f };
	boxData[boxData.size() - 1]->size = { 120.0f,30.0f };
}
