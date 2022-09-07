#include <DxLib.h>
#include "General.h"
#include "./Input/KeyInput.h"
#include "./Input/Controller.h"
#include "Player.h"
#include "Goal.h"
#include"Stage.h"
#include"PushCollision.h"
#include"Rod.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "とりトリップ";

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(General::WIN_WIDTH, General::WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0xFF);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	Player player;
	Goal goal = Goal(General::WIN_WIDTH - 100, General::WIN_HEIGHT / 2);
	//ステージ
	Stage stage;
	stage.Init();
	//棒
	Rod rod;
	rod.Init();

	while (1)
	{
		//更新
		KeyInput::Update();
		Controller::Update();

		player.Update();

		rod.Update();

		bool IsHitWall = false;
		bool IsHitGround = false;
		for (int i = 0; i < stage.boxMax; i++)
		{
			player.SetPosition(PushCollision::PushPlayer2Box(player.GetPos(), player.GetSize(), player.GetOldPos(),
				stage.GetBoxPos(i), stage.GetBoxSize(i), IsHitWall, IsHitGround));
		}
		//プレイヤーと棒
		player.SetPosition(PushCollision::PushPlayer2Box(player.GetPos(), player.GetSize(), player.GetOldPos(),
			rod.GetPos(), rod.GetSize(), IsHitWall, IsHitGround));

		//壁にあたったら
		if (IsHitWall)
		{
			player.ChangeFlag();
		}
		//地面に接している
		if (IsHitGround)
		{
			player.ChangeBoundFlag();
		}

		goal.Updata(player.GetPos());

		// 画面外判定
		bool isIn = Collision::BoxCollision(player.GetPos(),
											Vec2(General::WIN_WIDTH / 2.0f, General::WIN_HEIGHT / 2.0f),
											Vec2(player.GetSize(), player.GetSize()),
											Vec2(General::WIN_WIDTH / 2.0f, General::WIN_HEIGHT / 2.0f));
		// リセット
		if (isIn == false || KeyInput::IsKey(KEY_INPUT_R))
		{
			General::AllReset(&player, &goal);
		}

		// 画面クリア
		ClearDrawScreen();

		//描画
		goal.Draw();
		player.Draw();
		stage.Draw();

		rod.Draw();

		if (goal.GetGoal())
		{
			DrawString(0, 0, "Goal", GetColor(0xFF, 0xFF, 0xFF));
		}
		
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1)
		{
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE)
		{
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	return 0;
}