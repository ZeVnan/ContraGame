#include "ScubaSoldier.h"

CScubaSoldier::CScubaSoldier(float x, float y) :CGameObject(x, y) {
	this->state = 0;
	timeleft = SCUBA_HIDING_TIME;
}

void CScubaSoldier::Update(DWORD dt)
{
	this->timeleft -= dt;
	if (this->timeleft < 0) 
	{
		switch (this->state)
		{
		case 0:
			this->SetState(SCUBA_STATE_HIDING);
			break;
		case 1:
			this->SetState(SCUBA_STATE_SHOOTING);
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
	case 0:
		ani = SCUBA_ANI_HIDE_RIGHT;
		break;
	case 1:
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
		this->state = 1;
		timeleft = SCUBA_HIDING_TIME;
		break;
	case SCUBA_STATE_SHOOTING:
		isShooting = true;
		isHiding = false;
		this->state = 0;
		timeleft = SCUBA_SHOOTING_TIME;
		break;
	}
	
}