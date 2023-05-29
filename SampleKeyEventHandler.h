#pragma once

#include "KeyEventHandler.h"
enum gameScreen
{
	intro = 0,
	tutorial = 1,
	waiting1 = 2,
	stage1 = 3,
	waiting3 = 4,
	stage3 = 5,
	gameover = 6,
	credit = 7
};
enum screenOption
{
	option1 = 1,
	option2 = 2,
};

class CSampleKeyHandler: public CKeyEventHandler
{
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};
