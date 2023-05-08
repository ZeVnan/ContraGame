#include "BulletS.h"
void CBulletS::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vx = maxVx;
	vy = maxVy;
	CCollision::GetInstance()->Process(this, coObjects, dt);
	damage = 15;
}
CBulletS::CBulletS(float x, float y, int angle, bool friendly):CBullet(x, y, angle, friendly) {
	this->type = BULLET_ANI_SPREAD;
}
void CBulletS::CreateBox(DWORD dt) {
	bbox.left = x - BULLET_S_BOX_WIDTH / 2;
	bbox.top = y + BULLET_S_BOX_HEIGHT / 2;
	bbox.right = x + BULLET_S_BOX_WIDTH / 2;
	bbox.bottom = y - BULLET_S_BOX_HEIGHT / 2;
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}