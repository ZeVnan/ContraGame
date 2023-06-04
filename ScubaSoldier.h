#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"
#include "Bullet.h"
#include "BulletN.h"

#define SCUBA_HIDING_TIME 2000
#define SCUBA_SHOOTING_TIME 2000

#define SCUBA_STATE_HIDING 0
#define SCUBA_STATE_SHOOTING 1
#define SCUBA_STATE_EXPLODE 2

#define SCUBA_ANI_HIDE_LEFT 18000
#define SCUBA_ANI_HIDE_RIGHT 18001
#define SCUBA_ANI_SHOOT_LEFT 18010
#define SCUBA_ANI_SHOOT_RIGHT 18011

#define SCUBA_BOX_HIDE_WIDTH	30
#define SCUBA_BOX_HIDE_HEIGHT	30
#define SCUBA_BOX_SHOOT_WIDTH	30
#define SCUBA_BOX_SHOOT_HEIGHT	60

class CScubaSoldier : public CGameObject
{
private:
	BOOLEAN isHiding;
	BOOLEAN isShooting;
	BOOLEAN isActivated;
	int timeleft;
	
	int waveLeft = 1;
	vector<vector<LPBULLET>>waveContainer;
public:
	CScubaSoldier(float x, float y);

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void watchBill();
	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	bool isBlocking() { return false; }
	bool isCollidable() { return !isHiding; }

	vector<LPBULLET> ShootNormalBullet(int angle);
	void AddBullet();
	void UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void RenderBullet();
};
typedef CScubaSoldier* LPSCUBA;

