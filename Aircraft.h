#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"

#define AIRCRAFT_SPEED_X 0.3f
#define AIRCRAFT_SPEED_Y 0.2f
#define AIRCRAFT_GRAVITY -0.00075f
#define AIRCRAFT_ACTIVE_RADIUS 300

#define AIRCRAFT_STATE_NORMAL 0
#define AIRCRAFT_STATE_EXPLODE 1
#define AIRCRAFT_STATE_DROPITEM 2

#define AIRCRAFT_ANI_NORMAL 13000
#define AIRCRAFT_ANI_bAMMO 13001
#define AIRCRAFT_ANI_fAMMO 13002
#define AIRCRAFT_ANI_lAMMO 13003
#define AIRCRAFT_ANI_mAMMO 13004
#define AIRCRAFT_ANI_rAMMO 13005
#define AIRCRAFT_ANI_sAMMO 13006

#define AIRCRAFT_ANI_INVUL 13010

#define AIRCRAFT_BOX_WIDTH 50
#define AIRCRAFT_BOX_HEIGHT 30

class CAircraft : public CGameObject
{
private:
	BOOLEAN isCollectible;
	BOOLEAN isActivated;
	float ay;
	int ammo;
	int timeleft;
	int stage;
public:
	CAircraft(float x, float y, int stage);
	void watchBill();

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	void CollisionWithGrass(LPCOLLISIONEVENT e);
	bool isBlocking() { return false; }
	bool isCollidable() {
		return isActivated;
	}

	bool IsCollectible() {
		return isCollectible;
	}
	int getAmmoType() {
		return ammo;
	}
};
typedef CAircraft* LPAIRCRAFT;

