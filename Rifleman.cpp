#include "Rifleman.h"

Rifleman::Rifleman() {}

Rifleman::Rifleman(float x, float y) : CGameObject(x, y) {
	isShooting = true;
	isHiding = false;
	gunx = x;
	guny = y;
	ny = 0;
	nx = -1;
	this->state = RIFLEMAN_STATE_NORMAL;
	timeLeft = RIFLEMAN_SWITCH_TIME;
}

void Rifleman::Update(DWORD dt) {
	if (y >= GROUND_Y) {
		vy = 0;
		y = GROUND_Y;
	}
	else {
		vy += RIFLEMAN_GRAVITY * dt;
	}
	y += vy * dt;
	if (timeLeft > 0)
		timeLeft -= dt;
	else {
		switch (this->state) {
		case RIFLEMAN_STATE_NORMAL:
			this->SetState(RIFLEMAN_STATE_UP);
			timeLeft = RIFLEMAN_SWITCH_TIME;
			break;
		case RIFLEMAN_STATE_UP:
			this->SetState(RIFLEMAN_STATE_DOWN);
			timeLeft = RIFLEMAN_SWITCH_TIME;
			break;
		case RIFLEMAN_STATE_DOWN:
			this->SetState(RIFLEMAN_STATE_NORMAL);
			timeLeft = RIFLEMAN_SWITCH_TIME;
			break;
		}
	}
	//DebugOutTitle(L"State = %d, timeleft = %f", this->state, this->timeLeft);
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
			if (isShooting) {
				if (ny == 1) {
					ani = RIFLEMAN_ANI_AIM_UP_RIGHT;
				}
				if (ny == -1) {
					ani = RIFLEMAN_ANI_AIM_DOWN_RIGHT;
				}
				if (ny == 0) {
					ani = RIFLEMAN_ANI_NORMAL_RIGHT;
				}
			}
		}
		else {
			if (isShooting) {
				if (ny == 1) {
					ani = RIFLEMAN_ANI_AIM_UP_LEFT;
				}
				if (ny == -1) {
					ani = RIFLEMAN_ANI_AIM_DOWN_LEFT;
				}
				if (ny == 0) {
					ani = RIFLEMAN_ANI_NORMAL_LEFT;
				}
			}
		}
	}

	animations->Get(ani)->Render(x, y);
}

void Rifleman::SetState(int state) {
	switch (state) {
	case RIFLEMAN_STATE_NORMAL:
		ny = 0;
		break;
	case RIFLEMAN_STATE_LEFT:
		nx = -1;
		break;
	case RIFLEMAN_STATE_RIGHT:
		nx = 1;
		break;
	case RIFLEMAN_STATE_UP:
		ny = 1;
		break;
	case RIFLEMAN_STATE_DOWN:
		ny = -1;
		break;
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
	case RIFLEMAN_STATE_DEAD:
		isShooting = false;
		isHiding = false;
		break;
	}
	CGameObject::SetState(state);
}