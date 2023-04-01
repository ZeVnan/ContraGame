#pragma once
#include <windows.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Textures.h"

#include "Animation.h"
#include "Animations.h"
#include "Sprite.h"
#include "Sprites.h"

#include "Bill.h"
#include "Bullet.h"

#include "Soldier.h"
#include "Falcon.h"
#include "WallTurret.h"
#include "ScubaSoldier.h"
#include "Aircraft.h"
#include "Cannon.h"
#include "Rifleman.h"


#include "SampleKeyEventHandler.h"

#define ID_TEX_BILL 0
#define ID_TEX_BULLET 1

#define ID_TEX_FALCON 10
#define ID_TEX_SCUBA 11
#define ID_TEX_WTURRET 12

#define TEXTURE_PATH_BILL L"Images\\bill_animation.png"
#define TEXTURE_PATH_BULLET L"Images\\Bullets.png"
#define TEXTURE_PATH_FALCON L"Images\\Falcon.png"
#define TEXTURE_PATH_SCUBA L"Images\\ScubaSoldier.png"
#define TEXTURE_PATH_WTURRET L"Images\\wall_turret_all.png"

void CreateBillAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateBulletAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateFalconAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateScubaAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateWTurretAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);

#define ID_TEX_AIRCRAFT 3
#define ID_TEX_CANNON 4
#define ID_TEX_RIFLEMAN 5

#define TEXTURE_PATH_BILL L"Images\\bill_animation.png"
#define TEXTURE_PATH_BULLET L"Images\\Bullets.png"
#define TEXTURE_PATH_AIRCRAFT L"Images\\aircraft.png"
#define TEXTURE_PATH_CANNON L"Images\\Cannon_all"
#define TEXTURE_PATH_RIFLEMAN L"Images\\rifleman.png"

void CreateBillAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateBulletAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateAircraftAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateCannonAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateRiflemanAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);


