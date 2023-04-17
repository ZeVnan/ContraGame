#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"
#define GRASS_ANI 2000
#define GRASS_WIDTH 32
#define GRASS_HEIGHT 16

class CGrass:public CGameObject
{
public:
	CGrass(float x, float y);

	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL) {};
	void CreateBox(DWORD dt);
};

