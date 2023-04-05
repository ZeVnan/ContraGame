#include "Cannon.h"

CCannon::CCannon() {}

CCannon::CCannon(float x, float y) : CGameObject(x, y){
	isShooting = false;
	isAppear = true;
	state = 0;
	switchTime = 0;
}

void CCannon::Update(DWORD dt) {
	this->switchTime -= dt;
	if (this->switchTime < 0) {
		switch (this->state) {
		case 0:
			this->SetState(CANNON_STATE_LEFT);
			break;
		case 1:
			this->SetState(CANNON_STATE_LEFT_60);
			break;
		case 2:
			this->SetState(CANNON_STATE_LEFT_30);
			break;
		}
	}
}

void CCannon::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	
	switch (this->state) {
	case 0:
		ani = CANNON_ANI_LEFT;
		break;
	case 1:
		ani = CANNON_ANI_LEFT_60;
		break;
	case 2:
		ani = CANNON_ANI_LEFT_30;
		break;
	}
	animations->Get(ani)->Render(x, y);
}

void CCannon::SetState(int state) {
	switch (state) {
	case CANNON_STATE_LEFT:
		this->state = 0;
		this->switchTime = 300;
		break;
	case CANNON_STATE_LEFT_60:
		this->state = 1;
		this->switchTime = 300;
		break;
	case CANNON_STATE_LEFT_30:
		this->state = 2;
		this->switchTime = 300;
		break;
	}
	CGameObject::SetState(state);
}