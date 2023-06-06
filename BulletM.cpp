#include "BulletM.h"
CBulletM::CBulletM(float x, float y, int angle, bool friendly) :CBullet::CBullet(x, y, angle, friendly) {
	this->type = BULLET_ANI_MACHINE;
	damage = 15;
	vx = maxVx;
	vy = maxVy;
}
void CBulletM::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	CCollision::GetInstance()->Process(this, coObjects, dt);
}
void CBulletM::CreateBox(DWORD dt) {
	bbox.left = x - BULLET_M_BOX_WIDTH / 2;
	bbox.top = y + BULLET_M_BOX_HEIGHT / 2;
	bbox.right = x + BULLET_M_BOX_WIDTH / 2;
	bbox.bottom = y - BULLET_M_BOX_HEIGHT / 2;
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}
