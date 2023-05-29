#include "BulletS.h"
CBulletS::CBulletS(float x, float y, int angle, bool friendly):CBullet(x, y, angle, friendly) {
	this->type = BULLET_ANI_SPREAD;
	damage = 15;
	vx = maxVx;
	vy = maxVy;
}
void CBulletS::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	
	CCollision::GetInstance()->Process(this, coObjects, dt);
}
void CBulletS::CreateBox(DWORD dt) {
	bbox.left = x - BULLET_S_BOX_WIDTH / 2;
	bbox.top = y - BULLET_S_BOX_HEIGHT / 2;
	bbox.right = x + BULLET_S_BOX_WIDTH / 2;
	bbox.bottom = y + BULLET_S_BOX_HEIGHT / 2;
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}