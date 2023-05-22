#pragma once
#include "GameObject.h"
#include "Animations.h"

#define BOSS1GUN_STATE_NORMAL 0
#define BOSS1GUN_STATE_EXPLODE 1

#define BOSS1GUN_ANI_NORMAL 41000

#define BOSS1GUN_BOX_WIDTH 22
#define BOSS1GUN_BOX_HEIGHT 12
class CBoss1Gun : public CGameObject
{
private:
	int HP;
	int timeLeft;
public:
	CBoss1Gun(float x, float y);
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
typedef CBoss1Gun* LPBOSS1GUN;

