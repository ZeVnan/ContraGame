#include "WallTurret.h"

CWallTurret::CWallTurret(float x, float y) :CGameObject(x, y)
{
	this->state = WTURRET_STATE_APPEAR;
	timeleft = WTURRET_TIME_APPEAR;
	HP = 100;
	gunx = x;
	guny = y;
}

void CWallTurret::watchBill() {
	float x, y;
	bill->GetPosition(x, y);

	float xx, yy;
	this->GetPosition(xx, yy);

	float tan = abs(xx - x) / abs(yy - y);// get angle's tan value
	float degree = atan(tan) * 180.0 / M_PI;// transfer to angle degree
	float checking_degree = 0;// from 0 to 360 base on fourth part of degree's circle COMPARE TO Ox

	// calculate checking_degree
	if (x > xx) {
		if (y > yy) {
			checking_degree = 90 - degree;
		}
		else {
			checking_degree = 360 - degree;
		}
	}
	else {
		if (y > yy) {
			checking_degree = 180 - degree;
		}
		else {
			checking_degree = 270 - degree;
		}
	}

	// set State follow Bill's position

	if (checking_degree >= 345 || checking_degree <= 15) this->state = WTURRET_STATE_RIGHT90;
	else if (checking_degree >= 15 && checking_degree <= 45) this->state = WTURRET_STATE_RIGHT60;
	else if (checking_degree >= 45 && checking_degree <= 75) this->state = WTURRET_STATE_RIGHT30;
	else if (checking_degree >= 75 && checking_degree <= 105) this->state = WTURRET_STATE_UP;
	else if (checking_degree >= 105 && checking_degree <= 135) this->state = WTURRET_STATE_LEFT30;
	else if (checking_degree >= 135 && checking_degree <= 165) this->state = WTURRET_STATE_LEFT60;
	else if (checking_degree >= 165 && checking_degree <= 195) this->state = WTURRET_STATE_LEFT90;
	else if (checking_degree >= 195 && checking_degree <= 225) this->state = WTURRET_STATE_LEFT120;
	else if (checking_degree >= 225 && checking_degree <= 255) this->state = WTURRET_STATE_LEFT150;
	else if (checking_degree >= 255 && checking_degree <= 285) this->state = WTURRET_STATE_DOWN;
	else if (checking_degree >= 285 && checking_degree <= 315) this->state = WTURRET_STATE_RIGHT150;
	else if (checking_degree >= 315 && checking_degree <= 345) this->state = WTURRET_STATE_RIGHT120;

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

	watchBill();
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
		//AddBullet();
	}
	UpdateBullet(dt, coObjects);
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
	RenderBullet();
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

int CWallTurret::CalculateAngle() {

	switch (this->state) {
	case WTURRET_STATE_APPEAR:
		return 180;
		break;
	case WTURRET_STATE_LEFT30:
		return 120;
		break;
	case WTURRET_STATE_LEFT60:
		return 150;
		break;
	case WTURRET_STATE_LEFT90:
		return 180;
		break;
	case WTURRET_STATE_LEFT120:
		return 210;
		break;
	case WTURRET_STATE_LEFT150:
		return 240;
		break;
	case WTURRET_STATE_DOWN:
		return 270;
		break;
	case WTURRET_STATE_RIGHT150:
		return 300;
		break;
	case WTURRET_STATE_RIGHT120:
		return 330;
		break;
	case WTURRET_STATE_RIGHT90:
		return 0;
		break;
	case WTURRET_STATE_RIGHT60:
		return 30;
		break;
	case WTURRET_STATE_RIGHT30:
		return 60;
		break;
	case WTURRET_STATE_UP:
		return 90;
		break;
	}
}
vector<LPBULLET> CWallTurret::ShootNormalBullet(int angle) {
	LPBULLETN bulletN = new CBulletN(gunx, guny, angle, false);
	vector<LPBULLET> temp;
	temp.push_back(bulletN);
	return temp;
}
void CWallTurret::AddBullet() {
	waveContainer.push_back(ShootNormalBullet(CalculateAngle()));
}
void CWallTurret::UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	for (int i = 0; i < waveContainer.size(); i++) {
		if (waveContainer[i].size() > 0) {
			for (int j = 0; j < waveContainer[i].size(); j++) {
				if (waveContainer[i][j]->outOfScreen() || waveContainer[i][j]->IsDeleted()) {
					delete waveContainer[i][j];
					waveContainer[i].erase(waveContainer[i].begin() + j);
				}
				else
					waveContainer[i][j]->Update(dt, coObjects);
			}
		}
		if (waveContainer[i].size() == 0) {
			waveContainer.erase(waveContainer.begin() + i);
			waveLeft++;
		}
	}
}
void CWallTurret::RenderBullet() {
	for (int i = 0; i < waveContainer.size(); i++) {
		for (int j = 0; j < waveContainer[i].size(); j++) {
			waveContainer[i][j]->Render();
		}
	}
}

void CWallTurret::CreateBox(DWORD dt) {
	bbox.left = (x - WTURRET_BOX_WIDTH / 2);
	bbox.top = (y - WTURRET_BOX_HEIGHT / 2);
	bbox.right = (x + WTURRET_BOX_WIDTH / 2);
	bbox.bottom = (y + WTURRET_BOX_HEIGHT / 2);
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