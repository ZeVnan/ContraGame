#pragma once
#include "debug.h"

#include "Aircraft.h"

#define FALCON_SPEED_Y 0.6f
#define FALCON_GRAVITY -0.00075f

#define FALCON_CLOSE_TIME 1500
#define FALCON_OPEN_TIME 1500
#define FALCON_CLOSING_TIME 300
#define FALCON_OPENING_TIME 300

#define FALCON_STATE_CLOSE 0
#define FALCON_STATE_OPEN 1
#define FALCON_STATE_CLOSING 2
#define FALCON_STATE_OPENING 3
#define FALCON_STATE_EXPLODE 4
#define FALCON_STATE_DROPITEM 5

#define FALCON_ANI_CLOSED		16000
#define FALCON_ANI_OPENING		16001
#define FALCON_ANI_OPENED		16002
#define FALCON_ANI_CLOSING		16003

#define FALCON_bAMMO 16001
#define FALCON_fAMMO 16002
#define FALCON_lAMMO 16003
#define FALCON_mAMMO 16004
#define FALCON_rAMMO 16005
#define FALCON_sAMMO 16006

#define FALCON_BOX_WIDTH 62
#define FALCON_BOX_HEIGHT 62

#define FALCON_ITEM_BOX_WIDTH 50
#define FALCON_ITEM_BOX_HEIGHT 30

class CFalcon : public CGameObject
{
private:
	float ay;
	bool isCollectible;
	int timeleft;
	int ammo;
public:
	CFalcon(float x, float y);
	
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	void CollisionWithGrass(LPCOLLISIONEVENT e);
	bool isBlocking() { return false; }
	bool isCollidable() { return true; }
	bool IsCollectible() { return isCollectible; }

	int getAmmoType() { return ammo; }
};
typedef CFalcon* LPFALCON;