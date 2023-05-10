#include "Aircraft.h"

CAircraft::CAircraft(float x, float y, int ammo) :CGameObject(x, y) {
	this->ammo = ammo;
	vx = AIRCRAFT_SPEED_X;
	ay = AIRCRAFT_ACCEL_Y;
}
void CAircraft::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	x += vx * dt;
	y += vy * dt;

	//DebugOutTitle(L"vy = %f, y = %f, ay = %f", this->vy, this->y, this->ay);
}
void CAircraft::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	if (isDead == false) {
		ani = AIRCRAFT_ANI_NORMAL;
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
	animations->Get(ani)->Render(x, y);
}
void CAircraft::SetState(int state) {
	switch (state) {
	case AIRCRAFT_STATE_DEAD:
		isDead = true;
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
	x += vx * dt;
	y += vy * dt;
}
void CAircraft::CollisionWith(LPCOLLISIONEVENT e) {

	//Aircraft explodes by Bill's bullet & drop some bullet artifact

}