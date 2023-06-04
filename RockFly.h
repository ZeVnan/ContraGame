#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"

#define ROCKFLY_ANI 20004

#define ROCKFLY_FLY_SPEED 0.1f
#define ROCKFLY_FLY_TIME 2000

#define ROCKFLY_BOX_WIDTH 66
#define ROCKFLY_BOX_HEIGHT 62

class CRockFly :public CGameObject
{
private:
	BOOLEAN turn;
	int timeLeft;
public:
	CRockFly(float x, float y);

	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	bool isBlocking() { return false; }
	bool isCollidable() { return !isExploded; }
};
typedef CRockFly* LPROCKFLY;