#include "Rifleman.h"

Rifleman::Rifleman() {}

Rifleman::Rifleman(float x, float y) : CGameObject(x, y) {
	isShooting = false;
	isHiding = false;
}

void Rifleman::Update(DWORD dt) {
	y += vy * dt;

	if (y >= GROUND_Y) {
		vy = 0;
		y = GROUND_Y;
	}
	else {
		vy += RIFLEMAN_GRAVITY * dt;
	}
}

void Rifleman::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;



	if (isHiding) {
		if (nx > 0) {
			ani = RIFLEMAN_ANI_HIDE_RIGHT;
		}
		else {
			ani = RIFLEMAN_ANI_HIDE_LEFT;
		}
	}
	else {
		if (nx > 0) {
			ani = RIFLEMAN_ANI_NORMAL_RIGHT;
		}
		else {
			ani = RIFLEMAN_ANI_NORMAL_LEFT;
		}
	}

	if (isShooting) {
		if (nx > 0) {
			ani = RIFLEMAN_ANI_SHOOT_RIGHT;
		}
		else {
			ani = RIFLEMAN_ANI_SHOOT_LEFT;
		}
	}

	animations->Get(ani)->Render(x, y);
}

void Rifleman::SetState(int state) {
	switch (state) {
	case RIFLEMAN_STATE_HIDING:
		isShooting = false;
		isHiding = true;
		break;
	case RIFLEMAN_STATE_SHOOT:
		isShooting = true;
		break;
	case RIFLEMAN_STATE_SHOOT_RELEASE:
		isShooting = false;
		break;
	case RIFLEMAN_STATE_EXPOSE:
		isShooting = true;
		isHiding = false;
		break;
	}
	CGameObject::SetState(state);
}