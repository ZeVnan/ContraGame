#include "BulletBoss1.h"
CBulletBoss1::CBulletBoss1(float x, float y, int angle, bool friendly) :CBullet::CBullet(x, y, angle, friendly) {
	this->type = BULLET_ANI_BOSS1;
	this->damage = 10;
	ay = BULLET_BOSS1_GRAVITY;
	vy = maxVy;
}
void CBulletBoss1::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vx = maxVx;
	vy += ay;
	CCollision::GetInstance()->Process(this, coObjects, dt);
}
void CBulletBoss1::CreateBox(DWORD dt) {
	bbox.left = x - BULLET_BOSS1_BOX_WIDTH / 2;
	bbox.top = y - BULLET_BOSS1_BOX_HEIGHT / 2;
	bbox.right = x + BULLET_BOSS1_BOX_WIDTH / 2;
	bbox.bottom = y + BULLET_BOSS1_BOX_HEIGHT / 2;
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}