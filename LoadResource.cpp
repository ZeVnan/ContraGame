#pragma once
#include "LoadResource.h"

void CreateBillAni(CTextures* &textures, CSprites* &sprites, CAnimations* &animations) {

	textures->Add(ID_TEX_BILL, TEXTURE_PATH_BILL);
	LPTEXTURE texBill = textures->Get(ID_TEX_BILL);
	//normal right
	sprites->Add(10001, 1, 30, 25, 65, texBill);
	sprites->Add(10002, 26, 30, 50, 65, texBill);
	//normal left
	sprites->Add(10003, sprites->Get(10001));
	sprites->Add(10004, sprites->Get(10002));
	//run right
	sprites->Add(10011, 2, 66, 23, 102, texBill);
	sprites->Add(10012, 24, 66, 41, 102, texBill);
	sprites->Add(10013, 42, 66, 61, 102, texBill);
	sprites->Add(10014, 62, 66, 83, 102, texBill);
	sprites->Add(10015, 84, 66, 101, 102, texBill);
	sprites->Add(10016, 102, 66, 122, 102, texBill);
	//run left
	sprites->Add(10021, sprites->Get(10011));
	sprites->Add(10022, sprites->Get(10012));
	sprites->Add(10023, sprites->Get(10013));
	sprites->Add(10024, sprites->Get(10014));
	sprites->Add(10025, sprites->Get(10015));
	sprites->Add(10026, sprites->Get(10016));
	//jump right
	sprites->Add(10031, 117, 44, 134, 65, texBill);
	sprites->Add(10032, 135, 44, 155, 65, texBill);
	sprites->Add(10033, 156, 44, 173, 65, texBill);
	sprites->Add(10034, 174, 44, 194, 65, texBill);
	//jump left
	sprites->Add(10035, sprites->Get(10031));
	sprites->Add(10036, sprites->Get(10032));
	sprites->Add(10037, sprites->Get(10033));
	sprites->Add(10038, sprites->Get(10034));
	//laydown right
	sprites->Add(10041, 83, 48, 116, 65, texBill);
	//laydown left
	sprites->Add(10042, sprites->Get(10041));
	//run shot up right
	sprites->Add(10051, 123, 66, 144, 102, texBill);
	sprites->Add(10052, 145, 66, 162, 102, texBill);
	sprites->Add(10053, 163, 66, 183, 102, texBill);
	//run shot up left
	sprites->Add(10054, sprites->Get(10051));
	sprites->Add(10055, sprites->Get(10052));
	sprites->Add(10056, sprites->Get(10053));
	//run shot down right
	sprites->Add(10061, 184, 66, 206, 102, texBill);
	sprites->Add(10062, 207, 66, 228, 102, texBill);
	sprites->Add(10063, 229, 66, 251, 102, texBill);
	//run shot down left
	sprites->Add(10064, sprites->Get(10061));
	sprites->Add(10065, sprites->Get(10062));
	sprites->Add(10066, sprites->Get(10063));
	//shot up right
	sprites->Add(10071, 51, 19, 66, 65, texBill);
	sprites->Add(10072, 67, 19, 82, 65, texBill);
	//shot up left
	sprites->Add(10073, sprites->Get(10071));
	sprites->Add(10074, sprites->Get(10072));
	//run shot right
	sprites->Add(10081, 155, 189, 181, 224, texBill);
	sprites->Add(10082, 184, 189, 208, 224, texBill);
	sprites->Add(10083, 210, 189, 236, 224, texBill);
	//run shot left
	sprites->Add(10084, sprites->Get(10081));
	sprites->Add(10085, sprites->Get(10082));
	sprites->Add(10086, sprites->Get(10083));

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
	animations->Add(BILL_ANI_SHOOT_UPRIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10054);
	ani->Add(10055);
	ani->Add(10056);
	animations->Add(BILL_ANI_SHOOT_UPLEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10061);
	ani->Add(10062);
	ani->Add(10063);
	animations->Add(BILL_ANI_SHOOT_DOWNRIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10064);
	ani->Add(10065);
	ani->Add(10066);
	animations->Add(BILL_ANI_SHOOT_DOWNLEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10071);
	ani->Add(10072);
	animations->Add(BILL_ANI_SHOOT_UP_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10073);
	ani->Add(10074);
	animations->Add(BILL_ANI_SHOOT_UP_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10081);
	ani->Add(10082);
	ani->Add(10083);
	animations->Add(BILL_ANI_SHOOT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10084);
	ani->Add(10085);
	ani->Add(10086);
	animations->Add(BILL_ANI_SHOOT_LEFT, ani);
}
void CreateBulletAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	textures->Add(ID_TEX_BULLET, TEXTURE_PATH_BULLET);
	LPTEXTURE texBullet = textures->Get(ID_TEX_BULLET);
	//id sprite 101xx
	//bill
	//normal bullet
	sprites->Add(10100, 58, 42, 60, 44, texBullet);
	//laser bullet
	sprites->Add(10101, 23, 39, 38, 44, texBullet);
	//flame bullet
	sprites->Add(10102, 41, 37, 48, 44, texBullet);
	//spread bullet 
	sprites->Add(10103, 61, 27, 66, 32, texBullet);
	//machine bullet
	sprites->Add(10104, 69, 28, 73, 32, texBullet);
	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(10100);
	animations->Add(BULLET_ANI_NORMAL, ani);

	ani = new CAnimation(100);
	ani->Add(10101);
	animations->Add(BULLET_ANI_LASER, ani);

	ani = new CAnimation(100);
	ani->Add(10102);
	animations->Add(BULLET_ANI_FLAME, ani);
	
	ani = new CAnimation(100);
	ani->Add(10103);
	animations->Add(BULLET_ANI_SPREAD, ani);
	
	ani = new CAnimation(100);
	ani->Add(10104);
	animations->Add(BULLET_ANI_MACHINE, ani);
}
void CreateSoldierAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	textures->Add(ID_TEX_SOLDIER, TEXTURE_PATH_SOLDIER);
	LPTEXTURE texSoldier = textures->Get(ID_TEX_SOLDIER);
	//sprite id 102xx
	//run left
	sprites->Add(10200, 90, 0, 106, 32, texSoldier);
	sprites->Add(10201, 72, 0, 88, 32, texSoldier);
	sprites->Add(10202, 54, 0, 70, 32, texSoldier);
	sprites->Add(10203, 36, 0, 52, 32, texSoldier);
	sprites->Add(10204, 18, 0, 34, 32, texSoldier);
	sprites->Add(10205, 0, 0, 16, 32, texSoldier);
	//run right
	sprites->Add(10210, sprites->Get(10200));
	sprites->Add(10211, sprites->Get(10201));
	sprites->Add(10212, sprites->Get(10202));
	sprites->Add(10213, sprites->Get(10203));
	sprites->Add(10214, sprites->Get(10204));
	sprites->Add(10215, sprites->Get(10205));
	//jump left
	sprites->Add(10220, 108, 0, 124, 32, texSoldier);
	//jump right
	sprites->Add(10221, sprites->Get(10220));
	//shoot left
	sprites->Add(10230, 126, 0, 150, 32, texSoldier);
	sprites->Add(10231, 152, 0, 176, 32, texSoldier);
	//shoot right
	sprites->Add(10232, sprites->Get(10230));
	sprites->Add(10233, sprites->Get(10231));
	//lay down left
	sprites->Add(10240, 178, 0, 210, 32, texSoldier);
	//lay down right
	sprites->Add(10241, sprites->Get(10240));
	//die left
	sprites->Add(10250, 212, 0, 227, 32, texSoldier);
	//die right
	sprites->Add(10251, sprites->Get(10250));

	LPANIMATION ani;
	//run left 
	ani = new CAnimation(100);
	ani->Add(10200);
	ani->Add(10201);
	ani->Add(10202);
	ani->Add(10203);
	ani->Add(10204);
	ani->Add(10205);
	animations->Add(SOLDIER_ANI_RUN_LEFT, ani);
	//run right
	ani = new CAnimation(100);
	ani->Add(10210);
	ani->Add(10211);
	ani->Add(10212);
	ani->Add(10213);
	ani->Add(10214);
	ani->Add(10215);
	animations->Add(SOLDIER_ANI_RUN_RIGHT, ani);
	//jump left
	ani = new CAnimation(100);
	ani->Add(10220);
	animations->Add(SOLDIER_ANI_JUMP_LEFT, ani);
	//jump right
	ani = new CAnimation(100);
	ani->Add(10221);
	animations->Add(SOLDIER_ANI_JUMP_RIGHT, ani);
	//shoot left
	ani = new CAnimation(100);
	ani->Add(10230);
	ani->Add(10231);
	animations->Add(SOLDIER_ANI_SHOOT_LEFT, ani);
	//shoot right
	ani = new CAnimation(100);
	ani->Add(10232);
	ani->Add(10233);
	animations->Add(SOLDIER_ANI_SHOOT_RIGHT, ani);
	//laydown left
	ani = new CAnimation(100);
	ani->Add(10240);
	animations->Add(SOLDIER_ANI_LAYDOWN_LEFT, ani);
	//laydown right
	ani = new CAnimation(100);
	ani->Add(10241);
	animations->Add(SOLDIER_ANI_LAYDOWN_RIGHT, ani);
	//die left
	ani = new CAnimation(100);
	ani->Add(10250);
	animations->Add(SOLDIER_ANI_DIE_LEFT, ani);
	//die right
	ani = new CAnimation(100);
	ani->Add(10251);
	animations->Add(SOLDIER_ANI_DIE_RIGHT, ani);
}