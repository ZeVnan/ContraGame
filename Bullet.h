#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define BULLET_SPEED 0.2f;

#define BULLET_ANI_NORMAL 10100
#define BULLET_ANI_NORMAL_BILL 10101

#define BULLET_ANI_FLAME 10110

#define BULLET_ANI_SPREAD 10120

#define BULLET_ANI_MACHINE 10130

#define BULLET_ANI_LASER 10140
#define BULLET_ANI_LASER_45 10141
#define BULLET_ANI_LASER_135 10142
#define BULLET_ANI_LASER_225 10143
#define BULLET_ANI_LASER_315 10144
#define BULLET_ANI_LASER_90 10145
#define BULLET_ANI_LASER_270 10146

class CBullet :public CGameObject
{
protected:
	int type;
	float maxVx;
	float maxVy;
	bool friendly;
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
	~CBullet() {

	}
};
typedef CBullet* LPBULLET;

