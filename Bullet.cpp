#include "Bullet.h"
void CBullet::Update(DWORD dt) {
	vx = maxVx;
	vy = maxVy;

	x += vx * dt;
	y += vy * dt;
}
void CBullet::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = this->type;
	animations->Get(aniId)->Render(x, y);
}
BOOLEAN CBullet::outOfScreen() {
	if (this->x > 320 || this->x < 0 || this->y > 240 || this->y < 0)
		return true;
	return false;
}
CBullet::CBullet(float x, float y, float vx, float vy, int nx, int ny, int type) {
	this->x = x;
	this->y = y;
	this->type = type;

	if (vy == 0) {
		if (vx == 0) {
			if (ny == 1) {
				maxVy = -BULLET_SPEED;
				maxVx = 0;
			}
			else {
				maxVy = 0;
				maxVx = nx * BULLET_SPEED;
			}
		}
		else {
			maxVx = nx * BULLET_SPEED;
			maxVy = -ny * BULLET_SPEED;
		}
	}
	else {
		int a;
		if (vx == 0)
			a = 0;
		else
			a = nx;
		maxVx = a * BULLET_SPEED;
		maxVy = -ny * BULLET_SPEED;
		if (ny == 0)
			maxVx = nx * BULLET_SPEED;
	}
}