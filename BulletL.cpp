#include "BulletL.h"

CBulletL::CBulletL(float x, float y, int angle, int turn) : CBullet::CBullet(x, y, angle) {
	type = BULLET_ANI_LASER;
	waitTime = turn * BULLET_L_WAITTIME;
	this->angle = angle;
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
void CBulletL::Render(){
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	switch (angle) {
	case 45:
		aniId = BULLET_ANI_LASER_45;
		break;
	case 135:
		aniId = BULLET_ANI_LASER_135;
		break;
	case 225:
		aniId = BULLET_ANI_LASER_225;
		break;
	case 315:
		aniId = BULLET_ANI_LASER_315;
		break;
	case 90:
		aniId = BULLET_ANI_LASER_90;
		break;
	case 270:
		aniId = BULLET_ANI_LASER_90;
		break;
	case 0:
		aniId = BULLET_ANI_LASER;
		break;
	case 180:
		aniId = BULLET_ANI_LASER;
		break;
	}
	animations->Get(aniId)->Render(x, y);
}