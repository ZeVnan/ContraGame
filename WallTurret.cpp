#include "WallTurret.h"

CWallTurret::CWallTurret(float x, float y) :CGameObject(x, y)
{
	this->state = WTURRET_STATE_APPEAR;
	timeLeft = WTURRET_TIME_APPEAR;
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

	if (checking_degree >= 355 || checking_degree <= 5) this->state = WTURRET_STATE_RIGHT90;
	if (checking_degree >= 25 && checking_degree <= 35) this->state = WTURRET_STATE_RIGHT60;
	if (checking_degree >= 55 && checking_degree <= 65) this->state = WTURRET_STATE_RIGHT30;
	if (checking_degree >= 85 && checking_degree <= 95) this->state = WTURRET_STATE_UP;
	if (checking_degree >= 115 && checking_degree <= 125) this->state = WTURRET_STATE_LEFT30;
	if (checking_degree >= 145 && checking_degree <= 155) this->state = WTURRET_STATE_LEFT60;
	if (checking_degree >= 175 && checking_degree <= 185) this->state = WTURRET_STATE_LEFT90;
	if (checking_degree >= 205 && checking_degree <= 215) this->state = WTURRET_STATE_LEFT120;
	if (checking_degree >= 235 && checking_degree <= 245) this->state = WTURRET_STATE_LEFT150;
	if (checking_degree >= 265 && checking_degree <= 275) this->state = WTURRET_STATE_DOWN;
	if (checking_degree >= 295 && checking_degree <= 305) this->state = WTURRET_STATE_RIGHT150;
	if (checking_degree >= 325 && checking_degree <= 335) this->state = WTURRET_STATE_RIGHT120;

}

void CWallTurret::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->HP <= 0 && this->isExploded == false) {
		this->SetState(WTURRET_STATE_EXPLODE);
	}
	this->timeLeft -= dt;
	if (this->isExploded == true && this->timeLeft < 0) {
		isDeleted = true;
		return;
	}
	if (this->isExploded == false) {
		watchBill();
	}
	if (this->timeLeft < 0)
	{
		AddBullet();
		this->timeLeft = WTURRET_TIME_RELOAD;
	}
	UpdateBullet(dt, coObjects);
	DebugOutTitle(L"timeleft = %d", this->timeLeft);
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
		timeLeft = WTURRET_TIME_APPEAR;
		break;
	case WTURRET_STATE_LEFT30:
		break;
	case WTURRET_STATE_LEFT60:
		break;
	case WTURRET_STATE_LEFT90:
		break;
	case WTURRET_STATE_LEFT120:
		break;
	case WTURRET_STATE_LEFT150:
		break;
	case WTURRET_STATE_DOWN:
		break;
	case WTURRET_STATE_RIGHT150:
		break;
	case WTURRET_STATE_RIGHT120:
		break;
	case WTURRET_STATE_RIGHT90:
		break;
	case WTURRET_STATE_RIGHT60:
		break;
	case WTURRET_STATE_RIGHT30:
		break;
	case WTURRET_STATE_UP:
		break;
	case WTURRET_STATE_EXPLODE:
		this->isExploded = true;
		timeLeft = TIME_EXPLODE;
		break;
	}
	CGameObject::SetState(state);
}

int CWallTurret::CalculateAngle() {
	if (this->state == WTURRET_STATE_APPEAR) return 180;
	else if (this->state == WTURRET_STATE_LEFT30) return 120;
	else if (this->state == WTURRET_STATE_LEFT60) return 150;
	else if (this->state == WTURRET_STATE_LEFT90) return 180;
	else if (this->state == WTURRET_STATE_LEFT120) return 210;
	else if (this->state == WTURRET_STATE_LEFT150) return 240;
	else if (this->state == WTURRET_STATE_DOWN) return 270;
	else if (this->state == WTURRET_STATE_RIGHT150) return 300;
	else if (this->state == WTURRET_STATE_RIGHT120) return 330;
	else if (this->state == WTURRET_STATE_RIGHT90) return 0;
	else if (this->state == WTURRET_STATE_RIGHT60) return 30;
	else if (this->state == WTURRET_STATE_RIGHT30) return 60;
	else if (this->state == WTURRET_STATE_UP) return 90;
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