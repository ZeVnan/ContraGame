#include "Cannon.h"

CCannon::CCannon() {}

CCannon::CCannon(float x, float y) : CGameObject(x, y) {
	isShooting = false;
	isAppear = false;
	this->state = CANNON_STATE_LEFT;
}

void CCannon::Update(DWORD dt) {


}

void CCannon::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;

	switch (this->state) {
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
	case CANNON_ANI_APPEAR:
		isAppear = true;
		isShooting = true;
		break;
	}
	CGameObject::SetState(state);
}