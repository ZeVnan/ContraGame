#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"

#define FIRE_ANI 20001

#define FIRE_BOX_WIDTH 32
#define FIRE_BOX_HEIGHT 32

class CFire:public CGameObject
{
public:
	CFire(float x, float y);

	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
};

