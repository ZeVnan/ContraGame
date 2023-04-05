#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define BULLET_SPEED 0.2f;

#define BULLET_ANI_NORMAL 0
#define BULLET_ANI_FLAME 1
#define BULLET_ANI_SPREAD 2
#define BULLET_ANI_MACHINE 3
#define BULLET_ANI_LASER 4

class CBullet :public CGameObject
{
protected:
	int type;
	float maxVx;
	float maxVy;
public:
	int getType() { return type; }
	CBullet();
	CBullet(float x, float y, int angle);
	virtual void Update(DWORD dt) = 0;
	void Render();
	BOOLEAN outOfScreen();
};
typedef CBullet* LPBULLET;

