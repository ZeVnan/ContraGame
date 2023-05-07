#include "BulletN.h"

CBulletN::CBulletN(float x, float y, int angle, bool friendly) :CBullet::CBullet(x, y, angle, friendly) {
	if (friendly == true) {
		this->type = BULLET_ANI_NORMAL_BILL;
	}
	else {
		this->type = BULLET_ANI_NORMAL;
	}
}
void CBulletN::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vx = maxVx;
	vy = maxVy;
	x += vx * dt;
	y += vy * dt;
	CCollision::GetInstance()->Process(this, coObjects, dt);
}
void CBulletN::CreateBox(DWORD dt) {
	bbox.left = x - BOX_WIDTH / 2;
	bbox.top = y + BOX_HEIGHT / 2;
	bbox.right = x + BOX_WIDTH / 2;
	bbox.bottom = y - BOX_HEIGHT / 2;
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}