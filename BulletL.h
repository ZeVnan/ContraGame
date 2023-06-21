#pragma once
#include "Bullet.h"

#define BULLET_L_WAITTIME 50

#define BULLET_L_BOX_WIDTH_1 30
#define BULLET_L_BOX_HEIGHT_1 10

#define BULLET_L_BOX_WIDTH_2 10
#define BULLET_L_BOX_HEIGHT_2 30

#define BULLET_L_BOX_WIDTH_3 30
#define BULLET_L_BOX_HEIGHT_3 30
class CBulletL:public CBullet
{
private:
	int waitTime;
	float angle;
public:
	CBulletL(float x, float y, float angle, int turn, bool friendly);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void CreateBox(DWORD dt);
};
typedef CBulletL* LPBULLETL;
