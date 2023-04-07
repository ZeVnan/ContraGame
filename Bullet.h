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
#define BULLET_ANI_LASER_45 5
#define BULLET_ANI_LASER_135 6
#define BULLET_ANI_LASER_225 7
#define BULLET_ANI_LASER_315 8
#define BULLET_ANI_LASER_90 9
#define BULLET_ANI_LASER_270 10

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

