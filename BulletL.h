#pragma once
#include "Bullet.h"

#define BULLET_L_WAITTIME 50
class CBulletL:public CBullet
{
private:
	int waitTime;
	int angle;
public:
	CBulletL(float x, float y, int angle, int turn, bool friendly);
	void Update(DWORD dt);
	void Render();
};
typedef CBulletL* LPBULLETL;
