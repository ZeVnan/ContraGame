#pragma once
#include "GameObject.h"
#include "Animations.h"

#include "debug.h"

#define BOSS1SHIELD_ANI_NORMAL 40000
#define BOSS1SHIELD_ANI_AFTER_EXPLODE 40001

#define BOSS1SHIELD_STATE_NORMAL 0
#define BOSS1SHIELD_STATE_EXPLODE 1
#define BOSS1SHIELD_STATE_AFTER_EXPLODE 2


#define BOSS1SHIELD_BOX_WIDTH 46
#define BOSS1SHIELD_BOX_HEIGHT 60
class CBoss1Shield :public CGameObject
{
private:
	int HP;
	int timeLeft;
public:
	CBoss1Shield(float x, float y);
	void TakeDamage(int damage) {
		this->HP -= damage;
	}

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);

	bool isCollidable() { return !isExploded; }
	bool isBlocking() { return !isExploded; }
};
typedef CBoss1Shield* LPBOSS1SHIELD;
