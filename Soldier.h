#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"

#include "BulletN.h"


#define SOLDIER_RUN_SPEED 0.1f
#define SOLDIER_JUMP_SPEED_Y 0.4f
#define SOLDIER_GRAVITY -0.00075f
#define SOLDIER_ACTIVE_RADIUS 600

#define SOLDIER_START_X 20.0f
#define SOLDIER_START_Y 10.0f
#define SOLDIER_LAY_HEIGHT_ADJUST 10.0f

#define SOLDIER_STATE_RUN_RIGHT 10
#define SOLDIER_STATE_RUN_LEFT 11

#define SOLDIER_STATE_JUMP 20
#define SOLDIER_STATE_DROP 21

#define SOLDIER_STATE_SHOOT 30
#define SOLDIER_STATE_SHOOT_RELEASE 31

#define SOLDIER_STATE_LAYDOWN 40
#define SOLDIER_STATE_LAYDOWN_RELEASE 41

#define SOLDIER_STATE_ON_LAND 50

#define SOLDIER_STATE_EXPLODE 60


#define SOLDIER_ANI_RUN_LEFT 10200
#define SOLDIER_ANI_RUN_RIGHT 10201

#define SOLDIER_ANI_JUMP_LEFT 12010
#define SOLDIER_ANI_JUMP_RIGHT 12011

#define SOLDIER_ANI_SHOOT_LEFT 12020
#define SOLDIER_ANI_SHOOT_RIGHT 12021

#define SOLDIER_ANI_LAYDOWN_LEFT 12030
#define SOLDIER_ANI_LAYDOWN_RIGHT 12031

#define SOLDIER_ANI_DIE_LEFT 12040
#define SOLDIER_ANI_DIE_RIGHT 12041

#define SOLDIER_BOX_RUN_WIDTH	32
#define SOLDIER_BOX_RUN_HEIGHT	64

class CSoldier: public CGameObject
{
private:
	bool isLaying;
	bool isShooting;
	bool isOnPlatform;
	bool isJumping;
	bool isActivated;
	bool isDropping;
	float gunx;
	float guny;
	vector<LPBULLET> bullets;
	int timeleft;
public:
	CSoldier(float x, float y);
	void watchBill();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int State);

	void AddBullet();
	void UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void RenderBullet();

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	void CollisionWithGrass(LPCOLLISIONEVENT e);
	void CollisionWithWater(LPCOLLISIONEVENT e);
	void CollisionWithTriggerBox(LPCOLLISIONEVENT e);
	void CollisionWithBridge(LPCOLLISIONEVENT e);
	void CollisionWithRockFly(LPCOLLISIONEVENT e);

	bool isBlocking() { return false; }
	bool isCollidable() { return !isExploded; }
};
typedef CSoldier* LPSOLDIER;