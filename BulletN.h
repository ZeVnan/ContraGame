#pragma once
#include "Bullet.h"
#define BULLET_N_BOX_WIDTH 4
#define BULLET_N_BOX_HEIGHT 4
class CBulletN :public CBullet {
public:
	CBulletN(float x, float y, int angle, bool friendly);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void CreateBox(DWORD dt);
};
typedef CBulletN* LPBULLETN;