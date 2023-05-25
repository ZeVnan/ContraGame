#include "Bullet.h"
#include "WallTurret.h"
#include "Cannon.h"
#include "Rifleman.h"
#include "ScubaSoldier.h"
#include "Soldier.h"
#include "Aircraft.h"
#include "Falcon.h"
#include "Bill.h"
#include "Boss1Shield.h"
#include "Boss1Gun.h"

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
	float cx, cy, cw, ch;
	CGame::GetInstance()->GetCamera()->GetCamPos(cx, cy);
	cw = CGame::GetInstance()->GetCamera()->GetCamWidth();
	ch = CGame::GetInstance()->GetCamera()->GetCamHeight();
	if (x < (cx - cw / 2) || x >(cx + cw / 2) || y < (cy - ch / 2) || y > (cy + ch / 2))
		return true;
	return false;
}
void CBullet::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = this->type;
	animations->Get(aniId)->Render(x, y);
	//RenderBox();
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
	if (dynamic_cast<LPBILL>(e->dest_obj)) {
		CollisionWithBill(e);
		return;
	}
	if (dynamic_cast<LPBOSS1SHIELD>(e->dest_obj)) {
		CollisionWithBoss1Shield(e);
		return;
	}
	if (dynamic_cast<LPBOSS1GUN>(e->dest_obj)) {
		CollisionWithBoss1Gun(e);
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
	if (friendly == false || 
		(LPAIRCRAFT(e->dest_obj))->IsCollectible() == true ||
		(LPAIRCRAFT(e->dest_obj))->isCollidable() == false)
		return;
	(LPAIRCRAFT(e->dest_obj))->SetState(AIRCRAFT_STATE_EXPLODE);
	e->src_obj->Delete();
}

void CBullet::CollisionWithFalcon(LPCOLLISIONEVENT e)
{
	if (friendly == false || (LPFALCON(e->dest_obj))->GetState() != FALCON_STATE_OPEN)
		return;
	(LPFALCON(e->dest_obj))->SetState(FALCON_STATE_EXPLODE);
	e->src_obj->Delete();
}

void CBullet::CollisionWithBoss1Shield(LPCOLLISIONEVENT e) {
	if (friendly == false || (LPBOSS1SHIELD(e->dest_obj))->isCollidable() == false)
		return;
	(LPBOSS1SHIELD(e->dest_obj))->TakeDamage(this->damage);
	e->src_obj->Delete();
}
void CBullet::CollisionWithBoss1Gun(LPCOLLISIONEVENT e) {
	if (friendly == false || (LPBOSS1GUN(e->dest_obj))->isCollidable() == false)
		return;
	(LPBOSS1GUN(e->dest_obj))->TakeDamage(this->damage);
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
void CBullet::CollisionWithBill(LPCOLLISIONEVENT e) {
	if (friendly == true ||
		(LPBILL(e->dest_obj))->IsDiving() == true ||
		(LPBILL(e->dest_obj))->IsVulnerable() == false||
		(LPBILL(e->dest_obj))->IsDead() == true)
		return;
	e->src_obj->Delete();
	if (e->normal_x != 0) {
		if (e->normal_x > 0) {
			(LPBILL(e->dest_obj))->SetState(BILL_STATE_DYING_RIGHT);
		}
		else {
			(LPBILL(e->dest_obj))->SetState(BILL_STATE_DYING_LEFT);
		}
	}
	else if (e->normal_y != 0) {
		(LPBILL(e->dest_obj))->SetState(BILL_STATE_DYING_RIGHT);
	}
}