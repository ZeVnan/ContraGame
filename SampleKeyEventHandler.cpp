#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Bill.h"
extern CBill* bill;
void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	bill->KeyDown(KeyCode);
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	bill->KeyUp(KeyCode);
}

void CSampleKeyHandler::KeyState(BYTE *states)
{	
	CGame* game = CGame::GetInstance();
	bill->KeyState(game);
}