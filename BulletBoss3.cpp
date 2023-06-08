#include "BulletBoss3.h"
CBulletBoss3::CBulletBoss3(float x, float y, int angle, bool friendly) : CBullet(x, y, angle, friendly) {
	this->type = BULLET_ANI_BOSS3;
	damage = 10;
	vx = maxVx;
	vy = maxVy;
}
void CBulletBoss3::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	CCollision::GetInstance()->Process(this, coObjects, dt);
}
void CBulletBoss3::CreateBox(DWORD dt) {
	bbox.left = x - BULLET_BOSS3_BOX_WIDTH / 2;
	bbox.top = y + BULLET_BOSS3_BOX_HEIGHT / 2;
	bbox.right = x + BULLET_BOSS3_BOX_WIDTH / 2;
	bbox.bottom = y - BULLET_BOSS3_BOX_HEIGHT / 2;
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}