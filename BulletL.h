#pragma once
#include "Bullet.h"

#define BULLET_L_WAITTIME 50
class CBulletL:public CBullet
{
private:
	int waitTime;
public:
	CBulletL(float x, float y, int angle, int turn);
	void Update(DWORD dt);
};
typedef CBulletL* LPBULLETL;
