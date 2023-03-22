#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"
#include "Bill.h"

//extern CMario* mario;
extern CBill* bill;

void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_X:
		//mario->SetState(MARIO_STATE_JUMP);
		bill->SetState(BILL_STATE_JUMP);
		break;
	case DIK_Z:
		bill->SetState(BILL_STATE_SHOT);
		break;
	}
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_X:
		//mario->SetState(MARIO_STATE_RELEASE_JUMP);
		bill->SetState(BILL_STATE_JUMP_RELEASE);
		break;
	case DIK_Z:
		bill->SetState(BILL_STATE_SHOT_RELEASE);
		break;
	case DIK_DOWN:
		//mario->SetState(MARIO_STATE_SIT_RELEASE);
		bill->SetState(BILL_STATE_DOWN_RELEASE);
		break;
	case DIK_UP:
		bill->SetState(BILL_STATE_UP_RELEASE);
		break;
	case DIK_RIGHT:
		bill->SetState(BILL_STATE_NORMAL);
		break;
	case DIK_LEFT:
		bill->SetState(BILL_STATE_NORMAL);
		break;
	}
	
}

void CSampleKeyHandler::KeyState(BYTE *states)
{
	CGame* game = CGame::GetInstance();
	BOOLEAN normal = true;
	if (game->IsKeyDown(DIK_DOWN))
	{
		bill->SetState(BILL_STATE_DOWN);
		normal = false;
	}
	if (game->IsKeyDown(DIK_UP)) {
		bill->SetState(BILL_STATE_UP);
		normal = false;
	}
	if (game->IsKeyDown(DIK_LEFT))
	{
		bill->SetState(BILL_STATE_RUN_LEFT);
		normal = false;
	}
	if (game->IsKeyDown(DIK_RIGHT))
	{
		bill->SetState(BILL_STATE_RUN_RIGHT);
		normal = false;
	}
	if (normal == true)
		bill->SetState(BILL_STATE_NORMAL);
}