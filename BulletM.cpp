#include "BulletM.h"
CBulletM::CBulletM(float x, float y, int angle, bool friendly) :CBullet::CBullet(x, y, angle, friendly) {
	this->type = BULLET_ANI_MACHINE;
}
void CBulletM::Update(DWORD dt) {
	vx = maxVx;
	vy = maxVy;
	x += vx * dt;
	y += vy * dt;
}