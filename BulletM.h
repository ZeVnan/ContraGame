#pragma once
#include "Bullet.h"
#define BULLET_M_TIME 70
class CBulletM :public CBullet {
private:
	int lastBulletTime;
public:
	DWORD shootTime;
	CBulletM(float x, float y, int angle);
	void Update(DWORD dt);
};
typedef CBulletM* LPBULLETM;