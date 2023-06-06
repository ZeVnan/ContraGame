#pragma once
#include "Bullet.h"
#define BULLET_S_BOX_WIDTH 10
#define BULLET_S_BOX_HEIGHT 10
class CBulletS:public CBullet {

public:
	CBulletS(float x, float y, int angle, bool friendly);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void CreateBox(DWORD dt);
};
typedef CBulletS* LPBULLETS;