#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"
#define BILL_RUN_SPEED 0.1f

#define BILL_JUMP_SPEED_Y 0.2f

#define BILL_GRAVITY 0.0004f

#define BILL_STATE_NORMAL 0

#define BILL_STATE_RUN_RIGHT 10
#define BILL_STATE_RUN_LEFT 11

#define BILL_STATE_JUMP 20
#define BILL_STATE_JUMP_RELEASE 21

#define BILL_STATE_DOWN 30
#define BILL_STATE_DOWN_RELEASE 31

#define BILL_STATE_UP 40
#define BILL_STATE_UP_RELEASE 41

#define BILL_STATE_SHOT 50
#define BILL_STATE_SHOT_RELEASE 51

#define BILL_STATE_SWIM_BEGIN 60
#define BILL_STATE_SWIM 61
#define BILL_STATE_DIVING 62

#define BILL_STATE_DEAD 70


#pragma region
#define BILL_ANI_NORMAL_RIGHT 100
#define BILL_ANI_NORMAL_LEFT 101

#define BILL_ANI_RUN_RIGHT 200
#define BILL_ANI_RUN_LEFT 201

#define BILL_ANI_JUMP_RIGHT 300
#define BILL_ANI_JUMP_LEFT 301

#define BILL_ANI_LAYDOWN_RIGHT 400
#define BILL_ANI_LAYDOWN_LEFT 401

#define BILL_ANI_SHOT_UPRIGHT 500
#define BILL_ANI_SHOT_UPLEFT 501
#define BILL_ANI_SHOT_DOWNRIGHT 502
#define BILL_ANI_SHOT_DOWNLEFT 503
#define BILL_ANI_SHOT_UP_RIGHT 504
#define BILL_ANI_SHOT_UP_LEFT 505
#define BILL_ANI_SHOT_RIGHT 506
#define BILL_ANI_SHOT_LEFT 507

#define GROUND_Y 160.0f

#define BILL_LAY_HEIGHT_ADJUST 4.0f
class CBill :public CGameObject
{
	BOOLEAN isLaying;
	BOOLEAN isShooting;
	int updown = 0;    //normal:0, up:1, down:-1
	float maxVx;
public:
	CBill(float x, float y) : CGameObject(x, y)
	{
		isLaying = false;
		maxVx = 0.0f;
	}
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};


