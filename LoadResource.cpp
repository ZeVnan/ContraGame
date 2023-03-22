#include "LoadResource.h"


//void LoadBill() {
//	CTextures* textures = CTextures::GetInstance();
//	textures->Add(ID_TEX_BILL, TEXTURE_PATH_BILL);
//
//	CSprites* sprites = CSprites::GetInstance();
//	LPTEXTURE texBill = textures->Get(ID_TEX_BILL);
//	//normal right
//	sprites->Add(10001, 1, 30, 25, 65, texBill);
//	sprites->Add(10002, 26, 30, 50, 65, texBill);
//	//normal left
//	sprites->Add(10003, 506 - 25, 30, 506 - 1, 65, texBill);
//	sprites->Add(10004, 506 - 50, 30, 506 - 26, 65, texBill);
//	//run right
//	sprites->Add(10011, 2, 66, 23, 102, texBill);
//	sprites->Add(10012, 24, 66, 41, 102, texBill);
//	sprites->Add(10013, 42, 66, 61, 102, texBill);
//	sprites->Add(10014, 62, 66, 83, 102, texBill);
//	sprites->Add(10015, 84, 66, 101, 102, texBill);
//	sprites->Add(10016, 102, 66, 122, 102, texBill);
//	//run left
//	sprites->Add(10021, 506 - 23, 66, 506 - 2, 102, texBill);
//	sprites->Add(10022, 506 - 41, 66, 506 - 24, 102, texBill);
//	sprites->Add(10023, 506 - 61, 66, 506 - 42, 102, texBill);
//	sprites->Add(10024, 506 - 83, 66, 506 - 62, 102, texBill);
//	sprites->Add(10025, 506 - 101, 66, 506 - 84, 102, texBill);
//	sprites->Add(10026, 506 - 122, 66, 506 - 102, 102, texBill);
//	//jump right
//	sprites->Add(10031, 117, 44, 134, 65, texBill);
//	sprites->Add(10032, 135, 44, 155, 65, texBill);
//	sprites->Add(10033, 156, 44, 173, 65, texBill);
//	sprites->Add(10034, 174, 44, 194, 65, texBill);
//	//jump left
//	sprites->Add(10035, 506 - 134, 44, 506 - 117, 65, texBill);
//	sprites->Add(10036, 506 - 155, 44, 506 - 135, 65, texBill);
//	sprites->Add(10037, 506 - 173, 44, 506 - 156, 65, texBill);
//	sprites->Add(10038, 506 - 194, 44, 506 - 174, 65, texBill);
//	//laydown right
//	sprites->Add(10041, 83, 48, 116, 65, texBill);
//	//laydown left
//	sprites->Add(10042, 506 - 116, 48, 506 - 83, 65, texBill);
//
//	CAnimations* animations = CAnimations::GetInstance();
//	LPANIMATION ani;
//	ani = new CAnimation(100);
//	ani->Add(10001);
//	ani->Add(10002);
//	animations->Add(BILL_ANI_NORMAL_RIGHT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10003);
//	ani->Add(10004);
//	animations->Add(BILL_ANI_NORMAL_LEFT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10011);
//	ani->Add(10012);
//	ani->Add(10013);
//	ani->Add(10014);
//	ani->Add(10015);
//	ani->Add(10016);
//	animations->Add(BILL_ANI_RUN_RIGHT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10021);
//	ani->Add(10022);
//	ani->Add(10023);
//	ani->Add(10024);
//	ani->Add(10025);
//	ani->Add(10026);
//	animations->Add(BILL_ANI_RUN_LEFT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10031);
//	ani->Add(10032);
//	ani->Add(10033);
//	ani->Add(10034);
//	animations->Add(BILL_ANI_JUMP_RIGHT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10035);
//	ani->Add(10036);
//	ani->Add(10037);
//	ani->Add(10038);
//	animations->Add(BILL_ANI_JUMP_LEFT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10041);
//	animations->Add(BILL_ANI_LAYDOWN_RIGHT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10042);
//	animations->Add(BILL_ANI_LAYDOWN_LEFT, ani);
//
//	bill = new CBill(BILL_START_X, BILL_START_Y);
//	objects.push_back(bill);
//}

