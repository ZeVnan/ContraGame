#include "Cannon.h"

CCannon::CCannon() {}

CCannon::CCannon(float x, float y) : CGameObject(x, y){
	isShooting = false;
	isAppear = true;
	angle_state = ANGLE_STATE_LEFT;
	switchTime = 500;
}

void CCannon::Update(DWORD dt) {
	this->switchTime -= dt;
	if (this->switchTime < 0) {
		this->angle_state = rand() % (ANGLE_STATE_LEFT_30 + 1) + ANGLE_STATE_LEFT;
		switch (this->angle_state) {
		case ANGLE_STATE_LEFT:
			this->SetState(CANNON_STATE_LEFT);
			break;
		case ANGLE_STATE_LEFT_60:
			this->SetState(CANNON_STATE_LEFT_60);
			break;
		case ANGLE_STATE_LEFT_30:
			this->SetState(CANNON_STATE_LEFT_30);
			break;
		}
	}
}

void CCannon::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	
	switch (this->angle_state) {
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
		this->angle_state = ANGLE_STATE_LEFT;
		this->switchTime = 500;
		break;
	case CANNON_STATE_LEFT_60:
		this->angle_state = ANGLE_STATE_LEFT_60;
		this->switchTime = 600;
		break;
	case CANNON_STATE_LEFT_30:
		this->angle_state = ANGLE_STATE_LEFT_30;
		this->switchTime = 700;
		break;
	}
	CGameObject::SetState(state);
}