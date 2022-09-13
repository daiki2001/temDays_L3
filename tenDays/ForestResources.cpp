#include "ForestResources.h"
#include <DxLib.h>
#include "General.h"

ForestResources::ForestResources() :
	bigLeaf(-1),
	smallLeaf(-1),
	groundAndTree(-1),
	bgm(-1)
{
}

ForestResources::~ForestResources()
{
	Release();
}

void ForestResources::Init(int* background)
{
	DeleteGraph(*background);
	*background = LoadGraph("./Resources/forestback/forestback.png");
	Load();
}

void ForestResources::Update()
{
	BigLeafAnimation();
	SmallLeafAnimation();
}

void ForestResources::Draw()
{
	DrawGraph(static_cast<int>(bigLeafPos.x), static_cast<int>(bigLeafPos.y), bigLeaf, true);
	DrawGraph(static_cast<int>(smallLeafPos.x), static_cast<int>(smallLeafPos.y), smallLeaf, true);
	DrawGraph(0, 0, groundAndTree, true);
}

void ForestResources::Load()
{
	if (bigLeaf == -1)
	{
		bigLeaf = LoadGraph("./Resources/forestback/BigLeaf.png");
	}
	if (smallLeaf == -1)
	{
		smallLeaf = LoadGraph("./Resources/forestback/SmallLeaf.png");
	}
	if (groundAndTree == -1)
	{
		groundAndTree = LoadGraph("./Resources/forestback/ground_tree.png");
	}
	if (bgm == -1)
	{
		bgm = LoadSoundMem("./Resources/sound/BGM/1forest.mp3");
		ChangeVolumeSoundMem(0x80, bgm);
		PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);
	}
}

void ForestResources::Release()
{
	if (DeleteGraph(bigLeaf) == 0)
	{
		bigLeaf = -1;
	}
	if (DeleteGraph(smallLeaf) == 0)
	{
		smallLeaf = -1;
	}
	if (DeleteGraph(groundAndTree) == 0)
	{
		groundAndTree = -1;
	}
	if (DeleteSoundMem(groundAndTree) == 0)
	{
		bgm = -1;
	}
}

void ForestResources::BigLeafAnimation()
{
	static const int maxCount = 16;
	static int animationCount = 0;

	if ((General::Frame::GetFrame() % 6) == 0)
	{
		animationCount++;

		if (animationCount >= maxCount)
		{
			bigLeafPos.x = 740.0f;
			bigLeafPos.y = 404.0f;
			animationCount -= maxCount;
		}
		else
		{
			bigLeafPos.x -= 14.0f;
			bigLeafPos.y += 8.0f;
		}
	}
}

void ForestResources::SmallLeafAnimation()
{
	static const int maxCount = 16;
	static int animationCount = 0;

	if ((General::Frame::GetFrame() % 6) == 0)
	{
		animationCount++;

		if (animationCount >= maxCount)
		{
			smallLeafPos.x = 776.0f;
			smallLeafPos.y = 364.0f;
			animationCount -= maxCount;
		}
		else
		{
			if ((animationCount % 4) == 0)
			{
				smallLeafPos.x += 2.0f * animationCount;
			}
			else
			{
				smallLeafPos.x -= 2.0f * animationCount;
			}
			if ((animationCount % 2) == 0)
			{
				smallLeafPos.y += 14.0f;
			}
			else
			{
				smallLeafPos.y += 26.0f;
			}
		}
	}
}
