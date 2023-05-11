#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"

#include "Bullet.h"


#define SOLDIER_RUN_SPEED 0.1f
#define SOLDIER_JUMP_SPEED_Y 0.2f
#define SOLDIER_GRAVITY -0.00075f

#define SOLDIER_START_X 20.0f
#define SOLDIER_START_Y 10.0f
#define SOLDIER_LAY_HEIGHT_ADJUST 10.0f

#define SOLDIER_STATE_RUN_RIGHT 10
#define SOLDIER_STATE_RUN_LEFT 11

#define SOLDIER_STATE_JUMP 20
#define SOLDIER_STATE_JUMP_RELEASE 21

#define SOLDIER_STATE_SHOOT 30
#define SOLDIER_STATE_SHOOT_RELEASE 31

#define SOLDIER_STATE_LAYDOWN 40
#define SOLDIER_STATE_LAYDOWN_RELEASE 41

#define SOLDIER_STATE_EXPLODE 50


#define SOLDIER_ANI_RUN_LEFT 10200
#define SOLDIER_ANI_RUN_RIGHT 10201

#define SOLDIER_ANI_JUMP_LEFT 10210
#define SOLDIER_ANI_JUMP_RIGHT 10211

#define SOLDIER_ANI_SHOOT_LEFT 10220
#define SOLDIER_ANI_SHOOT_RIGHT 10221

#define SOLDIER_ANI_LAYDOWN_LEFT 10230
#define SOLDIER_ANI_LAYDOWN_RIGHT 10231

#define SOLDIER_ANI_DIE_LEFT 10240
#define SOLDIER_ANI_DIE_RIGHT 10241

#define SOLDIER_BOX_RUN_WIDTH	64
#define SOLDIER_BOX_RUN_HEIGHT	128
#define SOLDIER_BOX_SHOOT_WIDTH	96
#define SOLDIER_BOX_SHOOT_HEIGHT	96
#define SOLDIER_BOX_LAY_WIDTH	128
#define SOLDIER_BOX_LAY_HEIGHT	60

class CSoldier: public CGameObject
{
private:
	BOOLEAN isLaying;
	BOOLEAN isShooting;
	BOOLEAN isOnPlatform;
	float maxVx;
	float maxVy;
	float gunx;
	float guny;
	vector<LPBULLET> bullets;
	int timeleft;
public:
	CSoldier();
	CSoldier(float x, float y);

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int State);

	void AddBullet();
	void DelBullet();

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	void CollisionWithGrass(LPCOLLISIONEVENT e);

	bool isBlocking() { return false; }
	bool isCollidable() { return !isExploded; }
};
typedef CSoldier* LPSOLDIER;