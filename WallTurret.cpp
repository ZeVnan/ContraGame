#include "WallTurret.h"
extern int score;
CWallTurret::CWallTurret(float x, float y) :CGameObject(x, y)
{
	isActivated = false;
	isClosing = true;
	this->state = WTURRET_STATE_CLOSE;
	timeLeft = 0;
	HP = 100;
	gunx = x;
	guny = y;
}

void CWallTurret::watchBill() {
	float x, y;
	bill->GetPosition(x, y);

	float distance_to_Bill = sqrt((this->x - x) * (this->x - x) + (this->y - y) * (this->y - y));
	if (distance_to_Bill <= WALLTURRET_ACTIVE_RADIUS) {
		isActivated = true;
		if (this->state == WTURRET_STATE_CLOSE) {
			this->SetState(WTURRET_STATE_APPEAR);
		}
	}
	else {
		isActivated = false;
	}

	if (isClosing == true || isActivated == false || isExploded == true) {
		return;
	}
	if (state == WTURRET_STATE_APPEAR && timeLeft > 0) {
		return;
	}
	float tan = abs(this->y - y) / abs(this->x - x);// get angle's tan value
	float degree = atan(tan) * 180.0f / 3.14159f;// transfer to angle degree
	float checking_degree = 0;// from 0 to 360 base on fourth part of degree's circle COMPARE TO Ox

	// calculate checking_degree
	if (x > this->x) {
		if (y > this->y) {
			checking_degree = degree;
		}
		else {
			checking_degree = 360 - degree;
		}
	}
	else {
		if (y > this->y) {
			checking_degree = 180 - degree;
		}
		else {
			checking_degree = 180 + degree;
		}
	}

	// set State follow Bill's position

	if (checking_degree >= 345 || checking_degree <= 15) {
		this->state = WTURRET_STATE_RIGHT90;
		gunx = this->x + 16;
		guny = this->y;
	}
	else if (checking_degree >= 15 && checking_degree <= 45) {
		this->state = WTURRET_STATE_RIGHT60;
		gunx = this->x + 18;
		guny = this->y + 13;
	}
	else if (checking_degree >= 45 && checking_degree <= 75) {
		this->state = WTURRET_STATE_RIGHT30;
		gunx = this->x + 11;
		guny = this->y + 18;
	}
	else if (checking_degree >= 75 && checking_degree <= 105) {
		this->state = WTURRET_STATE_UP;
		gunx = this->x;
		guny = this->y + 16;
	}
	else if (checking_degree >= 105 && checking_degree <= 135) {
		this->state = WTURRET_STATE_LEFT30;
		gunx = this->x - 11;
		guny = this->y + 18;
	}
	else if (checking_degree >= 135 && checking_degree <= 165) {
		this->state = WTURRET_STATE_LEFT60;
		gunx = this->x - 18;
		guny = this->y + 13;
	}
	else if (checking_degree >= 165 && checking_degree <= 195) {
		this->state = WTURRET_STATE_LEFT90;
		gunx = this->x - 16;
		guny = this->y;
	}
	else if (checking_degree >= 195 && checking_degree <= 225) {
		this->state = WTURRET_STATE_LEFT120;
		gunx = this->x - 18;
		guny = this->y - 13;
	}
	else if (checking_degree >= 225 && checking_degree <= 255) {
		this->state = WTURRET_STATE_LEFT150;
		gunx = this->x - 11;
		guny = this->y - 18;
	}
	else if (checking_degree >= 255 && checking_degree <= 285) {
		this->state = WTURRET_STATE_DOWN;
		gunx = this->x;
		guny = this->y - 16;
	}
	else if (checking_degree >= 285 && checking_degree <= 315) {
		this->state = WTURRET_STATE_RIGHT150;
		gunx = this->x + 11;
		guny = this->y - 18;
	}
	else if (checking_degree >= 315 && checking_degree <= 345) {
		this->state = WTURRET_STATE_RIGHT120;
		gunx = this->x + 18;
		guny = this->y - 13;
	}
}

void CWallTurret::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->HP <= 0 && this->isExploded == false) {
		this->SetState(WTURRET_STATE_EXPLODE);
	}
	if (timeLeft > 0)
		this->timeLeft -= dt;
	if (this->isExploded == true && this->timeLeft <= 0) {
		isDeleted = true;
		return;
	}
	watchBill();
	if (this->timeLeft <= 0 && isActivated == true && isExploded == false)
	{
		AddBullet();
		this->timeLeft = WTURRET_TIME_RELOAD;
	}
	UpdateBullet(dt, coObjects);
	//DebugOutTitle(L"timeleft = %d, state = %d", this->timeLeft, state);

}
void CWallTurret::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	switch (this->state)
	{
	case WTURRET_STATE_CLOSE:
		ani = WTURRET_ANI_CLOSE;
		break;
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
		score += 40;
		break;
	}
	animations->Get(ani)->Render(x, y);
	RenderBullet();
}
void CWallTurret::SetState(int state)
{
	switch (state)
	{
	case WTURRET_ANI_CLOSE:
		break;
	case WTURRET_STATE_APPEAR:
		isClosing = false;
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

	switch (this->state) {
	case WTURRET_STATE_LEFT30:
		return 120;
	case WTURRET_STATE_LEFT60:
		return 150;
	case WTURRET_STATE_LEFT90:
		return 180;
	case WTURRET_STATE_LEFT120:
		return 210;
	case WTURRET_STATE_LEFT150:
		return 240;
	case WTURRET_STATE_DOWN:
		return 270;
	case WTURRET_STATE_RIGHT150:
		return 300;
	case WTURRET_STATE_RIGHT120:
		return 330;
	case WTURRET_STATE_RIGHT90:
		return 0;
	case WTURRET_STATE_RIGHT60:
		return 30;
	case WTURRET_STATE_RIGHT30:
		return 60;
	case WTURRET_STATE_UP:
		return 90;
	default:
		return 0;
	}
}
LPBULLET CWallTurret::ShootNormalBullet(float angle) {
	LPBULLETN bulletN = new CBulletN(gunx, guny, angle, false);
	return bulletN;
}
void CWallTurret::AddBullet() {
	bullets.push_back(ShootNormalBullet((float)CalculateAngle()));
}
void CWallTurret::UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i]->outOfScreen() || bullets[i]->IsDeleted()) {
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
		else {
			bullets[i]->Update(dt, coObjects);
		}
	}
}
void CWallTurret::RenderBullet() {
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Render();
	}
}

void CWallTurret::CreateBox(DWORD dt) {
	bbox.left = (x - WTURRET_BOX_WIDTH / 2);
	bbox.top = (y + WTURRET_BOX_HEIGHT / 2);
	bbox.right = (x + WTURRET_BOX_WIDTH / 2);
	bbox.bottom = (y - WTURRET_BOX_HEIGHT / 2);
}
void CWallTurret::NoCollision(DWORD dt) {
	x += 0;
	y += 0;
}
void CWallTurret::CollisionWith(LPCOLLISIONEVENT e) {

	//Aircraft explodes by Bill's bullet & drop some bullet artifact

}