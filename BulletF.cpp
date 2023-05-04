#include "BulletF.h"

CBulletF::CBulletF(float x, float y, int angle, bool friendly) : CBullet::CBullet(x, y, angle, friendly) {
	type = BULLET_ANI_FLAME;
	parameter = 2 * BULLET_F_RADIUS * 3.14159;
	vr = BULLET_F_SPEED_R;
	degree = 0;
	centerx = x;
	centery = y;
}
void CBulletF::Update(DWORD dt) {
	degree += (vr * dt) / parameter * 360;
	if (degree >= 360)
		degree -= 360;
	float rad = 3.14159 / 180 * degree;
	vx = maxVx;
	vy = maxVy;
	centerx += vx * dt;
	centery += vy * dt;
	x = centerx + cos(rad) * BULLET_F_RADIUS;
	y = centery + sin(rad) * BULLET_F_RADIUS;
}