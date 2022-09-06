#include"Controller.h"
#include"DxLib.h"

XINPUT_STATE Controller::XInput;			//XBoxコントローラーの入力状態
XINPUT_STATE Controller::oldXInput;		//1フレーム前のXBoxコントローラーの入力状態