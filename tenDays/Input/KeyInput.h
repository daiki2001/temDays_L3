#pragma once

class KeyInput
{
private: //メンバ変数
	static char keys[256];
	static char oldkeys[256];

private: //メンバ関数
	KeyInput() = default;
	~KeyInput() = default;

public:
	// 更新処理
	static void Update();
	// キーを押しているかどうかの判定
	static bool IsKey(int KeyCode);
	// キーを押した瞬間かどうかの判定
	static bool IsKeyTrigger(int KeyCode);
	// キーを離した瞬間かどうかの判定
	static bool IsKeyReturn(int KeyCode);
};
