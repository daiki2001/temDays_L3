#pragma once
#include"DxLib.h"

class Controller
{
private:
	Controller();	//static�Ŏg���N���X���ƒ�
	static XINPUT_STATE XInput;			//XBox�R���g���[���[�̓��͏��
	static XINPUT_STATE oldXInput;		//1�t���[���O��XBox�R���g���[���[�̓��͏��

public:
	/*���j���[�I���n*/
	//A�{�^���������ꂽ����Ԃ�
	static bool Decision_A()
	{
		return XInput.Buttons[XINPUT_BUTTON_A] == 1 && oldXInput.Buttons[XINPUT_BUTTON_A] == 0;
	}
	static bool Decision_B()
	{
		return XInput.Buttons[XINPUT_BUTTON_B] == 1 && oldXInput.Buttons[XINPUT_BUTTON_B] == 0;
	}
	/*
	*�E�ɐi�ރL�[�������ꂽ����Ԃ�
	*/
	static bool SelectRight()
	{
		return (XInput.ThumbLX > 18000 && oldXInput.ThumbLX < 18000);
	}

	/*
	*���ɐi�ރL�[�������ꂽ����Ԃ�
	*/
	static bool SelectLeft()
	{
		return  (XInput.ThumbLX < -18000 && oldXInput.ThumbLX > -18000);

	}
	/*
	*��ɐi�ރL�[�������ꂽ����Ԃ�
	*/
	static bool SelectUp()
	{
		return (XInput.ThumbLY > 18000 && oldXInput.ThumbLY < 18000) ;
	}

	/*
	*���ɐi�ރL�[�������ꂽ����Ԃ�
	*/
	static bool SelectDown()
	{
		return  (XInput.ThumbLY < -18000 && oldXInput.ThumbLY > -18000) ;

	}

	/*�ړ��n*/
	/*
	*�E�ɐi�ރL�[�������ꂽ����Ԃ�
	*/
	static bool Right()
	{
		return XInput.ThumbLX > 18000 ;
	}

	/*
	*���ɐi�ރL�[�������ꂽ����Ԃ�
	*/
	static bool Left()
	{
		return  XInput.ThumbLX < -18000 ;

	}

	/*
	*�W�����v����L�[�������ꂽ����Ԃ�
	*/
	static bool Jump()
	{
		return  XInput.LeftTrigger > 70 ;
	}

	/*
	*�e�����L�[�������ꂽ����Ԃ�
	*/
	static bool Shoot()
	{
		return  XInput.RightTrigger > 70 ;
	}


	/*����������*/
	/*
	*�E�������L�[�������ꂽ����Ԃ�
	*/
	static bool LookRight()
	{
		return XInput.ThumbRX > 18000/* || Input::isKey(KEY_INPUT_RIGHT) || Input::isKey(KEY_INPUT_D)*/;
	}

	/*
	*���������L�[�������ꂽ����Ԃ�
	*/
	static bool LookLeft()
	{
		return XInput.ThumbRX < -18000 /*|| Input::isKey(KEY_INPUT_LEFT) || Input::isKey(KEY_INPUT_A)*/;
	}

	/*
	*��������L�[�������ꂽ����Ԃ�
	*/
	static bool LookUp()
	{
		return XInput.ThumbRY > 18000 /*|| Input::isKey(KEY_INPUT_UP) || Input::isKey(KEY_INPUT_W)*/;
	}

	/*
	*���������L�[�������ꂽ����Ԃ�
	*/
	static bool LookDown()
	{
		return XInput.ThumbRY < -18000 /*|| Input::isKey(KEY_INPUT_DOWN) || Input::isKey(KEY_INPUT_S)*/;
	}


	/*�΂ߌn*/
	/*
	*�E��������L�[�������ꂽ����Ԃ�
	*/
	static bool LookTopRight()
	{
		return XInput.ThumbRX > 18000 && XInput.ThumbRY > 18000;
	}
	/*
	*�E���������L�[�������ꂽ����Ԃ�
	*/
	static bool LookLowerRight()
	{
		return XInput.ThumbRX > 18000 && XInput.ThumbRY < -18000;
	}

	/*
	*����������L�[�������ꂽ����Ԃ�
	*/
	static bool LookTopLeft()
	{
		return XInput.ThumbRX < -18000 && XInput.ThumbRY > 18000;
	}
	/*
	*�����������L�[�������ꂽ����Ԃ�
	*/
	static bool LookLowerLeft()
	{
		return XInput.ThumbRX < -18000 && XInput.ThumbRY < -18000;
	}




	//XBox�R���g���[���[�̎���
	static void Update()
	{
		oldXInput = XInput;		//1�t���[���O�̓��͂�ێ�
		GetJoypadXInputState(DX_INPUT_PAD1, &XInput);//���͂̍X�V
	}

	//XBox�̃L�[��������Ă��邩�m�F����֐�
	static int CheckBotton()
	{
		//return XInput.LeftTrigger;
		return XInput.ThumbRY;
	}

	//XBox�̃L�[��������Ă��邩�m�F����֐�
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