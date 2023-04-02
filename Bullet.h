#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define BULLET_SPEED 0.2f;

#define BULLET_ANI_NORMAL 0
#define BULLET_ANI_LASER 1
#define BULLET_ANI_FLAME 2
#define BULLET_ANI_SPREAD 3
#define BULLET_ANI_MACHINE 4

class CBullet :public CGameObject
{
private:
	int type;
	float maxVx = 0;
	float maxVy = 0;
public:
	CBullet(float x, float y, float vx, float vy, int nx, int ny, int type);
	void Update(DWORD dt);
	void Render();
	BOOLEAN outOfScreen();
};
typedef CBullet* LPBULLET;

