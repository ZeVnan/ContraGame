#include "BulletN.h"

CBulletN::CBulletN(float x, float y, int angle, bool friendly) :CBullet::CBullet(x, y, angle, friendly) {
	if (friendly == true) {
		this->type = BULLET_ANI_NORMAL_BILL;
	}
	else {
		this->type = BULLET_ANI_NORMAL;
	}
}
void CBulletN::Update(DWORD dt) {
	vx = maxVx;
	vy = maxVy;
	x += vx * dt;
	y += vy * dt;
}