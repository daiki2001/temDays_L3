﻿#include "KeyInput.h"
#include <DxLib.h>

char KeyInput::keys[256] = {};
char KeyInput::oldkeys[256] = {};

void KeyInput::Update()
{
	for (int i = 0; i < 256; i++)
	{
		oldkeys[i] = keys[i];
	}
	GetHitKeyStateAll(keys);
}

bool KeyInput::IsKey(int KeyCode)
{
	return keys[KeyCode];
}

bool KeyInput::IsKeyTrigger(int KeyCode)
{
	return keys[KeyCode] && !oldkeys[KeyCode];
}

bool KeyInput::IsKeyReturn(int KeyCode)
{
	return !keys[KeyCode] && oldkeys[KeyCode];
}
