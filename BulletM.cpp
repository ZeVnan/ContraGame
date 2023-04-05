#include "BulletM.h"
CBulletM::CBulletM(float x, float y, int angle) :CBullet::CBullet(x, y, angle) {
	this->type = BULLET_ANI_MACHINE;
}
void CBulletM::Update(DWORD dt) {
	vx = maxVx;
	vy = maxVy;
	x += vx * dt;
	y += vy * dt;
}