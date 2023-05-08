#pragma once
#include "Bullet.h"

#define BULLET_L_WAITTIME 50

#define BULLET_L_BOX_WIDTH_1 15
#define BULLET_L_BOX_HEIGHT_1 5

#define BULLET_L_BOX_WIDTH_2 5
#define BULLET_L_BOX_HEIGHT_2 15

#define BULLET_L_BOX_WIDTH_3 15
#define BULLET_L_BOX_HEIGHT_3 15
class CBulletL:public CBullet
{
private:
	int waitTime;
	int angle;
public:
	CBulletL(float x, float y, int angle, int turn, bool friendly);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void CreateBox(DWORD dt);
};
typedef CBulletL* LPBULLETL;
