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

#include "SampleKeyEventHandler.h"

#define ID_TEX_BILL 0
#define ID_TEX_BULLET 1

#define TEXTURE_PATH_BILL L"Images\\bill_animation.png"
#define TEXTURE_PATH_BULLET L"Images\\Bullets.png"

void CreateBillAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);
void CreateBulletAni(CTextures*& textures, CSprites*& sprites, CAnimations*& animations);