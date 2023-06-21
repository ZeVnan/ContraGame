#include "BulletL.h"

CBulletL::CBulletL(float x, float y, float angle, int turn, bool friendly) : CBullet::CBullet(x, y, angle, friendly) {
	type = BULLET_ANI_LASER;
	waitTime = turn * BULLET_L_WAITTIME;
	this->angle = angle;
	this->damage = 15;
}
void CBulletL::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (waitTime > 0) {
		waitTime -= dt;
	}
	else {
		waitTime = 0;
		vx = maxVx;
		vy = maxVy;
	}
	CCollision::GetInstance()->Process(this, coObjects, dt);
}
void CBulletL::Render(){
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	switch ((int)angle) {
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
void CBulletL::CreateBox(DWORD dt) {
	if (angle == 0 || angle == 180) {
		bbox.left = x - BULLET_L_BOX_WIDTH_1 / 2;
		bbox.top = y + BULLET_L_BOX_HEIGHT_1 / 2;
		bbox.right = x + BULLET_L_BOX_WIDTH_1 / 2;
		bbox.bottom = y - BULLET_L_BOX_HEIGHT_1 / 2;
	}
	else if (angle == 90 || angle == 270) {
		bbox.left = x - BULLET_L_BOX_WIDTH_2 / 2;
		bbox.top = y + BULLET_L_BOX_HEIGHT_2 / 2;
		bbox.right = x + BULLET_L_BOX_WIDTH_2 / 2;
		bbox.bottom = y - BULLET_L_BOX_HEIGHT_2 / 2;
	}
	else {
		bbox.left = x - BULLET_L_BOX_WIDTH_3 / 2;
		bbox.top = y + BULLET_L_BOX_HEIGHT_3 / 2;
		bbox.right = x + BULLET_L_BOX_WIDTH_3 / 2;
		bbox.bottom = y - BULLET_L_BOX_HEIGHT_3 / 2;
	}
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}