#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"
#define CANNON_START_X 250
#define CANNON_START_Y 150

#define CANNON_APPEAR_TIME 600
#define CANNON_SWITCH_TIME 300

#define CANNON_STATE_LEFT 10
#define CANNON_STATE_LEFT_60 20
#define CANNON_STATE_LEFT_30 30
#define CANNON_STATE_APPEAR 40


#define CANNON_ANI_LEFT 10400
#define CANNON_ANI_LEFT_60 10401
#define CANNON_ANI_LEFT_30 10402
#define CANNON_ANI_APPEAR 10403

#define CANNON_BOX_WIDTH 32
#define CANNON_BOX_HEIGHT 32

class CCannon : public CGameObject
{
private:
	BOOLEAN isShooting;
	BOOLEAN isAppear;
	int timeLeft;
public:
	CCannon();
	CCannon(float x, float y);

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
};

