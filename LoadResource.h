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
#include "Aircraft.h"
#include "Cannon.h"

#include "SampleKeyEventHandler.h"

#define ID_TEX_BILL 0
#define ID_TEX_BULLET 1
#define ID_TEX_AIRCRAFT 3
#define ID_TEX_CANNON 4
#define ID_TEX_RIFLEMAN 5

#define TEXTURE_PATH_BILL L"Images\\bill_animation.png"
#define TEXTURE_PATH_BULLET L"Images\\Bullets.png"
#define TEXTURE_PATH_AIRCRAFT L"Images\\aircraft.png"
#define TEXTURE_PATH_CANNON L"Images\\Cannon_all"

void CreateBillAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateBulletAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateAircraftAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateCannonAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);