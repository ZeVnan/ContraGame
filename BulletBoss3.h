#pragma once
#include "Bullet.h"
#define BULLET_BOSS3_BOX_WIDTH 30
#define BULLET_BOSS3_BOX_HEIGHT 30
class CBulletBoss3 : public CBullet
{
public:
	CBulletBoss3(float x, float y, int angle, bool friendly);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void CreateBox(DWORD dt);
};
typedef CBulletBoss3* LPBULLETBOSS3;
