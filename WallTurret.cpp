#include "WallTurret.h"

CWallTurret::CWallTurret(float x, float y) :CGameObject(x, y)
{
	this->state = WTURRET_STATE_APPEAR;
	timeleft = WTURRET_TIME_APPEAR;
	HP = 100;
}

void CWallTurret::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->HP <= 0 && this->isExploded == false) {
		this->SetState(WTURRET_STATE_EXPLODE);
	}
	this->timeleft -= dt;
	if (this->isExploded == true && this->timeleft < 0) {
		isDeleted = true;
		return;
	}
	if (this->timeleft < 0)
	{
		switch (this->state)
		{
		case WTURRET_STATE_APPEAR:
			this->SetState(WTURRET_STATE_LEFT30);
			break;
		case WTURRET_STATE_LEFT30:
			this->SetState(WTURRET_STATE_LEFT60);
			break;
		case WTURRET_STATE_LEFT60:
			this->SetState(WTURRET_STATE_LEFT90);
			break;
		case WTURRET_STATE_LEFT90:
			this->SetState(WTURRET_STATE_LEFT120);
			break;
		case WTURRET_STATE_LEFT120:
			this->SetState(WTURRET_STATE_LEFT150);
			break;
		case WTURRET_STATE_LEFT150:
			this->SetState(WTURRET_STATE_DOWN);
			break;
		case WTURRET_STATE_RIGHT30:
			this->SetState(WTURRET_STATE_UP);
			break;
		case WTURRET_STATE_RIGHT60:
			this->SetState(WTURRET_STATE_RIGHT30);
			break;
		case WTURRET_STATE_RIGHT90:
			this->SetState(WTURRET_STATE_RIGHT60);
			break;
		case WTURRET_STATE_RIGHT120:
			this->SetState(WTURRET_STATE_RIGHT90);
			break;
		case WTURRET_STATE_RIGHT150:
			this->SetState(WTURRET_STATE_RIGHT120);
			break;
		case WTURRET_STATE_UP:
			this->SetState(WTURRET_STATE_LEFT30);
			break;
		case WTURRET_STATE_DOWN:
			this->SetState(WTURRET_STATE_RIGHT150);
			break;
		}
	}
	//DebugOutTitle(L"state = %d, timeleft = %d, isDeleted = %d", this->state, this->timeleft, this->isDeleted);
}
void CWallTurret::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	switch (this->state)
	{
	case WTURRET_STATE_APPEAR:
		ani = WTURRET_ANI_APPEAR;
		break;
	case WTURRET_STATE_LEFT30:
		ani = WTURRET_ANI_LEFT30;
		break;
	case WTURRET_STATE_LEFT60:
		ani = WTURRET_ANI_LEFT60;
		break;
	case WTURRET_STATE_LEFT90:
		ani = WTURRET_ANI_LEFT90;
		break;
	case WTURRET_STATE_LEFT120:
		ani = WTURRET_ANI_LEFT120;
		break;
	case WTURRET_STATE_LEFT150:
		ani = WTURRET_ANI_LEFT150;
		break;
	case WTURRET_STATE_RIGHT30:
		ani = WTURRET_ANI_RIGHT30;
		break;
	case WTURRET_STATE_RIGHT60:
		ani = WTURRET_ANI_RIGHT60;
		break;
	case WTURRET_STATE_RIGHT90:
		ani = WTURRET_ANI_RIGHT90;
		break;
	case WTURRET_STATE_RIGHT120:
		ani = WTURRET_ANI_RIGHT120;
		break;
	case WTURRET_STATE_RIGHT150:
		ani = WTURRET_ANI_RIGHT150;
		break;
	case WTURRET_STATE_UP:
		ani = WTURRET_ANI_UP;
		break;
	case WTURRET_STATE_DOWN:
		ani = WTURRET_ANI_DOWN;
		break;
	case WTURRET_STATE_EXPLODE:
		ani = EXPLOSION_2_ANI;
		break;
	}
	animations->Get(ani)->Render(x, y);
}
void CWallTurret::SetState(int state)
{
	switch (state)
	{
	case WTURRET_STATE_APPEAR:
		timeleft = WTURRET_TIME_APPEAR;
		break;
	case WTURRET_STATE_LEFT30:
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_LEFT60:
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_LEFT90:
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_LEFT120:
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_LEFT150:
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_DOWN:
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_RIGHT150:
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_RIGHT120:
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_RIGHT90:
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_RIGHT60:
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_RIGHT30:
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_UP:
		timeleft = WTURRET_TIME_ROTATE;
		break;
	case WTURRET_STATE_EXPLODE:
		this->isExploded = true;
		timeleft = TIME_EXPLODE;
		break;
	}
	CGameObject::SetState(state);
}

void CWallTurret::CreateBox(DWORD dt) {
	bbox.left = x - WTURRET_BOX_WIDTH / 2;
	bbox.top = y - WTURRET_BOX_HEIGHT / 2;
	bbox.right = x + WTURRET_BOX_WIDTH / 2;
	bbox.bottom = y + WTURRET_BOX_HEIGHT / 2;
	x += 0;
	y += 0;
}

void CWallTurret::NoCollision(DWORD dt) {
	x += 0;
	y += 0;
}
void CWallTurret::CollisionWith(LPCOLLISIONEVENT e) {

	//Aircraft explodes by Bill's bullet & drop some bullet artifact

}