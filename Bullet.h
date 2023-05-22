#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define BULLET_SPEED 0.4f;

#define BULLET_ANI_NORMAL 11000
#define BULLET_ANI_NORMAL_BILL 11001

#define BULLET_ANI_FLAME 11010

#define BULLET_ANI_SPREAD 11020

#define BULLET_ANI_MACHINE 11030

#define BULLET_ANI_LASER 11040
#define BULLET_ANI_LASER_45 11041
#define BULLET_ANI_LASER_135 11042
#define BULLET_ANI_LASER_225 11043
#define BULLET_ANI_LASER_315 11044
#define BULLET_ANI_LASER_90 11045
#define BULLET_ANI_LASER_270 11046

#define BULLET_ANI_BOSS1 11050

class CBullet :public CGameObject
{
protected:
	int type;
	float maxVx;
	float maxVy;
	bool friendly;
	int damage;
public:
	int getType() { return type; }
	CBullet();
	CBullet(float x, float y, int angle, bool friendly);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL) = 0;
	void Render();
	BOOLEAN outOfScreen();

	bool isBlocking() {
		return false;
	}
	virtual void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	void CollisionWithWallTurret(LPCOLLISIONEVENT e);
	void CollisionWithCannon(LPCOLLISIONEVENT e);
	void CollisionWithAircraft(LPCOLLISIONEVENT e);
	void CollisionWithFalcon(LPCOLLISIONEVENT e);
	void CollisionWithRifleman(LPCOLLISIONEVENT e);
	void CollisionWithScubaSoldier(LPCOLLISIONEVENT e);
	void CollisionWithSoldier(LPCOLLISIONEVENT e);
	void CollisionWithBill(LPCOLLISIONEVENT e);
	void CollisionWithBoss1Shield(LPCOLLISIONEVENT e);
	void CollisionWithBoss1Gun(LPCOLLISIONEVENT e);
	~CBullet() {

	}
};
typedef CBullet* LPBULLET;

