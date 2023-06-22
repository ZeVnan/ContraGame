#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "BulletN.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"
#define CANNON_START_X 250
#define CANNON_START_Y 150
#define CANNON_ACTIVE_RADIUS 300

#define CANNON_APPEAR_TIME 600
#define CANNON_RELOAD_TIME 2000
#define CANNON_SHOOT_TIME 70
#define CANNON_WAVE_BULLET 3

#define CANNON_STATE_180 10
#define CANNON_STATE_150 20
#define CANNON_STATE_120 30
#define CANNON_STATE_APPEAR 40
#define CANNON_STATE_EXPLODE 50


#define CANNON_ANI_180 14000
#define CANNON_ANI_150 14001
#define CANNON_ANI_120 14002
#define CANNON_ANI_APPEAR 14003


#define CANNON_BOX_WIDTH 64
#define CANNON_BOX_HEIGHT 64

class CCannon : public CGameObject
{
private:
	bool isShooting;
	bool isAppear; //hoat dong nhu isHiding
	bool isActivated;
	int HP;

	vector<LPBULLET> bullets;
	int waveLeft = CANNON_WAVE_BULLET;
	int timeLeft;
public:
	CCannon(float x, float y);

	void TakeDamage(int damage) {
		this->HP -= damage;
	}

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	bool isBlocking() { return false; }
	bool isCollidable() {
		return isAppear;
	}
	void WatchBill();
	int CalculateBillAngle();
	void AddBullet();
	LPBULLET ShootNormalBullet(float angle);
	void UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void RenderBullet();
};
typedef CCannon* LPCANNON;