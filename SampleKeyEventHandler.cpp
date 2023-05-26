#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Bill.h"
extern CBill* bill;
extern gameScreen gameControl ;
extern screenOption option;
void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	if (gameControl == stage1 || gameControl == stage3) {
		bill->KeyDown(KeyCode);
	}
	switch (KeyCode) {
	case DIK_RETURN:
		switch (gameControl)
		{
		case intro:
			if (option == option1) {
				gameControl = tutorial;
			}
			else {
				gameControl = credit;
			}
			break;
		case tutorial:
			gameControl = waiting1;
			break;
		case gameover:
			if (option == option1) {
				
			}
			else {
				gameControl = intro;
			}
			break;
		case credit:
			gameControl = intro;
			break;
		}
		break;
	case DIK_UP:
		if (gameControl == intro || gameControl == gameover) {
			if (option == option2)
				option = option1;
		}
		break;
	case DIK_DOWN:
		if (gameControl == intro || gameControl == gameover) {
			if (option == option1)
				option = option2;
		}
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