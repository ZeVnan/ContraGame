#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"

#define AIRCRAFT_SPEED_X 0.15f
#define AIRCRAFT_SPEED_Y 0.15f

#define AIRCRAFT_ACCEL_Y 0.008f

#define AIRCRAFT_STATE_DEAD 0

#define AIRCRAFT_ANI_NORMAL 10300
#define AIRCRAFT_ANI_bAMMO 10301
#define AIRCRAFT_ANI_fAMMO 10302
#define AIRCRAFT_ANI_lAMMO 10303
#define AIRCRAFT_ANI_mAMMO 10304
#define AIRCRAFT_ANI_rAMMO 10305
#define AIRCRAFT_ANI_sAMMO 10306

#define AIRCRAFT_ANI_INVUL 10310

#define AIRCRAFT_BOX_WIDTH 25
#define AIRCRAFT_BOX_HEIGHT 15

class CAircraft : public CGameObject
{
private:
	BOOLEAN isDead = false;
	float ay;
	int ammo;
public:
	CAircraft(float x, float y, int ammo);

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
};

