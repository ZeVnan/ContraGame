#include "Rifleman.h"

Rifleman::Rifleman() {}

Rifleman::Rifleman(float x, float y) : CGameObject(x, y) {
	isShooting = false;
	isHiding = true;
	nx = -1;
}

void Rifleman::Update(DWORD dt) {
	
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
		isHiding = false;
		break;
	}
	CGameObject::SetState(state);
}