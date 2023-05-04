#include "Bullet.h"
CBullet::CBullet() {
	this->type = -1;
	maxVx = 0;
	maxVy = 0;
	friendly = true;
}
CBullet::CBullet(float x, float y, int angle, bool friendly) : CBullet() {
	this->x = x;
	this->y = y;
	this->friendly = friendly;
	float radian = 3.14159 / 180 * angle;

	maxVx =cos(radian) * BULLET_SPEED;
	maxVy =sin(radian) * BULLET_SPEED;
}
BOOLEAN CBullet::outOfScreen() {
	float cx, cy;
	CGame::GetInstance()->GetCamera()->GetCamPos(cx, cy);
	if (x < (cx - CAM_WIDTH / 2) || x >(cx + CAM_WIDTH / 2) || y < (cy - CAM_HEIGHT / 2) || y >(cy + CAM_HEIGHT / 2))
		return true;
	return false;
}
void CBullet::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = this->type;
	animations->Get(aniId)->Render(x, y);
}