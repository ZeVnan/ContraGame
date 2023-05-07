#pragma once
#include "Bullet.h"

#define BULLET_F_RADIUS 15.0f
#define BULLET_F_SPEED_R 0.4f

class CBulletF :public CBullet {
private:
	float degree;
	float parameter;
	float vr;
	float centerx;
	float centery;
public:
	CBulletF(float x, float y, int angle, bool friendly);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
};
typedef CBulletF* LPBULLETF;