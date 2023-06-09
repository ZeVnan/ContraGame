#include "LoadResource.h"

#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"Contra"
#define WINDOW_ICON_PATH L"Images\\Contra.ico"

#define BACKGROUND_COLOR D3DXCOLOR(0.0f/255, 0.0f/255, 0.0f/255, 0.0f)

gameScreen gameControl;
screenOption option;
int playingAt;
#define WAITING_TIME 3000
int timeLeft = WAITING_TIME;
int score = 0, highscore;

CBill* bill = NULL;
CSampleKeyHandler* keyHandler;

LPWORLD world = new CWorld(1000, 1000, 0);
LPWORLDPART worldpart = new CWorldPart();

vector<LPTILE> stage_tiles;

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
void ClearWorld() {

	world->ClearWorld();
}
void ClearDeletedObject() {
	world->ClearDeletedObjects();
}
void LoadResources() {
	CTextures* textures = CTextures::GetInstance();
	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	CreateBillAni(textures, sprites, animations);
	CreateBulletAni(textures, sprites, animations);
	CreateSoldierAni(textures, sprites, animations);
	CreateRiflemanAni(textures, sprites, animations);
	CreateCannonAni(textures, sprites, animations);
	CreateAircraftAni(textures, sprites, animations);
	CreateFalconAni(textures, sprites, animations);
	CreateScubaAni(textures, sprites, animations);
	CreateWTurretAni(textures, sprites, animations);
	CreateRockFallAni(textures, sprites, animations);
	CreateOtherAni(textures, sprites, animations);
	CreateBossAni(textures, sprites, animations);

	LoadScreenResources(textures, sprites);

	gameControl = intro;
	option = option1;
	ifstream ofs;
	ofs.open(HIGHSCORE_PATH);
	ofs >> highscore;
	ofs.close();
}
void LoadStage1() {
	world = new CWorld(6656, 6656, 1);
	//objects
	world->getObjectsListFromFile(STAGE1_PATH);
	bill = new CBill(100, 400, 1);
	world->getObjectList().push_back(bill);
	//tile
	CTextures* textures = CTextures::GetInstance();
	CSprites* sprites = CSprites::GetInstance();
	CreateStageTile(textures, sprites, stage_tiles, 1);
	world->setTileList(stage_tiles);
	//spatial partition
	worldpart = new CWorldPart(world);
	worldpart->Split(world);
	//camera set up
	CGame::GetInstance()->GetCamera() = new CCamera(world->getWidth(), 448, 1);
	CGame::GetInstance()->GetCamera()->Update(100, 400);
}
void LoadStage3() {
	world = new CWorld(4455, 4455, 3);
	//objects
	world->getObjectsListFromFile(STAGE3_PATH);
	bill = new CBill(85, 135, 3);//BILL
	world->getObjectList().push_back(bill);
	//tiles
	CTextures* textures = CTextures::GetInstance();
	CSprites* sprites = CSprites::GetInstance();
	CreateStageTile(textures, sprites, stage_tiles, 3);
	world->setTileList(stage_tiles);
	//spatial partition
	worldpart = new CWorldPart(world);
	worldpart->Split(world);
	//camera set up
	CGame::GetInstance()->GetCamera() = new CCamera(480, world->getHeight(), 3);
	CGame::GetInstance()->GetCamera()->Update(85, 135);
}

void LoadStage(int stage) {
	ClearWorld();
	switch (stage) {
	case 1:
		LoadStage1();
		break;
	case 3:
		LoadStage3();
		break;
	}
}

/*
	Update world status for this frame
	dt: time period between beginning of last frame and beginning of this frame
*/
void Update(DWORD dt)
{
	switch (gameControl) {
	case intro:

		break;
	case tutorial:

		break;
	case waiting1:
		if (score > highscore) {
			highscore = score;
			ofstream ofs;
			ofs.open(HIGHSCORE_PATH, std::ofstream::out | std::ofstream::trunc);
			ofs << highscore;
			ofs.close();
		}
		if (timeLeft > 0) {
			timeLeft -= dt;
		}
		else {
			gameControl = stage1;
			timeLeft = WAITING_TIME;
			LoadStage(1);
			playingAt = 1;
		}
		break;
	case stage1:
		world->Update(dt);
		world->ClearDeletedObjects();
		break;
	case waiting3:
		if (score > highscore) {
			highscore = score;
			ofstream ofs;
			ofs.open(HIGHSCORE_PATH, std::ofstream::out | std::ofstream::trunc);
			ofs << highscore;
			ofs.close();
		}
		if (timeLeft > 0) {
			timeLeft -= dt;
		}
		else {
			gameControl = stage3;
			timeLeft = WAITING_TIME;
			LoadStage(3);
			playingAt = 3;
		}
		break;
	case stage3:
		world->Update(dt);
		world->ClearDeletedObjects();
	case gameover:

		break;
	case credit:

		break;
	}
	//DebugOutTitle(L"score = %d, highscore = %d", score, highscore);
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
	int temp = highscore;
	vector<int> v;
	while (temp != 0) {
		v.push_back(temp % 10);
		temp /= 10;
	}
	switch (gameControl) {
	case intro:
		CGame::GetInstance()->GetCamera()->SetCamPos(0, 0);
		CSprites::GetInstance()->Get(30000)->Draw(0, 0);
		if (option == option1) {
			CSprites::GetInstance()->Get(30006)->Draw(0, -60);
		}
		else {
			CSprites::GetInstance()->Get(30006)->Draw(0, -85);
		}
		break;
	case tutorial:
		CGame::GetInstance()->GetCamera()->SetCamPos(0, 0);
		CSprites::GetInstance()->Get(30005)->Draw(0, 0);
		break;
	case waiting1:
		CGame::GetInstance()->GetCamera()->SetCamPos(0, 0);
		CSprites::GetInstance()->Get(30001)->Draw(0, 0);
		for (int i = (int)v.size()-1; i >=0 ; i--) {
			CSprites::GetInstance()->Get(v[i] + 30010)->Draw(100 - (float)i * 20, 90);
		}
		break;
	case stage1:
		world->DrawTile();
		world->Render();
		break;
	case waiting3:
		ClearWorld();
		CGame::GetInstance()->GetCamera()->SetCamPos(0, 0);
		CSprites::GetInstance()->Get(30002)->Draw(0, 0);
		for (int i = (int)v.size() - 1; i >= 0; i--) {
			CSprites::GetInstance()->Get(v[i] + 30010)->Draw(100 - (float)i * 20, 90);
		}
		break;
	case stage3:
		world->DrawTile();
		world->Render();
		break;
	case gameover:
		ClearWorld();
		CGame::GetInstance()->GetCamera()->SetCamPos(0, 0);
		CSprites::GetInstance()->Get(30003)->Draw(0, 0);
		if (option == option1) {
			CSprites::GetInstance()->Get(30006)->Draw(-50, -75);
		}
		else {
			CSprites::GetInstance()->Get(30006)->Draw(-50, -105);
		}
		break;
	case credit:
		ClearWorld();
		CGame::GetInstance()->GetCamera()->SetCamPos(0, 0);
		CSprites::GetInstance()->Get(30004)->Draw(0, 0);
		break;
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
			CGame::GetInstance()->ProcessKeyboard();
			Update((DWORD)dt);
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

	SetWindowPos(hWnd, 0, 0, 0, int(SCREEN_WIDTH * 1.2), int(SCREEN_HEIGHT * 1.2), SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);

	LoadResources();

	Run();

	return 0;
}