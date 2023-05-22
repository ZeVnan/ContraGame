#pragma once
#include "Bullet.h"
#define BULLET_M_TIME 70

#define BULLET_M_BOX_WIDTH 8
#define BULLET_M_BOX_HEIGHT 8
class CBulletM :public CBullet {
private:
	int lastBulletTime;
public:
	DWORD shootTime;
	CBulletM(float x, float y, int angle, bool friendly);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void CreateBox(DWORD dt);
};
typedef CBulletM* LPBULLETM;