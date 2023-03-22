/* =============================================================
	INTRODUCTION TO GAME PROGRAMMING SE102
	
	SAMPLE 03 - KEYBOARD AND OBJECT STATE

	This sample illustrates how to:

		1/ Process keyboard input
		2/ Control object state with keyboard events
================================================================ */
#include "LoadResource.h"

#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"Contra"
#define WINDOW_ICON_PATH L"mario.ico"

#define BACKGROUND_COLOR D3DXCOLOR(200.0f/255, 200.0f/255, 255.0f/255, 0.0f)

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240


CMario* mario = NULL;
CBill* bill = NULL;
vector<LPGAMEOBJECT> objects;
CSampleKeyHandler* keyHandler;

void LoadBill() {
	CTextures* textures = CTextures::GetInstance();
	textures->Add(ID_TEX_BILL, TEXTURE_PATH_BILL);

	CSprites* sprites = CSprites::GetInstance();
	LPTEXTURE texBill = textures->Get(ID_TEX_BILL);
	//normal right
	sprites->Add(10001, 1, 30, 25, 65, texBill);
	sprites->Add(10002, 26, 30, 50, 65, texBill);
	//normal left
	sprites->Add(10003, 506 - 25, 30, 506 - 1, 65, texBill);
	sprites->Add(10004, 506 - 50, 30, 506 - 26, 65, texBill);
	//run right
	sprites->Add(10011, 2, 66, 23, 102, texBill);
	sprites->Add(10012, 24, 66, 41, 102, texBill);
	sprites->Add(10013, 42, 66, 61, 102, texBill);
	sprites->Add(10014, 62, 66, 83, 102, texBill);
	sprites->Add(10015, 84, 66, 101, 102, texBill);
	sprites->Add(10016, 102, 66, 122, 102, texBill);
	//run left
	sprites->Add(10021, 506 - 23, 66, 506 - 2, 102, texBill);
	sprites->Add(10022, 506 - 41, 66, 506 - 24, 102, texBill);
	sprites->Add(10023, 506 - 61, 66, 506 - 42, 102, texBill);
	sprites->Add(10024, 506 - 83, 66, 506 - 62, 102, texBill);
	sprites->Add(10025, 506 - 101, 66, 506 - 84, 102, texBill);
	sprites->Add(10026, 506 - 122, 66, 506 - 102, 102, texBill);
	//jump right
	sprites->Add(10031, 117, 44, 134, 65, texBill);
	sprites->Add(10032, 135, 44, 155, 65, texBill);
	sprites->Add(10033, 156, 44, 173, 65, texBill);
	sprites->Add(10034, 174, 44, 194, 65, texBill);
	//jump left
	sprites->Add(10035, 506 - 134, 44, 506 - 117, 65, texBill);
	sprites->Add(10036, 506 - 155, 44, 506 - 135, 65, texBill);
	sprites->Add(10037, 506 - 173, 44, 506 - 156, 65, texBill);
	sprites->Add(10038, 506 - 194, 44, 506 - 174, 65, texBill);
	//laydown right
	sprites->Add(10041, 83, 48, 116, 65, texBill);
	//laydown left
	sprites->Add(10042, 506 - 116, 48, 506 - 83, 65, texBill);
	//run shot up right
	sprites->Add(10051, 123, 66, 144, 102, texBill);
	sprites->Add(10052, 145, 66, 162, 102, texBill);
	sprites->Add(10053, 163, 66, 183, 102, texBill);
	//run shot up left
	sprites->Add(10054, 506 - 144, 66, 506 - 123, 102, texBill);
	sprites->Add(10055, 506 - 162, 66, 506 - 145, 102, texBill);
	sprites->Add(10056, 506 - 183, 66, 506 - 163, 102, texBill);
	//run shot down right
	sprites->Add(10061, 184, 66, 206, 102, texBill);
	sprites->Add(10062, 207, 66, 228, 102, texBill);
	sprites->Add(10063, 229, 66, 251, 102, texBill);
	//run shot down left
	sprites->Add(10064, 506 - 206, 66, 506 - 184, 102, texBill);
	sprites->Add(10065, 506 - 228, 66, 506 - 207, 102, texBill);
	sprites->Add(10066, 506 - 251, 66, 506 - 229, 102, texBill);
	//shot up right
	sprites->Add(10071, 51, 19, 66, 65, texBill);
	sprites->Add(10072, 67, 19, 82, 65, texBill);
	//shot up left
	sprites->Add(10073, 506 - 66, 19, 506 - 51, 65, texBill);
	sprites->Add(10074, 506 - 82, 19, 506 - 67, 65, texBill);
	//run shot right
	sprites->Add(10081, 155, 189, 181, 224, texBill);
	sprites->Add(10082, 184, 189, 208, 224, texBill);
	sprites->Add(10083, 210, 189, 236, 224, texBill);
	//run shot left
	sprites->Add(10084, 506 - 181, 189, 506 - 155, 224, texBill);
	sprites->Add(10085, 506 - 208, 189, 506 - 184, 224, texBill);
	sprites->Add(10086, 506 - 236, 189, 506 - 210, 224, texBill);


	CAnimations* animations = CAnimations::GetInstance();
	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(10001);
	ani->Add(10002);
	animations->Add(BILL_ANI_NORMAL_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10003);
	ani->Add(10004);
	animations->Add(BILL_ANI_NORMAL_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10011);
	ani->Add(10012);
	ani->Add(10013);
	ani->Add(10014);
	ani->Add(10015);
	ani->Add(10016);
	animations->Add(BILL_ANI_RUN_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10021);
	ani->Add(10022);
	ani->Add(10023);
	ani->Add(10024);
	ani->Add(10025);
	ani->Add(10026);
	animations->Add(BILL_ANI_RUN_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10031);
	ani->Add(10032);
	ani->Add(10033);
	ani->Add(10034);
	animations->Add(BILL_ANI_JUMP_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10035);
	ani->Add(10036);
	ani->Add(10037);
	ani->Add(10038);
	animations->Add(BILL_ANI_JUMP_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10041);
	animations->Add(BILL_ANI_LAYDOWN_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10042);
	animations->Add(BILL_ANI_LAYDOWN_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10051);
	ani->Add(10052);
	ani->Add(10053);
	animations->Add(BILL_ANI_SHOT_UPRIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10054);
	ani->Add(10055);
	ani->Add(10056);
	animations->Add(BILL_ANI_SHOT_UPLEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10061);
	ani->Add(10062);
	ani->Add(10063);
	animations->Add(BILL_ANI_SHOT_DOWNRIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10064);
	ani->Add(10065);
	ani->Add(10066);
	animations->Add(BILL_ANI_SHOT_DOWNLEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10071);
	ani->Add(10072);
	animations->Add(BILL_ANI_SHOT_UP_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10073);
	ani->Add(10074);
	animations->Add(BILL_ANI_SHOT_UP_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10081);
	ani->Add(10082);
	ani->Add(10083);
	animations->Add(BILL_ANI_SHOT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10084);
	ani->Add(10085);
	ani->Add(10086);
	animations->Add(BILL_ANI_SHOT_LEFT, ani);

	bill = new CBill(BILL_START_X, BILL_START_Y);
	objects.push_back(bill);
}


LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

/*
	Update world status for this frame
	dt: time period between beginning of last frame and beginning of this frame
*/
void Update(DWORD dt)
{
	for (int i = 0; i < (int)objects.size(); i++)
	{
		objects[i]->Update(dt);
	}
}

void Render()
{
	CGame* g = CGame::GetInstance();

	ID3D10Device* pD3DDevice = g->GetDirect3DDevice();
	IDXGISwapChain* pSwapChain = g->GetSwapChain();
	ID3D10RenderTargetView* pRenderTargetView = g->GetRenderTargetView();
	ID3DX10Sprite* spriteHandler = g->GetSpriteHandler();

	pD3DDevice->ClearRenderTargetView(pRenderTargetView, BACKGROUND_COLOR);

	spriteHandler->Begin(D3DX10_SPRITE_SORT_TEXTURE);

	FLOAT NewBlendFactor[4] = { 0,0,0,0 };
	pD3DDevice->OMSetBlendState(g->GetAlphaBlending(), NewBlendFactor, 0xffffffff);

	for (int i = 0; i < (int)objects.size(); i++)
	{
		objects[i]->Render();
	}

	spriteHandler->End();
	pSwapChain->Present(0, 0);
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = (HICON)LoadImage(hInstance, WINDOW_ICON_PATH, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			MAIN_WINDOW_TITLE,
			WS_OVERLAPPEDWINDOW, // WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);

	if (!hWnd) 
	{
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

int Run()
{
	MSG msg;
	int done = 0;
	ULONGLONG frameStart = GetTickCount64();
	ULONGLONG tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		ULONGLONG now = GetTickCount64();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		ULONGLONG dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;
			Update((DWORD)dt);
			CGame::GetInstance()->ProcessKeyboard();
			Render();
		}
		else
			Sleep((DWORD)(tickPerFrame - dt));
	}

	return 1;
}

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
) {
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	SetDebugWindow(hWnd);

	CGame* game = CGame::GetInstance();
	game->Init(hWnd, hInstance);

	keyHandler = new CSampleKeyHandler();
	game->InitKeyboard(keyHandler);

	SetWindowPos(hWnd, 0, 0, 0, SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);

	LoadBill();

	Run();

	return 0;
}