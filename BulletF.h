#pragma once
#include "Bullet.h"

#define BULLET_F_RADIUS 20.0f
#define BULLET_F_SPEED_R 0.8f

#define BULLET_F_BOX_WIDTH 14
#define BULLET_F_BOX_HEIGHT 14
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
	void NoCollision(DWORD dt);
	void CreateBox(DWORD dt);
};
typedef CBulletF* LPBULLETF;