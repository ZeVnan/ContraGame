#pragma once

#include "KeyEventHandler.h"
enum gameScreen
{
	intro = 0,
	waiting1 = 1,
	stage1 = 2,
	waiting3 = 3,
	stage3 = 4,
	gameover = 5,
};
class CSampleKeyHandler: public CKeyEventHandler
{
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};
