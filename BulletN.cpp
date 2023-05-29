#include "BulletN.h"

CBulletN::CBulletN(float x, float y, int angle, bool friendly) :CBullet::CBullet(x, y, angle, friendly) {
	if (friendly == true) {
		this->type = BULLET_ANI_NORMAL_BILL;
	}
	else {
		this->type = BULLET_ANI_NORMAL;
	}
	this->damage = 10;
	vx = maxVx;
	vy = maxVy;
}
void CBulletN::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	CCollision::GetInstance()->Process(this, coObjects, dt);
}
void CBulletN::CreateBox(DWORD dt) {
	bbox.left = x - BULLET_N_BOX_WIDTH / 2;
	bbox.top = y - BULLET_N_BOX_HEIGHT / 2;
	bbox.right = x + BULLET_N_BOX_WIDTH / 2;
	bbox.bottom = y + BULLET_N_BOX_HEIGHT / 2;
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}