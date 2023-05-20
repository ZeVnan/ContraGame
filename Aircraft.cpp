#include "Aircraft.h"
#include "Bill.h"
#include "Grass.h"
extern CBill* bill;
CAircraft::CAircraft(float x, float y, int stage) :CGameObject(x, y) {
	this->ammo = rand() % 5 + 13002;
	this->stage = stage;
	isCollectible = false;
	isExploded = false;
	isActivated = false;
	timeleft = 0;
	if (stage == 1) {
		vx = AIRCRAFT_SPEED_X;
		vy = 0;
	}
	if (stage == 3) {
		vx = 0;
		vy = AIRCRAFT_SPEED_Y;
	}
	ay = 0;
}
void CAircraft::watchBill() {
	float x, y;
	bill->GetPosition(x, y);
	if (isActivated == true) {
		if (this->x - x >= AIRCRAFT_ACTIVE_RADIUS && stage == 1)
			isDeleted = true;
		if (this->y - y >= AIRCRAFT_ACTIVE_RADIUS && stage == 3)
			isDeleted = true;
	}
	else {
		if (x - this->x >= AIRCRAFT_ACTIVE_RADIUS && stage == 1)
			isActivated = true;
		if (y - this->y >= AIRCRAFT_ACTIVE_RADIUS && stage == 3)
			isActivated = true;
	}
}
void CAircraft::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	watchBill();
	if (isActivated == false)
		return;
	if (isExploded == false) {
		vy += ay * dt;
		x += vx * dt;
		y += vy * dt;
		return;
	}	
	//update for exploded
	if (timeleft >= 0) {
		this->timeleft -= dt;
	}
	if (this->timeleft < 0) {
		this->SetState(AIRCRAFT_STATE_DROPITEM);
	}
	if (isCollectible == false)	//update for collectible
		return;

	CCollision::GetInstance()->Process(this, coObjects, dt);
	//DebugOutTitle(L"vy = %f, y = %f", vy, y);
}
void CAircraft::Render() {
	if (isActivated == false) {
		return;
	}
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	if (isExploded) {
		if (isCollectible == false) {
			ani = EXPLOSION_2_ANI;
		}
		else {
			switch (this->ammo) {
			case AIRCRAFT_ANI_bAMMO:
				ani = AIRCRAFT_ANI_bAMMO;
				break;
			case AIRCRAFT_ANI_fAMMO:
				ani = AIRCRAFT_ANI_fAMMO;
				break;
			case AIRCRAFT_ANI_lAMMO:
				ani = AIRCRAFT_ANI_lAMMO;
				break;
			case AIRCRAFT_ANI_mAMMO:
				ani = AIRCRAFT_ANI_mAMMO;
				break;
			case AIRCRAFT_ANI_rAMMO:
				ani = AIRCRAFT_ANI_rAMMO;
				break;
			case AIRCRAFT_ANI_sAMMO:
				ani = AIRCRAFT_ANI_sAMMO;
				break;
			}
		}
	}
	else {
		ani = AIRCRAFT_ANI_NORMAL;
	}

	animations->Get(ani)->Render(x, y);
}
void CAircraft::SetState(int state) {
	switch (state) {
	case AIRCRAFT_STATE_NORMAL:
		isExploded = false;
		break;
	case AIRCRAFT_STATE_EXPLODE:
		isExploded = true;
		timeleft = TIME_EXPLODE;
		break;
	case AIRCRAFT_STATE_DROPITEM:
		isCollectible = true;
		if (stage == 1)
			vx = 0;
		if (stage == 3)
			vy = 0;
		ay = AIRCRAFT_GRAVITY;
		break;
	}
	CGameObject::SetState(state);
}

void CAircraft::CreateBox(DWORD dt) {
	bbox.left = (x - AIRCRAFT_BOX_WIDTH / 2);
	bbox.top = (y - AIRCRAFT_BOX_HEIGHT / 2);
	bbox.right = (x + AIRCRAFT_BOX_WIDTH / 2);
	bbox.bottom = (y + AIRCRAFT_BOX_HEIGHT / 2);
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}

void CAircraft::NoCollision(DWORD dt) {
	vy += ay * dt;
	x += vx * dt;
	y += vy * dt;
}
void CAircraft::CollisionWith(LPCOLLISIONEVENT e) {
	if (dynamic_cast<LPGRASS>(e->dest_obj)) {
		CollisionWithGrass(e);
	}
}
void CAircraft::CollisionWithGrass(LPCOLLISIONEVENT e) {
	if (e->normal_y < 0) {
		this->y += bbox.vpf_y;
	}
	if (e->normal_y > 0) {
		this->y += e->time * bbox.vpf_y;
	}
}