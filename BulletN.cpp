#include "BulletN.h"

CBulletN::CBulletN(float x, float y, int angle) :CBullet::CBullet(x, y, angle) {
	this->type = BULLET_ANI_NORMAL;
}
void CBulletN::Update(DWORD dt) {
	vx = maxVx;
	vy = maxVy;
	x += vx * dt;
	y += vy * dt;
}