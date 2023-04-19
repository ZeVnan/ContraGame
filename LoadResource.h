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
#include "Grass.h"
#include "Fire.h"

#include "SampleKeyEventHandler.h"
#include "Camera.h"
#include "World.h"
#include "WorldPart.h"

#define ID_TEX_BOX -10
#define ID_TEX_BILL 0
#define ID_TEX_BULLET 1
#define ID_TEX_SOLDIER 2
#define ID_TEX_AIRCRAFT 3
#define ID_TEX_CANNON 4
#define ID_TEX_RIFLEMAN 5
#define ID_TEX_FALCON 6
#define ID_TEX_SCUBA 7
#define ID_TEX_WTURRET 8
#define ID_TEX_GRASS 20
#define ID_TEX_FIRE 21

#define TEXTURE_PATH_BOX L"Images\\bbox.png"
#define TEXTURE_PATH_BILL L"Images\\bill_animation.png"
#define TEXTURE_PATH_BULLET L"Images\\Bullets.png"
#define TEXTURE_PATH_FALCON L"Images\\Falcon.png"
#define TEXTURE_PATH_SCUBA L"Images\\ScubaSoldier.png"
#define TEXTURE_PATH_WTURRET L"Images\\wall_turret_all.png"
#define TEXTURE_PATH_SOLDIER L"Images\\Soldier.png"
#define TEXTURE_PATH_BILL L"Images\\bill_animation.png"
#define TEXTURE_PATH_BULLET L"Images\\Bullets.png"
#define TEXTURE_PATH_AIRCRAFT L"Images\\aircraft.png"
#define TEXTURE_PATH_CANNON L"Images\\Cannon_all.png"
#define TEXTURE_PATH_RIFLEMAN L"Images\\rifleman.png"
#define TEXTURE_PATH_GRASS L"Images\\grass.png"
#define TEXTURE_PATH_FIRE L"Images\\fire.png"

#define STAGE1_PATH "Map\\stage1.xml"

void CreateBillAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateBulletAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateFalconAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateScubaAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateWTurretAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateAircraftAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateCannonAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateRiflemanAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateSoldierAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateOtherAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);