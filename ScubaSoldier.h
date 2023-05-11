#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"

#define SCUBA_HIDING_TIME 1000
#define SCUBA_SHOOTING_TIME 1000

#define SCUBA_STATE_HIDING 0
#define SCUBA_STATE_SHOOTING 1
#define SCUBA_STATE_EXPLODE 2

#define SCUBA_ANI_HIDE_LEFT 10800
#define SCUBA_ANI_HIDE_RIGHT 10801
#define SCUBA_ANI_SHOOT_LEFT 10810
#define SCUBA_ANI_SHOOT_RIGHT 10811

#define SCUBA_BOX_HIDE_WIDTH	30
#define SCUBA_BOX_HIDE_HEIGHT	30
#define SCUBA_BOX_SHOOT_WIDTH	30
#define SCUBA_BOX_SHOOT_HEIGHT	60

class CScubaSoldier : public CGameObject
{
private:
	BOOLEAN isHiding;
	BOOLEAN isShooting;
	int timeleft;
public:
	CScubaSoldier(float x, float y);

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	bool isBlocking() { return false; }
	bool isCollidable() { return !isExploded; }
};
typedef CScubaSoldier* LPSCUBA;

