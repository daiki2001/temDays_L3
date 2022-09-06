#pragma once
#include"DxLib.h"

class Controller
{
private:
	Controller();	//staticで使うクラスだと提示
	static XINPUT_STATE XInput;			//XBoxコントローラーの入力状態
	static XINPUT_STATE oldXInput;		//1フレーム前のXBoxコントローラーの入力状態

public:
	/*メニュー選択系*/
	//Aボタンを押されたかを返す
	static bool Decision_A()
	{
		return XInput.Buttons[XINPUT_BUTTON_A] == 1 && oldXInput.Buttons[XINPUT_BUTTON_A] == 0;
	}
	static bool Decision_B()
	{
		return XInput.Buttons[XINPUT_BUTTON_B] == 1 && oldXInput.Buttons[XINPUT_BUTTON_B] == 0;
	}
	/*
	*右に進むキーが押されたかを返す
	*/
	static bool SelectRight()
	{
		return (XInput.ThumbLX > 18000 && oldXInput.ThumbLX < 18000);
	}

	/*
	*左に進むキーが押されたかを返す
	*/
	static bool SelectLeft()
	{
		return  (XInput.ThumbLX < -18000 && oldXInput.ThumbLX > -18000);

	}
	/*
	*上に進むキーが押されたかを返す
	*/
	static bool SelectUp()
	{
		return (XInput.ThumbLY > 18000 && oldXInput.ThumbLY < 18000) ;
	}

	/*
	*下に進むキーが押されたかを返す
	*/
	static bool SelectDown()
	{
		return  (XInput.ThumbLY < -18000 && oldXInput.ThumbLY > -18000) ;

	}

	/*移動系*/
	/*
	*右に進むキーが押されたかを返す
	*/
	static bool Right()
	{
		return XInput.ThumbLX > 18000 ;
	}

	/*
	*左に進むキーが押されたかを返す
	*/
	static bool Left()
	{
		return  XInput.ThumbLX < -18000 ;

	}

	/*
	*ジャンプするキーが押されたかを返す
	*/
	static bool Jump()
	{
		return  XInput.LeftTrigger > 70 ;
	}

	/*
	*弾を撃つキーが押されたかを返す
	*/
	static bool Shoot()
	{
		return  XInput.RightTrigger > 70 ;
	}


	/*方向を向く*/
	/*
	*右を向くキーが押されたかを返す
	*/
	static bool LookRight()
	{
		return XInput.ThumbRX > 18000/* || Input::isKey(KEY_INPUT_RIGHT) || Input::isKey(KEY_INPUT_D)*/;
	}

	/*
	*左を向くキーが押されたかを返す
	*/
	static bool LookLeft()
	{
		return XInput.ThumbRX < -18000 /*|| Input::isKey(KEY_INPUT_LEFT) || Input::isKey(KEY_INPUT_A)*/;
	}

	/*
	*上を向くキーが押されたかを返す
	*/
	static bool LookUp()
	{
		return XInput.ThumbRY > 18000 /*|| Input::isKey(KEY_INPUT_UP) || Input::isKey(KEY_INPUT_W)*/;
	}

	/*
	*下を向くキーが押されたかを返す
	*/
	static bool LookDown()
	{
		return XInput.ThumbRY < -18000 /*|| Input::isKey(KEY_INPUT_DOWN) || Input::isKey(KEY_INPUT_S)*/;
	}


	/*斜め系*/
	/*
	*右上を向くキーが押されたかを返す
	*/
	static bool LookTopRight()
	{
		return XInput.ThumbRX > 18000 && XInput.ThumbRY > 18000;
	}
	/*
	*右下を向くキーが押されたかを返す
	*/
	static bool LookLowerRight()
	{
		return XInput.ThumbRX > 18000 && XInput.ThumbRY < -18000;
	}

	/*
	*左上を向くキーが押されたかを返す
	*/
	static bool LookTopLeft()
	{
		return XInput.ThumbRX < -18000 && XInput.ThumbRY > 18000;
	}
	/*
	*左下を向くキーが押されたかを返す
	*/
	static bool LookLowerLeft()
	{
		return XInput.ThumbRX < -18000 && XInput.ThumbRY < -18000;
	}




	//XBoxコントローラーの試し
	static void Update()
	{
		oldXInput = XInput;		//1フレーム前の入力を保持
		GetJoypadXInputState(DX_INPUT_PAD1, &XInput);//入力の更新
	}

	//XBoxのキーが押されているか確認する関数
	static int CheckBotton()
	{
		//return XInput.LeftTrigger;
		return XInput.ThumbRY;
	}

	//XBoxのキーが押されているか確認する関数
	static int CheckBottonX()
	{
		//return XInput.LeftTrigger;
		return XInput.ThumbRX;
	}

	static bool JpyPad()
	{
		//if (XInput.Buttons[XINPUT_BUTTON_DPAD_UP])
		if (XInput.ThumbRY)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

};