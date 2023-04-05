#include "BulletL.h"

CBulletL::CBulletL(float x, float y, int angle, int turn) : CBullet::CBullet(x, y, angle) {
	type = BULLET_ANI_LASER;
	waitTime = turn * BULLET_L_WAITTIME;
}
void CBulletL::Update(DWORD dt) {
	if (waitTime > 0) {
		waitTime -= dt;
	}
	else {
		waitTime = 0;
		vx = maxVx;
		vy = maxVy;
	}
	x += vx * dt;
	y += vy * dt;
}