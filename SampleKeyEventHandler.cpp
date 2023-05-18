#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Bill.h"
extern CBill* bill;
extern gameScreen gameControl ;
void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	if (gameControl == stage1 || gameControl == stage3) {
		bill->KeyDown(KeyCode);
	}
	switch (KeyCode) {
	case DIK_RETURN:
		if (gameControl == intro) {
			gameControl = waiting1;
		}
		break;
	}
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	if (gameControl == stage1 || gameControl == stage3) {
		bill->KeyUp(KeyCode);
	}
}

void CSampleKeyHandler::KeyState(BYTE *states)
{
	if (gameControl == stage1 || gameControl == stage3) {
		CGame* game = CGame::GetInstance();
		bill->KeyState(game);
	}
}