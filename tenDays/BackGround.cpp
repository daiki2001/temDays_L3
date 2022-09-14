#include "BackGround.h"
#include <DxLib.h>
#include"General.h"
BackGround::BackGround()
{
}

BackGround::~BackGround()
{
	Release();
}

void BackGround::Load(const int& stageNum)
{
	if (stageNum == 4)
	{
		if (ekihoka[0] == -1)
		{
			ekihoka[0] = LoadGraph("./Resources/station/hoka/ekihoka1.png");
		}
		if (ekihoka[1] == -1)
		{
			ekihoka[1] = LoadGraph("./Resources/station/hoka/ekihoka2.png");
		}
		if (ekihoka[2] == -1)
		{
			ekihoka[2] = LoadGraph("./Resources/station/hoka/ekihoka3.png");
		}
		if (ekihoka[3] == -1)
		{
			ekihoka[3] = LoadGraph("./Resources/station/hoka/ekihoka4.png");
		}
		if (ekihoka[4] == -1)
		{
			ekihoka[4] = LoadGraph("./Resources/station/hoka/ekihoka5.png");
		}

		if (ekilight[0] == -1)
		{
			ekilight[0] = LoadGraph("./Resources/station/light/ekitrain1.png");
		}
		if (ekilight[1] == -1)
		{
			ekilight[1] = LoadGraph("./Resources/station/light/ekitrain2.png");
		}
		if (ekilight[2] == -1)
		{
			ekilight[2] = LoadGraph("./Resources/station/light/ekitrain3.png");
		}
		if (ekilight[3] == -1)
		{
			ekilight[3] = LoadGraph("./Resources/station/light/ekitrain4.png");
		}
		if (ekilight[4] == -1)
		{
			ekilight[4] = LoadGraph("./Resources/station/light/ekitrain5.png");
		}

		if (train == -1)
		{
			train = LoadGraph("./Resources/station/ekitrain.png");
		}

		if (ekiBgm == -1)
		{
			ekiBgm = LoadSoundMem("./Resources/sound/BGM/2station.mp3");
			ChangeVolumeSoundMem(0x80, ekiBgm);
			PlaySoundMem(ekiBgm, DX_PLAYTYPE_LOOP);
		}
	}
	else if (stageNum == 5)
	{
		huji[0] = LoadGraph("./Resources/fujiback/fuji1.png");
		huji[1] = LoadGraph("./Resources/fujiback/fuji2.png");
		huji[2] = LoadGraph("./Resources/fujiback/fuji3.png");
		huji[3] = LoadGraph("./Resources/fujiback/fuji4.png");
		huji[4] = LoadGraph("./Resources/fujiback/fuji5.png");
		huji[5] = LoadGraph("./Resources/fujiback/fuji6.png");
		huji[6] = LoadGraph("./Resources/fujiback/fuji7.png");
		huji[7] = LoadGraph("./Resources/fujiback/fuji8.png");
		huji[8] = LoadGraph("./Resources/fujiback/fuji9.png");
		huji[9] = LoadGraph("./Resources/fujiback/fuji10.png");
		huji[10] = LoadGraph("./Resources/fujiback/fuji11.png");
		huji[11] = LoadGraph("./Resources/fujiback/fuji12.png");
		huji[12] = LoadGraph("./Resources/fujiback/fuji13.png");
		huji[13] = LoadGraph("./Resources/fujiback/fuji14.png");
		huji[14] = LoadGraph("./Resources/fujiback/fuji15.png");
		huji[15] = LoadGraph("./Resources/fujiback/fuji16.png");
		huji[16] = LoadGraph("./Resources/fujiback/fuji17.png");
		huji[17] = LoadGraph("./Resources/fujiback/fuji18.png");
		huji[18] = LoadGraph("./Resources/fujiback/fuji19.png");
		huji[19] = LoadGraph("./Resources/fujiback/fuji20.png");
		huji[20] = LoadGraph("./Resources/fujiback/fuji21.png");

		if (fujiBgm == -1)
		{
			fujiBgm = LoadSoundMem("./Resources/sound/BGM/3fujimountain.mp3");
			ChangeVolumeSoundMem(0x80, fujiBgm);
			PlaySoundMem(fujiBgm, DX_PLAYTYPE_LOOP);
		}
	}
	else if (stageNum == 6)
	{
		moonLoop = LoadGraph("./Resources/moon/unknown.png");
		monnsky = LoadGraph("./Resources/moon/moonsky.png");
		monnGround = LoadGraph("./Resources/moon/moon.ground.png");

		if (moonBgm == -1)
		{
			moonBgm = LoadSoundMem("./Resources/sound/BGM/4universe.mp3");
			ChangeVolumeSoundMem(0x80, moonBgm);
			PlaySoundMem(moonBgm, DX_PLAYTYPE_LOOP);
		}
	}
}

void BackGround::Update(int stageNum)
{
	switch (stageNum)
	{
	case 4:
		StationAnimation();
		break;
	case 5:
		SakuraAnimation();
		break;
	case 6:

		break;
	default:
		break;
	}
}

void BackGround::Draw(int stageNum, Vec2 scroll)
{
	switch (stageNum)
	{
	case 4:
		DrawGraph(0, -720 - scroll.y, ekihoka[stationNum], TRUE);
		DrawGraph(trainPos, -720 - scroll.y, train, TRUE);
		DrawGraph(0, -720 - scroll.y, ekilight[stationNum], TRUE);
		break;
	case 5:
		DrawGraph(0, -720 - scroll.y, huji[sakuraNum], TRUE);
		break;
	case 6:
		//DrawGraph(0, -720 - scroll.y, monnsky, TRUE);
		DrawGraph(0, -720 - scroll.y, moonLoop, TRUE);
		//DrawGraph(0, -720 - scroll.y, monnGround, TRUE);
		break;
	default:
		break;
	}
}

void BackGround::Release()
{
	if (DeleteSoundMem(ekiBgm) == 0)
	{
		ekiBgm = -1;
	}
	if (DeleteSoundMem(fujiBgm) == 0)
	{
		fujiBgm = -1;
	}
	if (DeleteSoundMem(moonBgm) == 0)
	{
		moonBgm = -1;
	}
}

void BackGround::StationAnimation()
{
	if ((General::Frame::GetFrame() % 6) == 0)
	{
		stationNum++;
		if (stationNum > 4)
		{
			stationNum = 0;
		}
		trainPos += 10.0f;
		if (trainPos >= 1400.0f)
		{
			trainPos = -300.0f;
		}

	}
}

void BackGround::SakuraAnimation()
{
	if ((General::Frame::GetFrame() % 50) == 0)
	{
		sakuraNum++;
		if (sakuraNum > 20)
		{
			sakuraNum = 0;
		}
	}
}
