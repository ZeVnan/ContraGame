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

void Rifleman::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	timeLeft -= dt;
	if (this->isExploded == true && this->timeLeft < 0) {
		isDeleted = true;
		return;
	}
	if (timeLeft < 0) {
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
	//DebugOutTitle(L"timeleft = %f", this->timeLeft);
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
					ani = RIFLEMAN_ANI_SHOOT_RIGHT;
				}
			}
			else
				ani = RIFLEMAN_ANI_NORMAL_RIGHT;
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
					ani = RIFLEMAN_ANI_SHOOT_LEFT;
				}
			}
			else
				ani = RIFLEMAN_ANI_NORMAL_LEFT;
		}
	}
	if (isExploded) {
		ani = EXPLOSION_1_ANI;
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
	case RIFLEMAN_STATE_EXPLODE:
		isShooting = false;
		isHiding = false;
		isExploded = true;
		timeLeft = TIME_EXPLODE;
		break;
	}
	CGameObject::SetState(state);
}

void Rifleman::CreateBox(DWORD dt)
{
	if (isHiding)
	{
		bbox.left = x - RIFLEMAN_BOX_HIDE_WIDTH / 2;
		bbox.top = y - RIFLEMAN_BOX_HIDE_HEIGHT / 2;
		bbox.right = x + RIFLEMAN_BOX_HIDE_WIDTH / 2;
		bbox.bottom = y + RIFLEMAN_BOX_HIDE_HEIGHT / 2;
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
	else
	{
		bbox.left = x - RIFLEMAN_BOX_NORMAL_WIDTH / 2;
		bbox.top = y - RIFLEMAN_BOX_NORMAL_HEIGHT / 2;
		bbox.right = x + RIFLEMAN_BOX_NORMAL_WIDTH / 2;
		bbox.bottom = y + RIFLEMAN_BOX_NORMAL_HEIGHT / 2;
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
}

void Rifleman::NoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void Rifleman::CollisionWith(LPCOLLISIONEVENT e)
{
}
