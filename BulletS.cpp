#include "BulletS.h"
void CBulletS::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vx = maxVx;
	vy = maxVy;

	x += vx * dt;
	y += vy * dt;
}
CBulletS::CBulletS(float x, float y, int angle, bool friendly):CBullet(x, y, angle, friendly) {
	this->type = BULLET_ANI_SPREAD;
}