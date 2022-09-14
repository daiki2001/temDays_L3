#include "Evaluate.h"
#include "Vec.h"

Evaluate::Evaluate()
{}

Evaluate::~Evaluate()
{}

void Evaluate::Init(int stageNum)
{
	Load();

	SetEvaluate(stageNum);
}

void Evaluate::Update()
{
	end = std::chrono::system_clock::now();
	time = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0);

	starNum = 3;
	for (int i = 0; i < evaNumMax; i++)
	{
		if (static_cast<float>(time) / 1000.0f > stageEvaTime[i])
		{
			starNum--;
		}
	}

}

void Evaluate::PlayDraw()
{
	int ofsetX = 10, spaceX = 64;
	int Time = static_cast<int>(time) / 1000;
	int a = Time / 60;
	int b = static_cast<int>(Time) % 60;
	//‚PŒ…–Ú
	int one = static_cast<int>(b) % 10;
	//‚QŒ…–Ú
	int	two = static_cast<int>(b) % 100 / 10;
	////‚RŒ…–Ú
	int	three = a % 10;;
	////‚SŒ…–Ú
	int four = a % 100 / 10;
	DrawGraph(ofsetX + spaceX * 5, 10, numberGraph[one], TRUE);

	DrawGraph(ofsetX + spaceX * 4, 10, numberGraph[two], TRUE);

	DrawGraph(ofsetX + spaceX * 3, 10, colonGraph, TRUE);

	DrawGraph(ofsetX + spaceX * 2, 10, numberGraph[three], TRUE);

	DrawGraph(ofsetX + spaceX * 1, 10, numberGraph[four], TRUE);

	DrawExtendGraph(ofsetX + spaceX * 0, 10, ofsetX + spaceX * 0 + 64, 10 + 64, watchGraph, TRUE);
}

void Evaluate::GoalDraw()
{
	//‚P‚Â
	if (starNum == 1)
	{
		DrawGraph(0, 0, clearGraph[0], TRUE);
	}
	//‚Q‚Â
	else if (starNum == 2)
	{
		DrawGraph(0, 0, clearGraph[1], TRUE);
	}
	//‚R‚Â
	else if (starNum == 3)
	{
		DrawGraph(0, 0, clearGraph[2], TRUE);
	}
}


void Evaluate::Start()
{
	start = std::chrono::system_clock::now();
}

void Evaluate::SetEvaluate(int stageNum)
{
	switch (stageNum)
	{
	case 1:
		stageEvaTime[0] = 5.0f;
		stageEvaTime[1] = 15.0f;
		break;
	case 2:
		stageEvaTime[0] = 10.0f;
		stageEvaTime[1] = 20.0f;
		break;
	case 3:
		stageEvaTime[0] = 12.0f;
		stageEvaTime[1] = 20.0f;
		break;
	case 4:
		stageEvaTime[0] = 10.0f;
		stageEvaTime[1] = 18.0f;
		break;
	case 5:
		stageEvaTime[0] = 20.0f;
		stageEvaTime[1] = 40.0f;
		break;
	case 6:
		stageEvaTime[0] = 25.0f;
		stageEvaTime[1] = 55.0f;
		break;
	}
	Start();
}

void Evaluate::Load()
{
	if (clearGraph[0] == -1)
	{
		clearGraph[0] = LoadGraph("./Resources/evaluate/GOOD.png");
	}
	if (clearGraph[1] == -1)
	{
		clearGraph[1] = LoadGraph("./Resources/evaluate/GREAT.png");
	}
	if (clearGraph[2] == -1)
	{
		clearGraph[2] = LoadGraph("./Resources/evaluate/perfectt.png");
	}
	if (numberGraph[0] == -1)
	{
		LoadDivGraph("./Resources/evaluate/number.png", 10, 10, 1, 64, 64, numberGraph);
	}
	if (colonGraph == -1)
	{
		colonGraph = LoadGraph("./Resources/evaluate/colon.png");
	}
	if (watchGraph == -1)
	{
		watchGraph = LoadGraph("./Resources/evaluate/TIME.png");
	}
}
