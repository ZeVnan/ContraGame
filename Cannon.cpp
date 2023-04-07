#include "Cannon.h"

CCannon::CCannon() {}

CCannon::CCannon(float x, float y) : CGameObject(x, y) {
	isShooting = true;
	isAppear = true;
	this->state = CANNON_STATE_APPEAR;
	timeLeft = CANNON_APPEAR_TIME;
}

void CCannon::Update(DWORD dt) {
	if (timeLeft > 0) {
		timeLeft -= dt;
	}
	else {
		switch (state) {
		case CANNON_STATE_APPEAR:
			this->SetState(CANNON_STATE_LEFT);
			timeLeft = CANNON_SWITCH_TIME;
			break;
		case CANNON_STATE_LEFT:
			this->SetState(CANNON_STATE_LEFT_30);
			timeLeft = CANNON_SWITCH_TIME;
			break;
		case CANNON_STATE_LEFT_30:
			this->SetState(CANNON_STATE_LEFT_60);
			timeLeft = CANNON_SWITCH_TIME;
			break;
		case CANNON_STATE_LEFT_60:
			this->SetState(CANNON_STATE_LEFT);
			timeLeft = CANNON_SWITCH_TIME;
			break;
		}
	}
}

void CCannon::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;

	switch (this->state) {
	case CANNON_STATE_APPEAR:
		ani = CANNON_ANI_APPEAR;
		break;
	case CANNON_STATE_LEFT:
		ani = CANNON_ANI_LEFT;
		break;
	case CANNON_STATE_LEFT_60:
		ani = CANNON_ANI_LEFT_60;
		break;
	case CANNON_STATE_LEFT_30:
		ani = CANNON_ANI_LEFT_30;
		break;
	}
	animations->Get(ani)->Render(x, y);
}

void CCannon::SetState(int state) {
	switch (state) {
	case CANNON_STATE_LEFT:
		break;
	case CANNON_STATE_LEFT_60:
		break;
	case CANNON_STATE_LEFT_30:
		break;
	case CANNON_STATE_APPEAR:
		isAppear = true;
		isShooting = true;
		break;
	}
	CGameObject::SetState(state);
}