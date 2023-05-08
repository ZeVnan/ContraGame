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
#define RIFLEMAN_STATE_DOWN 11
#define RIFLEMAN_STATE_NORMAL 12

#define RIFLEMAN_STATE_HIDING 20

#define RIFLEMAN_STATE_SHOOT 30
#define RIFLEMAN_STATE_SHOOT_RELEASE 31

#define RIFLEMAN_STATE_EXPOSE 40
#define RIFLEMAN_STATE_REHIDE 41

#define RIFLEMAN_STATE_EXPLODE 50

#pragma region
#define RIFLEMAN_ANI_NORMAL_LEFT 10500
#define RIFLEMAN_ANI_NORMAL_RIGHT 10501

#define RIFLEMAN_ANI_SHOOT_LEFT 10510
#define RIFLEMAN_ANI_SHOOT_RIGHT 10511

#define RIFLEMAN_ANI_AIM_UP_LEFT 10520
#define RIFLEMAN_ANI_AIM_UP_RIGHT 10521

#define RIFLEMAN_ANI_AIM_DOWN_LEFT 10530
#define RIFLEMAN_ANI_AIM_DOWN_RIGHT 10531

#define RIFLEMAN_ANI_HIDE_LEFT 10540
#define RIFLEMAN_ANI_HIDE_RIGHT 10541

#define RIFLEMAN_ANI_REHIDE_LEFT 10550
#define RIFLEMAN_ANI_REHIDE_RIGHT 10551

#define RIFLEMAN_ANI_EXPOSE_LEFT 10560
#define RIFLEMAN_ANI_EXPOSE_RIGHT 10561

#define RIFLEMAN_SWITCH_TIME 300

//Áp dụng được cho toàn bộ animation khi đứng của rifleman
#define RIFLEMAN_BOX_NORMAL_HEIGHT	38
#define RIFLEMAN_BOX_NORMAL_WIDTH	23

#define RIFLEMAN_BOX_HIDE_WIDTH		23
#define RIFLEMAN_BOX_HIDE_HEIGHT	16


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

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	bool isBlocking() { return false; }
	bool isCollidable() { return !isExploded; }
};
typedef Rifleman* LPRIFLEMAN;
