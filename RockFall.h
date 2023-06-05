#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"

#define ROCKFALL_SPEED_Y 0.2f
#define ROCKFALL_GRAVITY -0.002f
#define ROCKFALL_READY_TIME 2000
#define ROCKFALL_ACTIVE_RADIUS 300

#define ROCKFALL_STATE_NORMAL 0
#define ROCKFALL_STATE_FALLING 1

#define ROCKFALL_ANI_NORMAL		30000
#define ROCKFALL_ANI_FALLING	30001

#define ROCKFALL_BBOX_WIDTH 46
#define ROCKFALL_BBOX_HEIGHT 52

class CRockFall : public CGameObject
{
private:
	BOOLEAN isFalling;
	BOOLEAN isActivated;
	int timeLeft;
	float ay;
public:
	CRockFall(float x, float y);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int state);
	
	BOOLEAN outOfScreen();
	void watchBill();

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	bool isBlocking() { return false; }
	bool isCollidable() { return true; }
	void CollisionWith(LPCOLLISIONEVENT e);
	void CollisionWithGrass(LPCOLLISIONEVENT e);
	void CollisionWithBill(LPCOLLISIONEVENT e);
};
typedef CRockFall* LPROCKFALL;