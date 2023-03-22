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

#include "Mario.h"
#include "Brick.h"
#include "Bill.h"

#include "SampleKeyEventHandler.h"

#define ID_TEX_MARIO 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20

#define ID_TEX_BILL 30

#define ID_SPRITE_BRICK 20001

#define TEXTURES_DIR L"textures"
#define TEXTURE_PATH_MARIO TEXTURES_DIR "\\mario.png"
#define TEXTURE_PATH_MISC TEXTURES_DIR "\\misc.png"

#define TEXTURE_PATH_BILL L"Images\\bill_animation_2.png"

#define MARIO_START_X 160.0f
#define MARIO_START_Y 10.0f

#define BILL_START_X 160.0f
#define BILL_START_Y 10.0f

#define BRICK_X 0.0f
#define BRICK_Y GROUND_Y + 20.0f
#define NUM_BRICKS 50

//CMario* mario = NULL;
//CBill* bill = NULL;
//vector<LPGAMEOBJECT> objects;
//CSampleKeyHandler* keyHandler;

void LoadBill();