#include "ScubaSoldier.h"

CScubaSoldier::CScubaSoldier(float x, float y) :CGameObject(x, y) {
	this->state = SCUBA_STATE_HIDING;
	timeleft = SCUBA_HIDING_TIME;
}

void CScubaSoldier::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	this->timeleft -= dt;
	if (this->timeleft < 0) 
	{
		switch (this->state)
		{
		case SCUBA_STATE_HIDING:
			this->SetState(SCUBA_STATE_SHOOTING);
			break;
		case SCUBA_STATE_SHOOTING:
			this->SetState(SCUBA_STATE_HIDING);
			break;
		}
	}
	//DebugOutTitle(L"state = %d, timeleft = %d", this->state, this->timeleft);
}

void CScubaSoldier::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	switch(this->state)
	{
	case SCUBA_STATE_HIDING:
		ani = SCUBA_ANI_HIDE_RIGHT;
		break;
	case SCUBA_STATE_SHOOTING:
		ani = SCUBA_ANI_SHOOT_RIGHT;
		break;
	}
	animations->Get(ani)->Render(x, y);
}

void CScubaSoldier::SetState(int state)
{
	switch (state)
	{
	case SCUBA_STATE_HIDING:
		isHiding = true;
		isShooting = false;
		timeleft = SCUBA_HIDING_TIME;
		break;
	case SCUBA_STATE_SHOOTING:
		isShooting = true;
		isHiding = false;
		timeleft = SCUBA_SHOOTING_TIME;
		break;
	}
	CGameObject::SetState(state);
}

void CScubaSoldier::CreateBox(DWORD dt)
{
	if (isHiding)
	{
		bbox.left = x - SCUBA_BOX_HIDE_WIDTH / 2;
		bbox.top = y - SCUBA_BOX_HIDE_HEIGHT / 2;
		bbox.right = x + SCUBA_BOX_HIDE_WIDTH / 2;
		bbox.bottom = y + SCUBA_BOX_HIDE_HEIGHT / 2;
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
	else
	{
		bbox.left = x - SCUBA_BOX_SHOOT_WIDTH / 2;
		bbox.top = y - SCUBA_BOX_SHOOT_HEIGHT / 2;
		bbox.right = x + SCUBA_BOX_SHOOT_WIDTH / 2;
		bbox.bottom = y + SCUBA_BOX_SHOOT_HEIGHT / 2;
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
	
}

void CScubaSoldier::NoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CScubaSoldier::CollisionWith(LPCOLLISIONEVENT e)
{
}
