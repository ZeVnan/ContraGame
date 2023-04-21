#pragma once
#include "GameObject.h"
#include "Bullet.h"

#define RIFLEMAN_START_X 180.0f
#define RIFLEMAN_START_Y 10.0f
#define RIFLEMAN_GRAVITY 0.0004f

#pragma region
#define RIFLEMAN_STATE_LEFT 0
#define RIFLEMAN_STATE_RIGHT 1

#define RIFLEMAN_STATE_UP 10
#define RIFLEMAN_STATE_DOWN 20
#define RIFLEMAN_STATE_NORMAL 30

#define RIFLEMAN_STATE_HIDING 70

#define RIFLEMAN_STATE_SHOOT 80
#define RIFLEMAN_STATE_SHOOT_RELEASE 81

#define RIFLEMAN_STATE_EXPOSE 90
#define RIFLEMAN_STATE_REHIDE 91

#define RIFLEMAN_STATE_DEAD 100

#pragma region
#define RIFLEMAN_ANI_NORMAL_LEFT 400
#define RIFLEMAN_ANI_NORMAL_RIGHT 401

#define RIFLEMAN_ANI_SHOOT_LEFT 410
#define RIFLEMAN_ANI_SHOOT_RIGHT 411

#define RIFLEMAN_ANI_AIM_UP_LEFT 420
#define RIFLEMAN_ANI_AIM_UP_RIGHT 421

#define RIFLEMAN_ANI_AIM_DOWN_LEFT 440
#define RIFLEMAN_ANI_AIM_DOWN_RIGHT 441

#define RIFLEMAN_ANI_HIDE_LEFT 450
#define RIFLEMAN_ANI_HIDE_RIGHT 451

#define RIFLEMAN_ANI_REHIDE_LEFT 452
#define RIFLEMAN_ANI_REHIDE_RIGHT 453

#define RIFLEMAN_ANI_EXPOSE_LEFT 460
#define RIFLEMAN_ANI_EXPOSE_RIGHT 461

#define RIFLEMAN_SWITCH_TIME 300
class Rifleman : public CGameObject
{
private:
	BOOLEAN isShooting;
	BOOLEAN isHiding;
	vector<LPBULLET> bullets;
	float gunx;
	float guny;
	int ny; // down - -1, normal - 0, up - 1
	float timeLeft;
public:
	Rifleman();
	Rifleman(float x, float y);

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);
};

