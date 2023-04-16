#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"

#define AIRCRAFT_SPEED_X 0.15f
#define AIRCRAFT_SPEED_Y 0.15f

#define AIRCRAFT_ACCEL_Y 0.008f

#define AIRCRAFT_STATE_DEAD 0

#define AIRCRAFT_ANI_NORMAL 200
#define AIRCRAFT_ANI_bAMMO 201
#define AIRCRAFT_ANI_fAMMO 202
#define AIRCRAFT_ANI_lAMMO 203
#define AIRCRAFT_ANI_mAMMO 204
#define AIRCRAFT_ANI_rAMMO 205
#define AIRCRAFT_ANI_sAMMO 206

#define AIRCRAFT_ANI_INVUL 207

class CAircraft : public CGameObject
{
private:
	BOOLEAN isDead = false;
	float ay;
	int ammo;
public:
	CAircraft();
	CAircraft(float x, float y, int ammo);

	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};

