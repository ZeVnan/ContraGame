#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#include "BulletN.h"

#include "debug.h"

#define RIFLEMAN_START_X 180.0f
#define RIFLEMAN_START_Y 10.0f
#define RIFLEMAN_ACTIVE_RADIUS 250

#pragma region
#define RIFLEMAN_STATE_EXPOSE 0
#define RIFLEMAN_STATE_HIDE 1

#define RIFLEMAN_STATE_EXPLODE 10

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

#define RIFLEMAN_RELOAD_TIME 2000

//Áp dụng được cho toàn bộ animation khi đứng của rifleman
#define RIFLEMAN_BOX_NORMAL_HEIGHT	76
#define RIFLEMAN_BOX_NORMAL_WIDTH	46

#define RIFLEMAN_BOX_HIDE_WIDTH		46
#define RIFLEMAN_BOX_HIDE_HEIGHT	32


class Rifleman : public CGameObject
{
private:
	bool isShooting;
	bool isHiding;
	bool isOnBush;
	vector<LPBULLET> bullets;
	float gunx;
	float guny;
	int ny; // down - -1, normal - 0, up - 1
	float timeleft;
	int waveLeft;
	float angle;
public:
	Rifleman(float x, float y, bool isOnBush);
	void WatchBill();

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	bool isBlocking() { return false; }
	bool isCollidable() { return !isExploded; }
	bool IsHiding() { return isHiding; }

	LPBULLET ShootNormalBullet(float angle);
	void AddBullet();
	void UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void RenderBullet();
};
typedef Rifleman* LPRIFLEMAN;
