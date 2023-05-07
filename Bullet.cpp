#include "Bullet.h"
#include "WallTurret.h"
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
void CBullet::NoCollision(DWORD dt) {
	x += vx * dt;
	y += vy * dt;
}
void CBullet::CollisionWith(LPCOLLISIONEVENT e) {
	if (dynamic_cast<LPWALLTURRET>(e->dest_obj)) {
		CollisionWithWallTurret(e);
	}
}
void CBullet::CollisionWithWallTurret(LPCOLLISIONEVENT e) {
	if (friendly == false)
		return;
	(LPWALLTURRET(e->dest_obj))->SetState(WTURRET_STATE_EXPLODE);
	e->src_obj->Delete();
}