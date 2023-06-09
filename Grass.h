#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"
#define GRASS_ANI 20000
#define GRASS_WIDTH 64
#define GRASS_HEIGHT 32

class CGrass:public CGameObject
{
public:
	CGrass(float x, float y);

	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL) {};
	void CreateBox(DWORD dt);
};
typedef CGrass* LPGRASS;

