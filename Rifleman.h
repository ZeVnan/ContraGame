#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#include "BulletN.h"

#include "debug.h"

#include "Bill.h"

extern CBill* bill;


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
#define RIFLEMAN_ANI_NORMAL_LEFT 15000
#define RIFLEMAN_ANI_NORMAL_RIGHT 15001

#define RIFLEMAN_ANI_SHOOT_LEFT 15010
#define RIFLEMAN_ANI_SHOOT_RIGHT 15011

#define RIFLEMAN_ANI_AIM_UP_LEFT 15020
#define RIFLEMAN_ANI_AIM_UP_RIGHT 15021

#define RIFLEMAN_ANI_AIM_DOWN_LEFT 15030
#define RIFLEMAN_ANI_AIM_DOWN_RIGHT 15031

#define RIFLEMAN_ANI_HIDE_LEFT 15040
#define RIFLEMAN_ANI_HIDE_RIGHT 15041

#define RIFLEMAN_ANI_REHIDE_LEFT 15050
#define RIFLEMAN_ANI_REHIDE_RIGHT 15051

#define RIFLEMAN_ANI_EXPOSE_LEFT 15060
#define RIFLEMAN_ANI_EXPOSE_RIGHT 15061

#define RIFLEMAN_SWITCH_TIME 2000

//Áp dụng được cho toàn bộ animation khi đứng của rifleman
#define RIFLEMAN_BOX_NORMAL_HEIGHT	76
#define RIFLEMAN_BOX_NORMAL_WIDTH	46

#define RIFLEMAN_BOX_HIDE_WIDTH		46
#define RIFLEMAN_BOX_HIDE_HEIGHT	32


class Rifleman : public CGameObject
{
private:
	BOOLEAN isShooting;
	BOOLEAN isHiding;
	vector<vector<LPBULLET>> waveContainer;
	float gunx;
	float guny;
	int ny; // down - -1, normal - 0, up - 1
	float timeleft;
	int waveLeft;
public:
	Rifleman();
	Rifleman(float x, float y);
	void WatchBill();

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	bool isBlocking() { return false; }
	bool isCollidable() { return !isExploded; }

	int CalculateAngle();
	vector<LPBULLET> ShootNormalBullet(int angle);
	void AddBullet();
	void UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void RenderBullet();
};
typedef Rifleman* LPRIFLEMAN;
