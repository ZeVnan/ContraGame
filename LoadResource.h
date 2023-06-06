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
#include "BridgePart.h"
#include "RockFall.h"
#include "RockFly.h"

#include "Boss1Shield.h"
#include "Boss1Gun.h"
#include "Boss3Mouth.h"
#include "Boss3Arm.h"

#include "SampleKeyEventHandler.h"
#include "Camera.h"
#include "World.h"
#include "WorldPart.h"

#include "Map.h"

#define ID_TEX_EXPLOSION -11
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
#define ID_TEX_ROCKFALL 9

#define ID_TEX_GRASS 20
#define ID_TEX_FIRE 21
#define ID_TEX_BRIDGE 22
#define ID_TEX_ROCKFLY 23

#define ID_TEX_BOSS1 30
#define ID_TEX_BOSS3_MOUTH 31
#define ID_TEX_STAGE3_ELEMENT 32

#define ID_TEX_STAGE1_TILE 100
#define ID_TEX_STAGE3_TILE 101

#define ID_TEX_SCREEN_INTRO 200
#define ID_TEX_SCREEN_TUTORIAL 201
#define ID_TEX_SCREEN_WAITING1 202
#define ID_TEX_SCREEN_WAITING3 203
#define ID_TEX_SCREEN_GAMEOVER 204
#define ID_TEX_SCREEN_CREDIT 205
#define ID_TEX_SCREEN_OPTION 206

#define TEXTURE_PATH_EXPLOSION L"Images\\Explosion.png"
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
#define TEXTURE_PATH_ROCKFALL L"Images\\rockfall.png"
#define TEXTURE_PATH_ROCKFLY L"Images\\stage3_elements.png"
#define TEXTURE_PATH_BRIDGE L"Images\\bridge.png"
#define TEXTURE_PATH_BOSS1 L"Images\\boss_stage1.png"
#define TEXTURE_PATH_BOSS3_MOUTH L"Images\\boss_stage3.png"
#define TEXTURE_PATH_STAGE3_ELEMENT L"Images\\stage3_elements.png"

#define STAGE1_PATH "Map\\stage1.xml"
#define STAGE1_TILE L"Map\\stage1.png"
#define STAGE3_PATH "Map\\stage3.xml"
#define STAGE3_TILE L"Map\\stage3.png"

#define SCREEN_INTRO_PATH L"Images\\intro.png"
#define SCREEN_TUTORIAL_PATH L"Images\\Tutorial.png"
#define SCREEN_WAITING1_PATH L"Images\\Stage1.png"
#define SCREEN_WAITING3_PATH L"Images\\Stage3.png"
#define SCREEN_GAMEOVER_PATH L"Images\\GameOver.png"
#define SCREEN_CREDIT_PATH L"Images\\Credits.png"
#define SCREEN_OPTION_PATH L"Images\\yellowfalcon.png"

void CreateBillAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateBulletAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateFalconAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateScubaAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateWTurretAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateAircraftAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateCannonAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateRiflemanAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateSoldierAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateRockFallAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateOtherAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateBossAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);

void CreateStageTile(CTextures*& textures, CSprites*& sprites, vector<LPTILE>& a, int stage);

void LoadScreenResources(CTextures*& textures, CSprites*& sprites);