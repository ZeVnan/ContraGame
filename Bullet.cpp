#include "Bullet.h"
#include "WallTurret.h"
#include "Cannon.h"
#include "Rifleman.h"
#include "ScubaSoldier.h"
#include "Soldier.h"
#include "Aircraft.h"
#include "Falcon.h"

CBullet::CBullet() {
	this->type = -1;
	maxVx = 0;
	maxVy = 0;
	friendly = true;
	damage = 0;
}
CBullet::CBullet(float x, float y, int angle, bool friendly) : CBullet() {
	this->x = x;
	this->y = y;
	this->friendly = friendly;
	float radian = 3.14159 / 180 * angle;

	maxVx = cos(radian) * BULLET_SPEED;
	maxVy = sin(radian) * BULLET_SPEED;
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
	RenderBox();
}
void CBullet::NoCollision(DWORD dt) {
	x += vx * dt;
	y += vy * dt;
}
void CBullet::CollisionWith(LPCOLLISIONEVENT e) {
	if (dynamic_cast<LPWALLTURRET>(e->dest_obj)) {
		CollisionWithWallTurret(e);
		return;
	}
	if (dynamic_cast<LPCANNON>(e->dest_obj)) {
		CollisionWithCannon(e);
		return;
	}
	if (dynamic_cast<LPAIRCRAFT>(e->dest_obj)) {
		CollisionWithAircraft(e);
		return;
	}
	if (dynamic_cast<LPFALCON>(e->dest_obj)) {
		CollisionWithFalcon(e);
		return;
	}
	if (dynamic_cast<LPRIFLEMAN>(e->dest_obj)) {
		CollisionWithRifleman(e);
		return;
	}
	if (dynamic_cast<LPSCUBA>(e->dest_obj)) {
		CollisionWithScubaSoldier(e);
		return;
	}
	if (dynamic_cast<LPSOLDIER>(e->dest_obj)) {
		CollisionWithSoldier(e);
		return;
	}
	x += bbox.vpf_x;
	y += bbox.vpf_y;
}
//in-human collision
void CBullet::CollisionWithWallTurret(LPCOLLISIONEVENT e) {
	if (friendly == false || (LPWALLTURRET(e->dest_obj))->isCollidable() == false)
		return;
	(LPWALLTURRET(e->dest_obj))->TakeDamage(this->damage);
	e->src_obj->Delete();
}

void CBullet::CollisionWithCannon(LPCOLLISIONEVENT e) {
	if (friendly == false || (LPCANNON(e->dest_obj))->isCollidable() == false)
		return;
	(LPCANNON(e->dest_obj))->TakeDamage(this->damage);
	e->src_obj->Delete();
}

void CBullet::CollisionWithAircraft(LPCOLLISIONEVENT e) {
	if (friendly == false || (LPAIRCRAFT(e->dest_obj))->isCollidable() == false)
		return;
	(LPAIRCRAFT(e->dest_obj))->SetState(AIRCRAFT_STATE_EXPLODE);
	e->src_obj->Delete();
}

void CBullet::CollisionWithFalcon(LPCOLLISIONEVENT e)
{
	if (friendly == false || (LPFALCON(e->dest_obj))->isCollidable() == false)
		return;
	(LPFALCON(e->dest_obj))->SetState(FALCON_STATE_EXPLODE);
	e->src_obj->Delete();
}

//human collision
void CBullet::CollisionWithRifleman(LPCOLLISIONEVENT e) {
	if (friendly == false || (LPRIFLEMAN(e->dest_obj))->isCollidable() == false)
		return;
	(LPRIFLEMAN(e->dest_obj))->SetState(RIFLEMAN_STATE_EXPLODE);
	e->src_obj->Delete();
}

void CBullet::CollisionWithScubaSoldier(LPCOLLISIONEVENT e) {
	if (friendly == false || (LPSCUBA(e->dest_obj))->isCollidable() == false)
		return;
	(LPSCUBA(e->dest_obj))->SetState(SCUBA_STATE_EXPLODE);
	e->src_obj->Delete();
}

void CBullet::CollisionWithSoldier(LPCOLLISIONEVENT e) {
	if (friendly == false || (LPSOLDIER(e->dest_obj))->isCollidable() == false)
		return;
	(LPSOLDIER(e->dest_obj))->SetState(SOLDIER_STATE_EXPLODE);
	e->src_obj->Delete();
}