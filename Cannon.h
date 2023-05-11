#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"
#define CANNON_START_X 250
#define CANNON_START_Y 150

#define CANNON_APPEAR_TIME 600
#define CANNON_SWITCH_TIME 600

#define CANNON_STATE_LEFT 10
#define CANNON_STATE_LEFT_60 20
#define CANNON_STATE_LEFT_30 30
#define CANNON_STATE_APPEAR 40
#define CANNON_STATE_EXPLODE 50


#define CANNON_ANI_LEFT 14000
#define CANNON_ANI_LEFT_60 14001
#define CANNON_ANI_LEFT_30 14002
#define CANNON_ANI_APPEAR 14003

#define CANNON_BOX_WIDTH 64
#define CANNON_BOX_HEIGHT 64

class CCannon : public CGameObject
{
private:
	BOOLEAN isShooting;
	BOOLEAN isAppear;
	int HP;
	int timeLeft;
public:
	CCannon();
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
		return !isExploded;
	}
};
typedef CCannon* LPCANNON;