#pragma once
#include "Bullet.h"

#define BULLET_BOSS1_GRAVITY -0.075f

#define BULLET_BOSS1_BOX_WIDTH 14
#define BULLET_BOSS1_BOX_HEIGHT 14
class CBulletBoss1 :public CBullet {
private:
	float ay;
public:
	CBulletBoss1(float x, float y, float angle, bool friendly);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void CreateBox(DWORD dt);

};