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
#define CANNON_STATE_APPEAR 99


#define CANNON_ANI_LEFT 300
#define CANNON_ANI_LEFT_60 301
#define CANNON_ANI_LEFT_30 302
#define CANNON_ANI_APPEAR 310

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
};

