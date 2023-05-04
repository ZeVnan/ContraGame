#pragma once
#include "LoadResource.h"

void CreateBillAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	//100xx
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
	//normal bullet (bill)
	sprites->Add(10111, 64, 42, 66, 44, texBullet);
	//laser bullet
	sprites->Add(10101, 23, 39, 38, 44, texBullet);
	sprites->Add(10105, sprites->Get(10101), 45);
	sprites->Add(10106, sprites->Get(10101), 135);
	sprites->Add(10107, sprites->Get(10101), 225);
	sprites->Add(10108, sprites->Get(10101), 315);
	sprites->Add(10109, sprites->Get(10101), 90);
	sprites->Add(10110, sprites->Get(10101), 270);
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
	ani->Add(10111);
	animations->Add(BULLET_ANI_NORMAL_BILL, ani);

	ani = new CAnimation(100);
	ani->Add(10101);
	animations->Add(BULLET_ANI_LASER, ani);
	ani = new CAnimation(100);
	ani->Add(10105);
	animations->Add(BULLET_ANI_LASER_45, ani);
	ani = new CAnimation(100);
	ani->Add(10106);
	animations->Add(BULLET_ANI_LASER_135, ani);
	ani = new CAnimation(100);
	ani->Add(10107);
	animations->Add(BULLET_ANI_LASER_225, ani);
	ani = new CAnimation(100);
	ani->Add(10108);
	animations->Add(BULLET_ANI_LASER_315, ani);
	ani = new CAnimation(100);
	ani->Add(10109);
	animations->Add(BULLET_ANI_LASER_90, ani);

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
void CreateAircraftAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	textures->Add(ID_TEX_AIRCRAFT, TEXTURE_PATH_AIRCRAFT);
	LPTEXTURE aircraftTex = textures->Get(ID_TEX_AIRCRAFT);
	//aircraft 103xx

	//normal
	sprites->Add(10310, 2, 0, 27, 15, aircraftTex);
	//b_ammo
	sprites->Add(10311, 28, 0, 53, 15, aircraftTex);
	//f_ammo
	sprites->Add(10312, 54, 0, 79, 15, aircraftTex);
	//l_ammo
	sprites->Add(10313, 80, 0, 105, 15, aircraftTex);
	//m_ammo
	sprites->Add(10314, 106, 0, 131, 15, aircraftTex);
	//r_ammo
	sprites->Add(10315, 132, 0, 157, 15, aircraftTex);
	//s_ammo
	sprites->Add(10316, 158, 0, 183, 15, aircraftTex);
	//invul
	sprites->Add(10317, 186, 0, 212, 15, aircraftTex);
	sprites->Add(10318, 217, 0, 242, 15, aircraftTex);
	sprites->Add(10319, 247, 0, 272, 15, aircraftTex);

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(10310);
	animations->Add(AIRCRAFT_ANI_NORMAL, ani);

	ani = new CAnimation(100);
	ani->Add(10311);
	animations->Add(AIRCRAFT_ANI_bAMMO, ani);
	ani = new CAnimation(100);
	ani->Add(10312);
	animations->Add(AIRCRAFT_ANI_fAMMO, ani);
	ani = new CAnimation(100);
	ani->Add(10313);
	animations->Add(AIRCRAFT_ANI_lAMMO, ani);
	ani = new CAnimation(100);
	ani->Add(10314);
	animations->Add(AIRCRAFT_ANI_mAMMO, ani);
	ani = new CAnimation(100);
	ani->Add(10315);
	animations->Add(AIRCRAFT_ANI_rAMMO, ani);
	ani = new CAnimation(100);
	ani->Add(10316);
	animations->Add(AIRCRAFT_ANI_sAMMO, ani);

	ani = new CAnimation(100);
	ani->Add(10317);
	ani->Add(10318);
	ani->Add(10319);
	animations->Add(AIRCRAFT_ANI_INVUL, ani);
}
void CreateCannonAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	textures->Add(ID_TEX_CANNON, TEXTURE_PATH_CANNON);
	LPTEXTURE cannonTex = textures->Get(ID_TEX_CANNON);
	//cannon 104xx

	//left
	sprites->Add(10400, 66, 66, 98, 98, cannonTex);
	sprites->Add(10401, 66, 34, 98, 66, cannonTex);
	sprites->Add(10402, 66, 2, 98, 34, cannonTex);
	//left - 60
	sprites->Add(10403, 98, 66, 130, 98, cannonTex);
	sprites->Add(10404, 98, 34, 130, 66, cannonTex);
	sprites->Add(10405, 98, 2, 130, 34, cannonTex);
	//left - 30
	sprites->Add(10406, 130, 66, 162, 98, cannonTex);
	sprites->Add(10407, 130, 34, 162, 66, cannonTex);
	sprites->Add(10408, 130, 2, 162, 34, cannonTex);
	//appear
	sprites->Add(10410, 2, 66, 34, 98, cannonTex);
	sprites->Add(10411, 2, 34, 34, 66, cannonTex);
	sprites->Add(10412, 2, 2, 34, 34, cannonTex);
	sprites->Add(10413, 34, 66, 66, 98, cannonTex);
	sprites->Add(10414, 34, 34, 66, 66, cannonTex);
	sprites->Add(10415, 34, 2, 66, 34, cannonTex);

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(10400);
	ani->Add(10401);
	ani->Add(10402);
	animations->Add(CANNON_ANI_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10403);
	ani->Add(10404);
	ani->Add(10405);
	animations->Add(CANNON_ANI_LEFT_60, ani);

	ani = new CAnimation(100);
	ani->Add(10406);
	ani->Add(10407);
	ani->Add(10408);
	animations->Add(CANNON_ANI_LEFT_30, ani);

	ani = new CAnimation(100);
	ani->Add(10410);
	ani->Add(10411);
	ani->Add(10412);
	ani->Add(10413);
	ani->Add(10414);
	ani->Add(10415);
	animations->Add(CANNON_ANI_APPEAR, ani);
}
void CreateRiflemanAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	textures->Add(ID_TEX_RIFLEMAN, TEXTURE_PATH_RIFLEMAN);
	LPTEXTURE riflemanTex = textures->Get(ID_TEX_RIFLEMAN);
	//rifleman 105xx
	//normal-left
	sprites->Add(10500, 0, 0, 23, 38, riflemanTex);
	//normal-right
	sprites->Add(10501, sprites->Get(10500));
	//shoot-left
	sprites->Add(10510, 26, 0, 49, 38, riflemanTex);
	//shoot-right
	sprites->Add(10511, sprites->Get(10510));
	//aim_up-left
	sprites->Add(10520, 52, 0, 69, 38, riflemanTex);
	//aim_up-right
	sprites->Add(10521, sprites->Get(10520));
	//shoot_up-left
	sprites->Add(10530, 72, 0, 89, 38, riflemanTex);
	//shoot_up-right
	sprites->Add(10531, sprites->Get(10530));
	//aim_down-left
	sprites->Add(10540, 92, 0, 115, 38, riflemanTex);
	//aim_down-right
	sprites->Add(10541, sprites->Get(10540));
	//hide-left
	sprites->Add(10550, 118, 0, 125, 38, riflemanTex);
	//hide-right
	sprites->Add(10551, sprites->Get(10550));
	//expose-left
	sprites->Add(10560, 128, 0, 150, 38, riflemanTex);
	sprites->Add(10561, 153, 0, 176, 38, riflemanTex);
	//expose-right
	sprites->Add(10562, sprites->Get(10560));
	sprites->Add(10563, sprites->Get(10561));

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(10500);
	animations->Add(RIFLEMAN_ANI_NORMAL_LEFT, ani);
	ani = new CAnimation(100);
	ani->Add(10501);
	animations->Add(RIFLEMAN_ANI_NORMAL_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10510);
	animations->Add(RIFLEMAN_ANI_SHOOT_LEFT, ani);
	ani = new CAnimation(100);
	ani->Add(10511);
	animations->Add(RIFLEMAN_ANI_SHOOT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10520);
	ani->Add(10530);
	animations->Add(RIFLEMAN_ANI_AIM_UP_LEFT, ani);
	ani = new CAnimation(100);
	ani->Add(10521);
	ani->Add(10531);
	animations->Add(RIFLEMAN_ANI_AIM_UP_RIGHT, ani);
	ani = new CAnimation(100);
	ani->Add(10540);
	animations->Add(RIFLEMAN_ANI_AIM_DOWN_LEFT, ani);
	ani = new CAnimation(100);
	ani->Add(10541);
	animations->Add(RIFLEMAN_ANI_AIM_DOWN_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10550);
	animations->Add(RIFLEMAN_ANI_HIDE_LEFT, ani);
	ani = new CAnimation(100);
	ani->Add(10551);
	animations->Add(RIFLEMAN_ANI_HIDE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10560);
	ani->Add(10561);
	animations->Add(RIFLEMAN_ANI_EXPOSE_LEFT, ani);
	ani = new CAnimation(100);
	ani->Add(10562);
	ani->Add(10563);
	animations->Add(RIFLEMAN_ANI_EXPOSE_RIGHT, ani);
}
void CreateFalconAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations)
{
	textures->Add(ID_TEX_FALCON, TEXTURE_PATH_FALCON);
	LPTEXTURE texFalcon = textures->Get(ID_TEX_FALCON);
	//id sprite 106xx
	//normal falcon
	sprites->Add(10600, 0, 0, 31, 31, texFalcon);
	//opening falcon
	sprites->Add(10601, 34, 0, 65, 31, texFalcon);
	sprites->Add(10602, 68, 0, 99, 31, texFalcon);
	sprites->Add(10603, 102, 0, 133, 31, texFalcon);
	//opened falcon
	sprites->Add(10604, 136, 0, 167, 31, texFalcon);
	sprites->Add(10605, 170, 0, 201, 31, texFalcon);
	sprites->Add(10606, 204, 0, 235, 31, texFalcon);

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(10600);
	animations->Add(FALCON_ANI_CLOSED, ani);

	ani = new CAnimation(100);
	ani->Add(10601);
	ani->Add(10602);
	ani->Add(10603);
	animations->Add(FALCON_ANI_OPENING, ani);

	ani = new CAnimation(100);
	ani->Add(10604);
	ani->Add(10605);
	ani->Add(10606);
	animations->Add(FALCON_ANI_OPENED, ani);

	ani = new CAnimation(100);
	ani->Add(10603);
	ani->Add(10602);
	ani->Add(10601);
	animations->Add(FALCON_ANI_CLOSING, ani);
}
void CreateWTurretAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations)
{
	textures->Add(ID_TEX_WTURRET, TEXTURE_PATH_WTURRET);
	LPTEXTURE texWTurret = textures->Get(ID_TEX_WTURRET);
	//id tex 107xx
	//turret appear
	sprites->Add(10700, 96, 64, 128, 96, texWTurret);
	sprites->Add(10701, 128, 64, 160, 96, texWTurret);
	sprites->Add(10702, 160, 64, 192, 96, texWTurret);
	sprites->Add(10703, 96, 32, 128, 64, texWTurret);
	sprites->Add(10704, 128, 32, 160, 64, texWTurret);
	sprites->Add(10705, 160, 32, 192, 64, texWTurret);
	//turret up
	sprites->Add(10706, 96, 0, 128, 32, texWTurret);
	sprites->Add(10707, 128, 0, 160, 32, texWTurret);
	sprites->Add(10708, 160, 0, 192, 32, texWTurret);
	//turret down
	sprites->Add(10709, 96, 96, 128, 128, texWTurret);
	sprites->Add(10710, 128, 96, 160, 128, texWTurret);
	sprites->Add(10711, 160, 96, 192, 128, texWTurret);
	//turret left 30
	sprites->Add(10712, 0, 0, 32, 32, texWTurret);
	sprites->Add(10713, 32, 0, 64, 32, texWTurret);
	sprites->Add(10714, 64, 0, 96, 32, texWTurret);
	//turret left 60
	sprites->Add(10715, 0, 32, 32, 64, texWTurret);
	sprites->Add(10716, 32, 32, 64, 64, texWTurret);
	sprites->Add(10717, 64, 32, 96, 64, texWTurret);
	//turret left 90 or DEFAUT STATE WHEN TURRET APPEAR
	sprites->Add(10718, 0, 64, 32, 96, texWTurret);
	sprites->Add(10719, 32, 64, 64, 96, texWTurret);
	sprites->Add(10720, 64, 64, 96, 96, texWTurret);
	//turret left 120
	sprites->Add(10721, 0, 96, 32, 128, texWTurret);
	sprites->Add(10722, 32, 96, 64, 128, texWTurret);
	sprites->Add(10723, 64, 96, 96, 128, texWTurret);
	//turret left 150
	sprites->Add(10724, 0, 128, 32, 160, texWTurret);
	sprites->Add(10725, 32, 128, 64, 160, texWTurret);
	sprites->Add(10726, 64, 128, 96, 160, texWTurret);
	
	//turret right 30
	sprites->Add(10727, 192, 0, 224, 32, texWTurret);
	sprites->Add(10728, 224, 0, 256, 32, texWTurret);
	sprites->Add(10729, 256, 0, 288, 32, texWTurret);
	//turret right 60
	sprites->Add(10730, 192, 32, 224, 64, texWTurret);
	sprites->Add(10731, 224, 32, 256, 64, texWTurret);
	sprites->Add(10732, 256, 32, 288, 64, texWTurret);
	//turret right 90
	sprites->Add(10733, 192, 64, 224, 96, texWTurret);
	sprites->Add(10734, 224, 64, 256, 96, texWTurret);
	sprites->Add(10735, 256, 64, 288, 96, texWTurret);
	//turret right 120
	sprites->Add(10736, 192, 96, 224, 128, texWTurret);
	sprites->Add(10737, 224, 96, 256, 128, texWTurret);
	sprites->Add(10738, 256, 96, 288, 128, texWTurret);
	//turret right 150
	sprites->Add(10739, 96, 128, 128, 160, texWTurret);
	sprites->Add(10740, 128, 128, 160, 160, texWTurret);
	sprites->Add(10741, 160, 128, 192, 160, texWTurret);

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(10700);
	ani->Add(10701);
	ani->Add(10702);
	ani->Add(10703);
	ani->Add(10704);
	ani->Add(10705);
	animations->Add(WTURRET_ANI_APPEAR, ani);

	ani = new CAnimation(100);
	ani->Add(10706);
	ani->Add(10707);
	ani->Add(10708);
	animations->Add(WTURRET_ANI_UP, ani);

	ani = new CAnimation(100);
	ani->Add(10709);
	ani->Add(10710);
	ani->Add(10711);
	animations->Add(WTURRET_ANI_DOWN, ani);

	ani = new CAnimation(100);
	ani->Add(10712);
	ani->Add(10713);
	ani->Add(10714);
	animations->Add(WTURRET_ANI_LEFT30, ani);

	ani = new CAnimation(100);
	ani->Add(10715);
	ani->Add(10716);
	ani->Add(10717);
	animations->Add(WTURRET_ANI_LEFT60, ani);

	ani = new CAnimation(100);
	ani->Add(10718);
	ani->Add(10719);
	ani->Add(10720);
	animations->Add(WTURRET_ANI_LEFT90, ani);

	ani = new CAnimation(100);
	ani->Add(10721);
	ani->Add(10722);
	ani->Add(10723);
	animations->Add(WTURRET_ANI_LEFT120, ani);

	ani = new CAnimation(100);
	ani->Add(10724);
	ani->Add(10725);
	ani->Add(10726);
	animations->Add(WTURRET_ANI_LEFT150, ani);

	ani = new CAnimation(100);
	ani->Add(10727);
	ani->Add(10728);
	ani->Add(10729);
	animations->Add(WTURRET_ANI_RIGHT30, ani);

	ani = new CAnimation(100);
	ani->Add(10730);
	ani->Add(10731);
	ani->Add(10732);
	animations->Add(WTURRET_ANI_RIGHT60, ani);

	ani = new CAnimation(100);
	ani->Add(10733);
	ani->Add(10734);
	ani->Add(10735);
	animations->Add(WTURRET_ANI_RIGHT90, ani);

	ani = new CAnimation(100);
	ani->Add(10736);
	ani->Add(10737);
	ani->Add(10738);
	animations->Add(WTURRET_ANI_RIGHT120, ani);

	ani = new CAnimation(100);
	ani->Add(10739);
	ani->Add(10740);
	ani->Add(10741);
	animations->Add(WTURRET_ANI_RIGHT150, ani);
}
void CreateScubaAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations)
{
	textures->Add(ID_TEX_SCUBA, TEXTURE_PATH_SCUBA);
	LPTEXTURE texScuba = textures->Get(ID_TEX_SCUBA);
	//id sprite 108xx
	//Scuba soldier hide right
	sprites->Add(10800, 2, 0, 17, 30, texScuba);
	//Scuba soldier hide left
	sprites->Add(10801, sprites->Get(10800));
	//Scuba soldier shooting right
	sprites->Add(10802, 20, 0, 35, 30, texScuba);
	//Scuba soldier hide left
	sprites->Add(10803, sprites->Get(10802));

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(10800);
	animations->Add(SCUBA_ANI_HIDE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10801);
	animations->Add(SCUBA_ANI_HIDE_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10802);
	animations->Add(SCUBA_ANI_SHOOT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10803);
	animations->Add(SCUBA_ANI_SHOOT_LEFT, ani);
}

void CreateOtherAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations) {
	textures->Add(ID_TEX_GRASS, TEXTURE_PATH_GRASS);
	textures->Add(ID_TEX_FIRE, TEXTURE_PATH_FIRE);
	textures->Add(ID_TEX_BOX, TEXTURE_PATH_BOX);

	LPTEXTURE texGrass = textures->Get(ID_TEX_GRASS);
	LPTEXTURE texFire = textures->Get(ID_TEX_FIRE);
	//grass
	sprites->Add(20000, 0, 0, 32, 16, texGrass);
	//fire
	sprites->Add(20001, 0, 0, 16, 16, texFire);
	sprites->Add(20002, 16, 0, 32, 16, texFire);

	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(20000);
	animations->Add(GRASS_ANI, ani);

	ani = new CAnimation(100);
	ani->Add(20001);
	ani->Add(20002);
	animations->Add(FIRE_ANI, ani);
}