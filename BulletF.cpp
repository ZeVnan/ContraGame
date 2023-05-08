#include "BulletF.h"

CBulletF::CBulletF(float x, float y, int angle, bool friendly) : CBullet::CBullet(x, y, angle, friendly) {
	type = BULLET_ANI_FLAME;
	parameter = 2 * BULLET_F_RADIUS * 3.14159;
	vr = BULLET_F_SPEED_R;
	degree = 0;
	centerx = x;
	centery = y;
	damage = 15;
}
void CBulletF::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vx = maxVx;
	vy = maxVy;
	CCollision::GetInstance()->Process(this, coObjects, dt);
}
void CBulletF::NoCollision(DWORD dt) {
	degree += (vr * dt) / parameter * 360;
	if (degree >= 360)
		degree -= 360;
	float rad = 3.14159 / 180 * degree; 
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
	int vr_degree = 0;
	if (degree >= 0 && degree < 90)
		vr_degree = 180 - (90 - degree);
	if (degree >= 90 && degree < 180)
		vr_degree = 180 + (degree - 90);
	if (degree >= 180 && degree < 270)
		vr_degree = 360 - (270 - degree);
	if (degree >= 270 && degree < 360)
		vr_degree = degree - 270;
	float vr_rad = 3.14159 / 180 * vr_degree;
	bbox.vpf_x = (cos(vr_rad) + vx) * dt;
	bbox.vpf_y = (sin(vr_rad) + vy) * dt;
}