#include "BulletS.h"
void CBulletS::Update(DWORD dt) {
	vx = maxVx;
	vy = maxVy;

	x += vx * dt;
	y += vy * dt;
}
CBulletS::CBulletS(float x, float y, int angle):CBullet(x, y, angle) {
	this->type = BULLET_ANI_SPREAD;
}