//void LoadMario() {
//	CTextures* textures = CTextures::GetInstance();
//
//	textures->Add(ID_TEX_MARIO, TEXTURE_PATH_MARIO);
//	textures->Add(ID_TEX_MISC, TEXTURE_PATH_MISC);
//
//
//	CSprites* sprites = CSprites::GetInstance();
//	CAnimations* animations = CAnimations::GetInstance();
//
//	LPTEXTURE texMario = textures->Get(ID_TEX_MARIO);
//
//	sprites->Add(10001, 246, 154, 260, 181, texMario);
//
//	sprites->Add(10002, 275, 154, 290, 181, texMario);
//	sprites->Add(10003, 304, 154, 321, 181, texMario);
//
//	sprites->Add(10011, 186, 154, 200, 181, texMario);
//
//	sprites->Add(10012, 155, 154, 170, 181, texMario);
//	sprites->Add(10013, 125, 154, 140, 181, texMario);
//
//	// RUNNING RIGHT 
//	sprites->Add(10021, 335, 154, 335 + 18, 154 +26, texMario);
//	sprites->Add(10022, 363, 154, 363 + 18, 154 + 26, texMario);
//	sprites->Add(10023, 393, 154, 393 + 18, 154 + 26, texMario);
//
//	// RUNNING LEFT
//	sprites->Add(10031, 92, 154, 92 + 18, 154 + 26, texMario);
//	sprites->Add(10032, 66, 154, 66 + 18, 154 + 26, texMario);
//	sprites->Add(10033, 35, 154, 35 + 18, 154 + 26, texMario);
//
//	// JUMP WALK RIGHT & LEFT 
//	sprites->Add(10041, 395, 275, 395 + 16, 275 + 25, texMario);
//	sprites->Add(10042, 35, 275, 35 + 16, 275 + 25, texMario);
//
//	// JUMP RUN RIGHT & LEFT 
//	sprites->Add(10043, 395, 195, 395 + 18, 195 + 25, texMario);
//	sprites->Add(10044, 33, 195, 33 + 18, 195 + 25, texMario);
//
//	// SIT RIGHT/LEFT
//	sprites->Add(10051, 426, 239, 426 + 14, 239 + 17, texMario);
//	sprites->Add(10052, 5, 239, 5 + 14, 239 + 17, texMario);
//
//	// BRACING RIGHT/LEFT
//	sprites->Add(10061, 425, 154, 425 + 15, 154 + 27, texMario);
//	sprites->Add(10062, 5, 154, 5 + 15, 154 + 27, texMario);
//	 
//
//
//	LPANIMATION ani;
//
//	ani = new CAnimation(100);	
//	ani->Add(10001);
//	animations->Add(ID_ANI_MARIO_IDLE_RIGHT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10011);
//	animations->Add(ID_ANI_MARIO_IDLE_LEFT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10001);
//	ani->Add(10002);
//	ani->Add(10003);
//	animations->Add(ID_ANI_MARIO_WALKING_RIGHT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10011);
//	ani->Add(10012);
//	ani->Add(10013);
//	animations->Add(ID_ANI_MARIO_WALKING_LEFT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10021);
//	ani->Add(10022);
//	ani->Add(10023);
//	animations->Add(ID_ANI_MARIO_RUNNING_RIGHT, ani);
//
//	ani = new CAnimation(50);	// Mario runs faster hence animation speed should be faster
//	ani->Add(10031);
//	ani->Add(10032);
//	ani->Add(10033);
//	animations->Add(ID_ANI_MARIO_RUNNING_LEFT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10041);
//	animations->Add(ID_ANI_MARIO_JUMP_WALK_RIGHT, ani);
//
//	ani = new CAnimation(100);	
//	ani->Add(10042);
//	animations->Add(ID_ANI_MARIO_JUMP_WALK_LEFT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10043);
//	animations->Add(ID_ANI_MARIO_JUMP_RUN_RIGHT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10044);
//	animations->Add(ID_ANI_MARIO_JUMP_RUN_LEFT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10051);
//	animations->Add(ID_ANI_MARIO_SIT_RIGHT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10052);
//	animations->Add(ID_ANI_MARIO_SIT_LEFT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10061);
//	animations->Add(ID_ANI_MARIO_BRACE_RIGHT, ani);
//
//	ani = new CAnimation(100);
//	ani->Add(10062);
//	animations->Add(ID_ANI_MARIO_BRACE_LEFT, ani);
//}

//void LoadBrick() {
//	// Brick objects 
//	CTextures* textures = CTextures::GetInstance();
//	LPTEXTURE texMisc = textures->Get(ID_TEX_MISC);
//
//	CSprites* sprites = CSprites::GetInstance();
//	sprites->Add(ID_SPRITE_BRICK, 372, 153, 372+15, 153+15, texMisc);
//
//	CAnimations* animations = CAnimations::GetInstance();
//	LPANIMATION ani;
//	ani = new CAnimation(100);
//	ani->Add(ID_SPRITE_BRICK);
//	animations->Add(ID_ANI_BRICK,ani);
//
//	for (int i=0;i<NUM_BRICKS;i++) 
//	{
//		CBrick* b = new CBrick(BRICK_X + i * BRICK_WIDTH, BRICK_Y);
//		objects.push_back(b);
//	}
//}