#pragma once
#include "LoadResource.h"

void CreateBillAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	//10xxx
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
	//swimming begin 
	sprites->Add(10090, 94, 115, 111, 131, texBill);
	//diving
	sprites->Add(10100, 112, 123, 129, 131, texBill);
	//swimming right
	sprites->Add(10110, 130, 115, 147, 131, texBill);
	//swimming left
	sprites->Add(10111, sprites->Get(10110));
	//swimming shot right
	sprites->Add(10120, 191, 113, 217, 131, texBill);
	//swimming shot left
	sprites->Add(10121, sprites->Get(10120));
	//swimming shot up right
	sprites->Add(10130, 169, 103, 187, 131, texBill);
	//swimming shot up left
	sprites->Add(10131, sprites->Get(10130));
	//swimming shot upright
	sprites->Add(10140, 148, 113, 168, 131, texBill);
	//swimming shot upleft
	sprites->Add(10141, sprites->Get(10140));
	//dying right
	sprites->Add(10150, 2, 107, 18, 131, texBill);
	sprites->Add(10151, 19, 112, 42, 131, texBill);
	sprites->Add(10152, 43, 107, 59, 131, texBill);
	sprites->Add(10153, 60, 120, 93, 131, texBill);
	//dying left
	sprites->Add(10154, sprites->Get(10150));
	sprites->Add(10155, sprites->Get(10151));
	sprites->Add(10156, sprites->Get(10152));
	sprites->Add(10157, sprites->Get(10153));

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

	ani = new CAnimation(100);
	ani->Add(10090);
	animations->Add(BILL_ANI_SWIMMING_BEGIN, ani);

	ani = new CAnimation(100);
	ani->Add(10100);
	animations->Add(BILL_ANI_DIVING, ani);

	ani = new CAnimation(100);
	ani->Add(10110);
	animations->Add(BILL_ANI_SWIMMING_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10111);
	animations->Add(BILL_ANI_SWIMMING_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10120);
	animations->Add(BILL_ANI_SWIMMING_SHOOT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10121);
	animations->Add(BILL_ANI_SWIMMING_SHOOT_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10130);
	animations->Add(BILL_ANI_SWIMMING_SHOOT_UP_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10131);
	animations->Add(BILL_ANI_SWIMMING_SHOOT_UP_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10140);
	animations->Add(BILL_ANI_SWIMMING_SHOOT_UPRIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10141);
	animations->Add(BILL_ANI_SWIMMING_SHOOT_UPLEFT, ani);

	ani = new CAnimation(200);
	ani->Add(10150);
	ani->Add(10151);
	ani->Add(10152);
	ani->Add(10153);
	animations->Add(BILL_ANI_DYING_RIGHT, ani);

	ani = new CAnimation(200);
	ani->Add(10154);
	ani->Add(10155);
	ani->Add(10156);
	ani->Add(10157);
	animations->Add(BILL_ANI_DYING_LEFT, ani);
}
void CreateBulletAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	textures->Add(ID_TEX_BULLET, TEXTURE_PATH_BULLET);
	LPTEXTURE texBullet = textures->Get(ID_TEX_BULLET);
	//id sprite 11xxx
	//bill
	//normal bullet
	sprites->Add(11000, 58, 42, 60, 44, texBullet);
	//normal bullet (bill)
	sprites->Add(11011, 64, 42, 66, 44, texBullet);
	//laser bullet
	sprites->Add(11001, 23, 39, 38, 44, texBullet);
	sprites->Add(11005, sprites->Get(11001), 45);
	sprites->Add(11006, sprites->Get(11001), 135);
	sprites->Add(11007, sprites->Get(11001), 225);
	sprites->Add(11008, sprites->Get(11001), 315);
	sprites->Add(11009, sprites->Get(11001), 90);
	sprites->Add(11010, sprites->Get(11001), 270);
	//flame bullet
	sprites->Add(11002, 41, 37, 48, 44, texBullet);
	//spread bullet 
	sprites->Add(11003, 61, 27, 66, 32, texBullet);
	//machine bullet
	sprites->Add(11004, 69, 28, 73, 32, texBullet);
	//boss 1 bullet 
	sprites->Add(11012, 50, 25, 57, 32, texBullet);
	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(11000);
	animations->Add(BULLET_ANI_NORMAL, ani);

	ani = new CAnimation(100);
	ani->Add(11011);
	animations->Add(BULLET_ANI_NORMAL_BILL, ani);

	ani = new CAnimation(100);
	ani->Add(11001);
	animations->Add(BULLET_ANI_LASER, ani);
	ani = new CAnimation(100);
	ani->Add(11005);
	animations->Add(BULLET_ANI_LASER_45, ani);
	ani = new CAnimation(100);
	ani->Add(11006);
	animations->Add(BULLET_ANI_LASER_135, ani);
	ani = new CAnimation(100);
	ani->Add(11007);
	animations->Add(BULLET_ANI_LASER_225, ani);
	ani = new CAnimation(100);
	ani->Add(11008);
	animations->Add(BULLET_ANI_LASER_315, ani);
	ani = new CAnimation(100);
	ani->Add(11009);
	animations->Add(BULLET_ANI_LASER_90, ani);

	ani = new CAnimation(100);
	ani->Add(11002);
	animations->Add(BULLET_ANI_FLAME, ani);

	ani = new CAnimation(100);
	ani->Add(11003);
	animations->Add(BULLET_ANI_SPREAD, ani);

	ani = new CAnimation(100);
	ani->Add(11004);
	animations->Add(BULLET_ANI_MACHINE, ani);

	ani = new CAnimation(100);
	ani->Add(11012);
	animations->Add(BULLET_ANI_BOSS1, ani);
}
void CreateSoldierAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	textures->Add(ID_TEX_SOLDIER, TEXTURE_PATH_SOLDIER);
	LPTEXTURE texSoldier = textures->Get(ID_TEX_SOLDIER);
	//sprite id 12xxx
	//run left
	sprites->Add(12000, 90, 0, 106, 32, texSoldier);
	sprites->Add(12001, 72, 0, 88, 32, texSoldier);
	sprites->Add(12002, 54, 0, 70, 32, texSoldier);
	sprites->Add(12003, 36, 0, 52, 32, texSoldier);
	sprites->Add(12004, 18, 0, 34, 32, texSoldier);
	sprites->Add(12005, 0, 0, 16, 32, texSoldier);
	//run right
	sprites->Add(12010, sprites->Get(12000));
	sprites->Add(12011, sprites->Get(12001));
	sprites->Add(12012, sprites->Get(12002));
	sprites->Add(12013, sprites->Get(12003));
	sprites->Add(12014, sprites->Get(12004));
	sprites->Add(12015, sprites->Get(12005));
	//jump left
	sprites->Add(12020, 108, 0, 124, 32, texSoldier);
	//jump right
	sprites->Add(12021, sprites->Get(12020));
	//shoot left
	sprites->Add(12030, 126, 0, 150, 32, texSoldier);
	sprites->Add(12031, 152, 0, 176, 32, texSoldier);
	//shoot right
	sprites->Add(12032, sprites->Get(12030));
	sprites->Add(12033, sprites->Get(12031));
	//lay down left
	sprites->Add(12040, 178, 0, 210, 32, texSoldier);
	//lay down right
	sprites->Add(12041, sprites->Get(12040));
	//die left
	sprites->Add(12050, 212, 0, 227, 32, texSoldier);
	//die right
	sprites->Add(12051, sprites->Get(12050));

	LPANIMATION ani;
	//run left 
	ani = new CAnimation(100);
	ani->Add(12000);
	ani->Add(12001);
	ani->Add(12002);
	ani->Add(12003);
	ani->Add(12004);
	ani->Add(12005);
	animations->Add(SOLDIER_ANI_RUN_LEFT, ani);
	//run right
	ani = new CAnimation(100);
	ani->Add(12010);
	ani->Add(12011);
	ani->Add(12012);
	ani->Add(12013);
	ani->Add(12014);
	ani->Add(12015);
	animations->Add(SOLDIER_ANI_RUN_RIGHT, ani);
	//jump left
	ani = new CAnimation(100);
	ani->Add(12020);
	animations->Add(SOLDIER_ANI_JUMP_LEFT, ani);
	//jump right
	ani = new CAnimation(100);
	ani->Add(12021);
	animations->Add(SOLDIER_ANI_JUMP_RIGHT, ani);
	//shoot left
	ani = new CAnimation(100);
	ani->Add(12030);
	ani->Add(12031);
	animations->Add(SOLDIER_ANI_SHOOT_LEFT, ani);
	//shoot right
	ani = new CAnimation(100);
	ani->Add(12032);
	ani->Add(12033);
	animations->Add(SOLDIER_ANI_SHOOT_RIGHT, ani);
	//laydown left
	ani = new CAnimation(100);
	ani->Add(12040);
	animations->Add(SOLDIER_ANI_LAYDOWN_LEFT, ani);
	//laydown right
	ani = new CAnimation(100);
	ani->Add(12041);
	animations->Add(SOLDIER_ANI_LAYDOWN_RIGHT, ani);
	//die left
	ani = new CAnimation(100);
	ani->Add(12050);
	animations->Add(SOLDIER_ANI_DIE_LEFT, ani);
	//die right
	ani = new CAnimation(100);
	ani->Add(12051);
	animations->Add(SOLDIER_ANI_DIE_RIGHT, ani);
}
void CreateAircraftAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	textures->Add(ID_TEX_AIRCRAFT, TEXTURE_PATH_AIRCRAFT);
	LPTEXTURE aircraftTex = textures->Get(ID_TEX_AIRCRAFT);
	//aircraft 13xxx

	//normal
	sprites->Add(13010, 2, 0, 27, 15, aircraftTex);
	//b_ammo
	sprites->Add(13011, 28, 0, 53, 15, aircraftTex);
	//f_ammo
	sprites->Add(13012, 54, 0, 79, 15, aircraftTex);
	//l_ammo
	sprites->Add(13013, 80, 0, 105, 15, aircraftTex);
	//m_ammo
	sprites->Add(13014, 106, 0, 131, 15, aircraftTex);
	//r_ammo
	sprites->Add(13015, 132, 0, 157, 15, aircraftTex);
	//s_ammo
	sprites->Add(13016, 158, 0, 183, 15, aircraftTex);
	//invul
	sprites->Add(13017, 186, 0, 212, 15, aircraftTex);
	sprites->Add(13018, 217, 0, 242, 15, aircraftTex);
	sprites->Add(13019, 247, 0, 272, 15, aircraftTex);

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(13010);
	animations->Add(AIRCRAFT_ANI_NORMAL, ani);

	ani = new CAnimation(100);
	ani->Add(13011);
	animations->Add(AIRCRAFT_ANI_bAMMO, ani);
	ani = new CAnimation(100);
	ani->Add(13012);
	animations->Add(AIRCRAFT_ANI_fAMMO, ani);
	ani = new CAnimation(100);
	ani->Add(13013);
	animations->Add(AIRCRAFT_ANI_lAMMO, ani);
	ani = new CAnimation(100);
	ani->Add(13014);
	animations->Add(AIRCRAFT_ANI_mAMMO, ani);
	ani = new CAnimation(100);
	ani->Add(13015);
	animations->Add(AIRCRAFT_ANI_rAMMO, ani);
	ani = new CAnimation(100);
	ani->Add(13016);
	animations->Add(AIRCRAFT_ANI_sAMMO, ani);

	ani = new CAnimation(100);
	ani->Add(13017);
	ani->Add(13018);
	ani->Add(13019);
	animations->Add(AIRCRAFT_ANI_INVUL, ani);
}
void CreateCannonAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	textures->Add(ID_TEX_CANNON, TEXTURE_PATH_CANNON);
	LPTEXTURE cannonTex = textures->Get(ID_TEX_CANNON);
	//cannon 14xxx

	//left
	sprites->Add(14000, 66, 66, 98, 98, cannonTex);
	sprites->Add(14001, 66, 34, 98, 66, cannonTex);
	sprites->Add(14002, 66, 2, 98, 34, cannonTex);
	//left - 60
	sprites->Add(14003, 98, 66, 130, 98, cannonTex);
	sprites->Add(14004, 98, 34, 130, 66, cannonTex);
	sprites->Add(14005, 98, 2, 130, 34, cannonTex);
	//left - 30
	sprites->Add(14006, 130, 66, 162, 98, cannonTex);
	sprites->Add(14007, 130, 34, 162, 66, cannonTex);
	sprites->Add(14008, 130, 2, 162, 34, cannonTex);
	//appear
	sprites->Add(14010, 2, 66, 34, 98, cannonTex);
	sprites->Add(14011, 2, 34, 34, 66, cannonTex);
	sprites->Add(14012, 2, 2, 34, 34, cannonTex);
	sprites->Add(14013, 34, 66, 66, 98, cannonTex);
	sprites->Add(14014, 34, 34, 66, 66, cannonTex);
	sprites->Add(14015, 34, 2, 66, 34, cannonTex);

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(14000);
	ani->Add(14001);
	ani->Add(14002);
	animations->Add(CANNON_ANI_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(14003);
	ani->Add(14004);
	ani->Add(14005);
	animations->Add(CANNON_ANI_LEFT_60, ani);

	ani = new CAnimation(100);
	ani->Add(14006);
	ani->Add(14007);
	ani->Add(14008);
	animations->Add(CANNON_ANI_LEFT_30, ani);

	ani = new CAnimation(100);
	ani->Add(14010);
	ani->Add(14011);
	ani->Add(14012);
	ani->Add(14013);
	ani->Add(14014);
	ani->Add(14015);
	animations->Add(CANNON_ANI_APPEAR, ani);
}
void CreateRiflemanAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	textures->Add(ID_TEX_RIFLEMAN, TEXTURE_PATH_RIFLEMAN);
	LPTEXTURE riflemanTex = textures->Get(ID_TEX_RIFLEMAN);
	//rifleman 15xxx
	//normal-left
	sprites->Add(15000, 0, 0, 23, 38, riflemanTex);
	//normal-right
	sprites->Add(15001, sprites->Get(15000));
	//shoot-left
	sprites->Add(15010, 26, 0, 49, 38, riflemanTex);
	//shoot-right
	sprites->Add(15011, sprites->Get(15010));
	//aim_up-left
	sprites->Add(15020, 52, 0, 69, 38, riflemanTex);
	//aim_up-right
	sprites->Add(15021, sprites->Get(15020));
	//shoot_up-left
	sprites->Add(15030, 72, 0, 89, 38, riflemanTex);
	//shoot_up-right
	sprites->Add(15031, sprites->Get(15030));
	//aim_down-left
	sprites->Add(15040, 92, 0, 115, 38, riflemanTex);
	//aim_down-right
	sprites->Add(15041, sprites->Get(15040));
	//hide-left
	sprites->Add(15050, 118, 0, 125, 38, riflemanTex);
	//hide-right
	sprites->Add(15051, sprites->Get(15050));
	//expose-left
	sprites->Add(15060, 128, 0, 150, 38, riflemanTex);
	sprites->Add(15061, 153, 0, 176, 38, riflemanTex);
	//expose-right
	sprites->Add(15062, sprites->Get(15060));
	sprites->Add(15063, sprites->Get(15061));

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(15000);
	animations->Add(RIFLEMAN_ANI_NORMAL_LEFT, ani);
	ani = new CAnimation(100);
	ani->Add(15001);
	animations->Add(RIFLEMAN_ANI_NORMAL_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(15010);
	animations->Add(RIFLEMAN_ANI_SHOOT_LEFT, ani);
	ani = new CAnimation(100);
	ani->Add(15011);
	animations->Add(RIFLEMAN_ANI_SHOOT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(15020);
	ani->Add(15030);
	animations->Add(RIFLEMAN_ANI_AIM_UP_LEFT, ani);
	ani = new CAnimation(100);
	ani->Add(15021);
	ani->Add(15031);
	animations->Add(RIFLEMAN_ANI_AIM_UP_RIGHT, ani);
	ani = new CAnimation(100);
	ani->Add(15040);
	animations->Add(RIFLEMAN_ANI_AIM_DOWN_LEFT, ani);
	ani = new CAnimation(100);
	ani->Add(15041);
	animations->Add(RIFLEMAN_ANI_AIM_DOWN_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(15050);
	animations->Add(RIFLEMAN_ANI_HIDE_LEFT, ani);
	ani = new CAnimation(100);
	ani->Add(15051);
	animations->Add(RIFLEMAN_ANI_HIDE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(15060);
	ani->Add(15061);
	animations->Add(RIFLEMAN_ANI_EXPOSE_LEFT, ani);
	ani = new CAnimation(100);
	ani->Add(15062);
	ani->Add(15063);
	animations->Add(RIFLEMAN_ANI_EXPOSE_RIGHT, ani);
}
void CreateFalconAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations)
{
	textures->Add(ID_TEX_FALCON, TEXTURE_PATH_FALCON);
	LPTEXTURE texFalcon = textures->Get(ID_TEX_FALCON);
	//id sprite 16xxx
	//normal falcon
	sprites->Add(16000, 0, 0, 31, 31, texFalcon);
	//opening falcon
	sprites->Add(16001, 34, 0, 65, 31, texFalcon);
	sprites->Add(16002, 68, 0, 99, 31, texFalcon);
	sprites->Add(16003, 102, 0, 133, 31, texFalcon);
	//opened falcon
	sprites->Add(16004, 136, 0, 167, 31, texFalcon);
	sprites->Add(16005, 170, 0, 201, 31, texFalcon);
	sprites->Add(16006, 204, 0, 235, 31, texFalcon);

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(16000);
	animations->Add(FALCON_ANI_CLOSED, ani);

	ani = new CAnimation(100);
	ani->Add(16001);
	ani->Add(16002);
	ani->Add(16003);
	animations->Add(FALCON_ANI_OPENING, ani);

	ani = new CAnimation(100);
	ani->Add(16004);
	ani->Add(16005);
	ani->Add(16006);
	animations->Add(FALCON_ANI_OPENED, ani);

	ani = new CAnimation(100);
	ani->Add(16003);
	ani->Add(16002);
	ani->Add(16001);
	animations->Add(FALCON_ANI_CLOSING, ani);
}
void CreateWTurretAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations)
{
	textures->Add(ID_TEX_WTURRET, TEXTURE_PATH_WTURRET);
	LPTEXTURE texWTurret = textures->Get(ID_TEX_WTURRET);
	//id tex 17xxx
	//turret appear
	sprites->Add(17000, 96, 64, 128, 96, texWTurret);
	sprites->Add(17001, 128, 64, 160, 96, texWTurret);
	sprites->Add(17002, 160, 64, 192, 96, texWTurret);
	sprites->Add(17003, 96, 32, 128, 64, texWTurret);
	sprites->Add(17004, 128, 32, 160, 64, texWTurret);
	sprites->Add(17005, 160, 32, 192, 64, texWTurret);
	//turret up
	sprites->Add(17006, 96, 0, 128, 32, texWTurret);
	sprites->Add(17007, 128, 0, 160, 32, texWTurret);
	sprites->Add(17008, 160, 0, 192, 32, texWTurret);
	//turret down
	sprites->Add(17009, 96, 96, 128, 128, texWTurret);
	sprites->Add(17010, 128, 96, 160, 128, texWTurret);
	sprites->Add(17011, 160, 96, 192, 128, texWTurret);
	//turret left 30
	sprites->Add(17012, 0, 0, 32, 32, texWTurret);
	sprites->Add(17013, 32, 0, 64, 32, texWTurret);
	sprites->Add(17014, 64, 0, 96, 32, texWTurret);
	//turret left 60
	sprites->Add(17015, 0, 32, 32, 64, texWTurret);
	sprites->Add(17016, 32, 32, 64, 64, texWTurret);
	sprites->Add(17017, 64, 32, 96, 64, texWTurret);
	//turret left 90 or DEFAUT STATE WHEN TURRET APPEAR
	sprites->Add(17018, 0, 64, 32, 96, texWTurret);
	sprites->Add(17019, 32, 64, 64, 96, texWTurret);
	sprites->Add(17020, 64, 64, 96, 96, texWTurret);
	//turret left 120
	sprites->Add(17021, 0, 96, 32, 128, texWTurret);
	sprites->Add(17022, 32, 96, 64, 128, texWTurret);
	sprites->Add(17023, 64, 96, 96, 128, texWTurret);
	//turret left 150
	sprites->Add(17024, 0, 128, 32, 160, texWTurret);
	sprites->Add(17025, 32, 128, 64, 160, texWTurret);
	sprites->Add(17026, 64, 128, 96, 160, texWTurret);
	
	//turret right 30
	sprites->Add(17027, 192, 0, 224, 32, texWTurret);
	sprites->Add(17028, 224, 0, 256, 32, texWTurret);
	sprites->Add(17029, 256, 0, 288, 32, texWTurret);
	//turret right 60
	sprites->Add(17030, 192, 32, 224, 64, texWTurret);
	sprites->Add(17031, 224, 32, 256, 64, texWTurret);
	sprites->Add(17032, 256, 32, 288, 64, texWTurret);
	//turret right 90
	sprites->Add(17033, 192, 64, 224, 96, texWTurret);
	sprites->Add(17034, 224, 64, 256, 96, texWTurret);
	sprites->Add(17035, 256, 64, 288, 96, texWTurret);
	//turret right 120
	sprites->Add(17036, 192, 96, 224, 128, texWTurret);
	sprites->Add(17037, 224, 96, 256, 128, texWTurret);
	sprites->Add(17038, 256, 96, 288, 128, texWTurret);
	//turret right 150
	sprites->Add(17039, 96, 128, 128, 160, texWTurret);
	sprites->Add(17040, 128, 128, 160, 160, texWTurret);
	sprites->Add(17041, 160, 128, 192, 160, texWTurret);

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(17000);
	ani->Add(17001);
	ani->Add(17002);
	ani->Add(17003);
	ani->Add(17004);
	ani->Add(17005);
	animations->Add(WTURRET_ANI_APPEAR, ani);

	ani = new CAnimation(100);
	ani->Add(17006);
	ani->Add(17007);
	ani->Add(17008);
	animations->Add(WTURRET_ANI_UP, ani);

	ani = new CAnimation(100);
	ani->Add(17009);
	ani->Add(17010);
	ani->Add(17011);
	animations->Add(WTURRET_ANI_DOWN, ani);

	ani = new CAnimation(100);
	ani->Add(17012);
	ani->Add(17013);
	ani->Add(17014);
	animations->Add(WTURRET_ANI_LEFT30, ani);

	ani = new CAnimation(100);
	ani->Add(17015);
	ani->Add(17016);
	ani->Add(17017);
	animations->Add(WTURRET_ANI_LEFT60, ani);

	ani = new CAnimation(100);
	ani->Add(17018);
	ani->Add(17019);
	ani->Add(17020);
	animations->Add(WTURRET_ANI_LEFT90, ani);

	ani = new CAnimation(100);
	ani->Add(17021);
	ani->Add(17022);
	ani->Add(17023);
	animations->Add(WTURRET_ANI_LEFT120, ani);

	ani = new CAnimation(100);
	ani->Add(17024);
	ani->Add(17025);
	ani->Add(17026);
	animations->Add(WTURRET_ANI_LEFT150, ani);

	ani = new CAnimation(100);
	ani->Add(17027);
	ani->Add(17028);
	ani->Add(17029);
	animations->Add(WTURRET_ANI_RIGHT30, ani);

	ani = new CAnimation(100);
	ani->Add(17030);
	ani->Add(17031);
	ani->Add(17032);
	animations->Add(WTURRET_ANI_RIGHT60, ani);

	ani = new CAnimation(100);
	ani->Add(17033);
	ani->Add(17034);
	ani->Add(17035);
	animations->Add(WTURRET_ANI_RIGHT90, ani);

	ani = new CAnimation(100);
	ani->Add(17036);
	ani->Add(17037);
	ani->Add(17038);
	animations->Add(WTURRET_ANI_RIGHT120, ani);

	ani = new CAnimation(100);
	ani->Add(17039);
	ani->Add(17040);
	ani->Add(17041);
	animations->Add(WTURRET_ANI_RIGHT150, ani);
}
void CreateScubaAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations)
{
	textures->Add(ID_TEX_SCUBA, TEXTURE_PATH_SCUBA);
	LPTEXTURE texScuba = textures->Get(ID_TEX_SCUBA);
	//id sprite 18xxx
	//Scuba soldier hide right
	sprites->Add(18000, 2, 0, 17, 30, texScuba);
	//Scuba soldier hide left
	sprites->Add(18001, sprites->Get(18000));
	//Scuba soldier shooting right
	sprites->Add(18002, 20, 0, 35, 30, texScuba);
	//Scuba soldier hide left
	sprites->Add(18003, sprites->Get(18002));

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(18000);
	animations->Add(SCUBA_ANI_HIDE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(18001);
	animations->Add(SCUBA_ANI_HIDE_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(18002);
	animations->Add(SCUBA_ANI_SHOOT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(18003);
	animations->Add(SCUBA_ANI_SHOOT_LEFT, ani);
}
void CreateOtherAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	textures->Add(ID_TEX_GRASS, TEXTURE_PATH_GRASS);
	textures->Add(ID_TEX_FIRE, TEXTURE_PATH_FIRE);
	textures->Add(ID_TEX_BOX, TEXTURE_PATH_BOX);
	textures->Add(ID_TEX_EXPLOSION, TEXTURE_PATH_EXPLOSION);
	textures->Add(ID_TEX_BRIDGE, TEXTURE_PATH_BRIDGE);

	LPTEXTURE texGrass = textures->Get(ID_TEX_GRASS);
	LPTEXTURE texFire = textures->Get(ID_TEX_FIRE);
	LPTEXTURE texExplosion = textures->Get(ID_TEX_EXPLOSION);
	LPTEXTURE texBridge = textures->Get(ID_TEX_BRIDGE);
	//grass
	sprites->Add(20000, 0, 0, 32, 16, texGrass);
	//fire
	sprites->Add(20001, 0, 0, 16, 16, texFire);
	sprites->Add(20002, 16, 0, 32, 16, texFire);
	//explosion type 1
	sprites->Add(20010, 0, 0, 25, 32, texExplosion);
	sprites->Add(20011, 164, 0, 189, 32, texExplosion);
	sprites->Add(20012, 26, 0, 55, 32, texExplosion);
	sprites->Add(20013, 190, 0, 219, 32, texExplosion);
	sprites->Add(20014, 56, 0, 89, 32, texExplosion);
	sprites->Add(20015, 220, 0, 253, 32, texExplosion);
	//explosion type 2
	sprites->Add(20020, 90, 0, 106, 32, texExplosion);
	sprites->Add(20021, 254, 0, 270, 32, texExplosion);
	sprites->Add(20022, 107, 0, 131, 32, texExplosion);
	sprites->Add(20023, 271, 0, 295, 32, texExplosion);
	sprites->Add(20024, 132, 0, 163, 32, texExplosion);
	sprites->Add(20025, 296, 0, 327, 32, texExplosion);
	//bridge 
	sprites->Add(20030, 0, 0, 16, 16, texBridge);	//upleft
	sprites->Add(20031, 0, 16, 16, 32, texBridge);	//upright
	sprites->Add(20032, 16, 0, 32, 16, texBridge);	//downbegin
	sprites->Add(20033, 16, 16, 32, 32, texBridge); //down
	sprites->Add(20034, 32, 16, 48, 32, texBridge);	//downend

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(20000);
	animations->Add(GRASS_ANI, ani);

	ani = new CAnimation(100);
	ani->Add(20001);
	ani->Add(20002);
	animations->Add(FIRE_ANI, ani);

	ani = new CAnimation(100);
	ani->Add(20010);
	ani->Add(20011);
	ani->Add(20012);
	ani->Add(20013);
	ani->Add(20014);
	ani->Add(20015);
	animations->Add(EXPLOSION_1_ANI, ani);

	ani = new CAnimation(100);
	ani->Add(20020);
	ani->Add(20021);
	ani->Add(20022);
	ani->Add(20023);
	ani->Add(20024);
	ani->Add(20025);
	animations->Add(EXPLOSION_2_ANI, ani);

	ani = new CAnimation(100);
	ani->Add(20030);
	animations->Add(BRIDGEPART_ANI_UPLEFT, ani);

	ani = new CAnimation(100);
	ani->Add(20031);
	animations->Add(BRIDGEPART_ANI_UPRIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(20032);
	animations->Add(BRIDGEPART_ANI_DOWNBEGIN, ani);

	ani = new CAnimation(100);
	ani->Add(20033);
	animations->Add(BRIDGEPART_ANI_DOWN, ani);

	ani = new CAnimation(100);
	ani->Add(20034);
	animations->Add(BRIDGEPART_ANI_DOWNEND, ani);
}
void CreateBossAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	//4xxxx
	textures->Add(ID_TEX_BOSS1, TEXTURE_PATH_BOSS1);
	//boss 1
	LPTEXTURE texBoss1 = textures->Get(ID_TEX_BOSS1);
	///shield
	////normal
	sprites->Add(40000, 0, 54, 23, 84, texBoss1);
	sprites->Add(40001, 27, 54, 50, 84, texBoss1);
	sprites->Add(40002, 54, 54, 77, 84, texBoss1);
	////after explode
	sprites->Add(40003, 0, 0, 108, 38, texBoss1);
	///gun
	sprites->Add(41000, 48, 42, 59, 48, texBoss1);
	

	LPANIMATION ani = new CAnimation(100);
	ani->Add(40000);
	ani->Add(40001);
	ani->Add(40002);
	animations->Add(BOSS1SHIELD_ANI_NORMAL, ani);

	ani = new CAnimation(100);
	ani->Add(40003);
	animations->Add(BOSS1SHIELD_ANI_AFTER_EXPLODE, ani);
	
	ani = new CAnimation(100);
	ani->Add(41000);
	animations->Add(BOSS1GUN_ANI_NORMAL, ani);
}

void CreateStageTile(CTextures*& textures, CSprites*& sprites, vector<LPTILE>& a) {
	textures->Add(ID_TEX_STAGE1_TILE, STAGE1_TILE);

	LPTEXTURE tex_stage1 = textures->Get(ID_TEX_STAGE1_TILE);
	a = Map::LoadFromFile(STAGE1_PATH, tex_stage1, sprites)->tileList;
}

void LoadScreenResources(CTextures*& textures, CSprites*& sprites) {
	//3xxxx
	textures->Add(ID_TEX_SCREEN_INTRO, SCREEN_INTRO_PATH);
	textures->Add(ID_TEX_SCREEN_WAITING, SCREEN_WAITING_PATH);
	textures->Add(ID_TEX_SCREEN_GAMEOVER, SCREEN_GAMEOVER_PATH);

	LPTEXTURE texIntro = textures->Get(ID_TEX_SCREEN_INTRO);
	LPTEXTURE texWaiting = textures->Get(ID_TEX_SCREEN_WAITING);
	LPTEXTURE texGameover = textures->Get(ID_TEX_SCREEN_GAMEOVER);

	sprites->Add(30000, 0, 0, 256, 224, texIntro);
	sprites->Add(30001, 0, 0, 256, 224, texWaiting);
	sprites->Add(30002, 0, 0, 255, 224, texGameover);
}