#include "WallTurret.h"

CWallTurret::CWallTurret(float x, float y) :CGameObject(x, y)
{
	this->state = 0;
	timeleft = WTURRET_TIME_APPEAR;
}

void CWallTurret::Update(DWORD dt)
{
	this->timeleft -= dt;
	if (this->timeleft < 0)
	{
		switch (this->state)
		{
		case 0:
			this->SetState(WTURRET_STATE_APPEAR);
			break;
		case 1:
			this->SetState(WTURRET_STATE_LEFT30);
			break;
		case 2:
			this->SetState(WTURRET_STATE_LEFT60);
			break;
		case 3:
			this->SetState(WTURRET_STATE_LEFT90);
			break;
		case 4:
			this->SetState(WTURRET_STATE_LEFT120);
			break;
		case 5:
			this->SetState(WTURRET_STATE_LEFT150);
			break;
		case 6:
			this->SetState(WTURRET_STATE_RIGHT30);
			break;
		case 7:
			this->SetState(WTURRET_STATE_RIGHT60);
			break;
		case 8:
			this->SetState(WTURRET_STATE_RIGHT90);
			break;
		case 9:
			this->SetState(WTURRET_STATE_RIGHT120);
			break;
		case 10:
			this->SetState(WTURRET_STATE_RIGHT150);
			break;
		case 11:
			this->SetState(WTURRET_STATE_UP);
			break;
		case 12:
			this->SetState(WTURRET_STATE_DOWN);
			break;
		}
	}
	DebugOutTitle(L"state = %d, timeleft = %d", this->state, this->timeleft);
}

void CWallTurret::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	switch (this->state)
	{
	case 0:
		ani = WTURRET_ANI_APPEAR;
		break;
	case 1:
		ani = WTURRET_ANI_LEFT30;
		break;
	case 2:
		ani = WTURRET_ANI_LEFT60;
		break;
	case 3:
		ani = WTURRET_ANI_LEFT90;
		break;
	case 4:
		ani = WTURRET_ANI_LEFT120;
		break;
	case 5:
		ani = WTURRET_ANI_LEFT150;
		break;
	case 6:
		ani = WTURRET_ANI_RIGHT30;
		break;
	case 7:
		ani = WTURRET_ANI_RIGHT60;
		break;
	case 8:
		ani = WTURRET_ANI_RIGHT90;
		break;
	case 9:
		ani = WTURRET_ANI_RIGHT120;
		break;
	case 10:
		ani = WTURRET_ANI_RIGHT150;
		break;
	case 11:
		ani = WTURRET_ANI_UP;
		break;
	case 12:
		ani = WTURRET_ANI_DOWN;
		break;
	}
	animations->Get(ani)->Render(x, y);
}

void CWallTurret::SetState(int state)
{
	switch (state)
	{
	case WTURRET_STATE_APPEAR:
		this->state = 1;
		timeleft = WTURRET_TIME_APPEAR;
		break;
	case WTURRET_STATE_LEFT30:
		this->state = 2;
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_LEFT60:
		this->state = 3;
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_LEFT90:
		this->state = 4;
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_LEFT120:
		this->state = 5;
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_LEFT150:
		this->state = 12;
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_DOWN:
		this->state = 10;
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_RIGHT150:
		this->state = 9;
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_RIGHT120:
		this->state = 8;
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_RIGHT90:
		this->state = 7;
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_RIGHT60:
		this->state = 6;
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_RIGHT30:
		this->state = 11;
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_UP:
		this->state = 1;
		timeleft = WTURRET_TIME_ROTATE;
		break;
	}

}