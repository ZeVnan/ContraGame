#include "BulletF.h"

CBulletF::CBulletF(float x, float y, float angle, bool friendly) : CBullet::CBullet(x, y, angle, friendly) {
	type = BULLET_ANI_FLAME;
	parameter = 2 * BULLET_F_RADIUS * 3.14159f;
	vr = BULLET_F_SPEED_R;
	degree = 0;
	centerx = x;
	centery = y;
	damage = 15;
	vx = maxVx;
	vy = maxVy;
}
void CBulletF::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	CCollision::GetInstance()->Process(this, coObjects, dt);
}
void CBulletF::NoCollision(DWORD dt) {
	degree += (vr * dt) / parameter * 360;
	if (degree >= 360)
		degree -= 360;
	float rad = 3.14159f / 180 * degree; 
	centerx += vx * dt;
	centery += vy * dt;
	x = centerx + cos(rad) * BULLET_F_RADIUS;
	y = centery + sin(rad) * BULLET_F_RADIUS;
}
void CBulletF::CreateBox(DWORD dt) {
	bbox.left = x - BULLET_F_BOX_WIDTH / 2;
	bbox.top = y + BULLET_F_BOX_HEIGHT / 2;
	bbox.right = x + BULLET_F_BOX_WIDTH / 2;
	bbox.bottom = y - BULLET_F_BOX_HEIGHT / 2;
	float vr_degree = degree + 90.0f;
	float vr_rad = 3.14159f / 180 * vr_degree;
	bbox.vpf_x = (cos(vr_rad) * vr + vx) * dt;
	bbox.vpf_y = (sin(vr_rad) * vr + vy) * dt;
}