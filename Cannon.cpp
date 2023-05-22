#include "Cannon.h"
#include "Bill.h"

extern CBill* bill;

CCannon::CCannon() {}
CCannon::CCannon(float x, float y) : CGameObject(x, y) {
	isShooting = false;
	isAppear = false;
	isActivated = false;
	this->state = CANNON_STATE_APPEAR;
	timeLeft = CANNON_APPEAR_TIME;
	HP = 100;
	//DebugOutTitle(L"x = %f, y = %f", this->x, this->y);
}

void CCannon::WatchBill() {
	float x, y;
	bill->GetPosition(x, y);
	if (isActivated == true) {
		if (this->x - x < 0 || abs(this->x - x) >= CANNON_ACTIVE_RADIUS)
			isActivated = false;
		if (abs(this->y - y) >= CANNON_ACTIVE_RADIUS)
			isActivated = false;
	}
	else {
		if (this->x - x <= CANNON_ACTIVE_RADIUS && this->x - x > 0 && abs(y - this->y) <= CANNON_ACTIVE_RADIUS)
			isActivated = true;
	}
	//DebugOutTitle(L"isActivated = %d", isActivated);
	//DebugOutTitle(L"x = %f, y = %f, xCannon = %f, yCannon = %f, xCannon - x = %f, isActivated = %f", x, y, this->x, this->y, this->x - x, isActivated);
}

int CCannon::CalculateBillAngle() {
	const float PI = 3.14159265;
	float x, y;
	bill->GetPosition(x, y);
	float res = atan(abs(this->y - y) / abs(this->x - x)) * 180 / PI;
	res = 180 - res;
	//DebugOutTitle(L"test = %f", res);

	if (y < this->y) { 
		return CANNON_STATE_LEFT;
	}
	if (abs(180 - res) < abs(150 - res)) {
		return CANNON_STATE_LEFT;
	}
	else if (abs(150 - res) < abs(120 - res)) {
		return CANNON_STATE_LEFT_60;
	}
	else {
		return CANNON_STATE_LEFT_30;
	}
}

void CCannon::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (this->HP <= 0 && this->isExploded == false) {
		this->SetState(CANNON_STATE_EXPLODE);
	}
	if (this->isExploded == true && this->timeLeft < 0) {
		isDeleted = true;
		return;
	}
	WatchBill();
	
	if (isActivated) {
		if (!isExploded) {
			this->SetState(CalculateBillAngle());
		}
	}
	else {
		if (!isAppear) {
			isAppear = true;
		}
		this->isShooting = false;
		//return;
	}
	if (timeLeft > 0) {
		timeLeft -= dt;
	}
	else {
		timeLeft = CANNON_SWITCH_TIME;
		AddBullet();
	}
	UpdateBullet(dt, coObjects);
}

void CCannon::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;

	switch (this->state) {
	case CANNON_STATE_APPEAR:
		ani = CANNON_ANI_APPEAR;
		break;
	case CANNON_STATE_LEFT:
		ani = CANNON_ANI_LEFT;
		break;
	case CANNON_STATE_LEFT_60:
		ani = CANNON_ANI_LEFT_60;
		break;
	case CANNON_STATE_LEFT_30:
		ani = CANNON_ANI_LEFT_30;
		break;
	case CANNON_STATE_EXPLODE:
		ani = EXPLOSION_2_ANI;
		break;
	}
	animations->Get(ani)->Render(x, y);
	RenderBullet();
}

void CCannon::SetState(int state) {
	switch (state) {
	case CANNON_STATE_LEFT:
		if (isActivated) {
			isShooting = true;
		}
		else {
			isShooting = false;
		}
		break;
	case CANNON_STATE_LEFT_60:
		if (isActivated) {
			isShooting = true;
		}
		else {
			isShooting = false;
		}
		break;
	case CANNON_STATE_LEFT_30:
		if (isActivated) {
			isShooting = true;
		}
		else {
			isShooting = false;
		}
		break;
	case CANNON_STATE_APPEAR:
		isAppear = true;
		isShooting = false;
		break;
	case CANNON_STATE_EXPLODE:
		this->isExploded = true;
		timeLeft = TIME_EXPLODE;
		break;
	}
	CGameObject::SetState(state);
}

void CCannon::CreateBox(DWORD dt) {
	bbox.left = x - CANNON_BOX_WIDTH / 2;
	bbox.top = y - CANNON_BOX_HEIGHT / 2;
	bbox.right = x + CANNON_BOX_WIDTH / 2;
	bbox.bottom = y + CANNON_BOX_HEIGHT / 2;
	x += 0;
	y += 0;
}

void CCannon::NoCollision(DWORD dt) {
		
}
void CCannon::CollisionWith(LPCOLLISIONEVENT e) {

	//Cannon explodes by Bill's bullets

}

vector<LPBULLET> CCannon::ShootNormalBullet(int angle) {
	LPBULLETN bulletN;
	vector<LPBULLET> temp;
	bulletN = new CBulletN(x, y, angle, false);
	temp.push_back(bulletN);
	return temp;
}

void CCannon::AddBullet() {
	if (waveLeft > 0) {
		if (this->state == CANNON_STATE_LEFT && isShooting == true) {
			waveContainer.push_back(ShootNormalBullet(180));
		}
		else if (this->state == CANNON_STATE_LEFT_60 && isShooting == true) {
			waveContainer.push_back(ShootNormalBullet(150));
		}
		else if (this->state == CANNON_STATE_LEFT_30 && isShooting == true) {
			waveContainer.push_back(ShootNormalBullet(120));
		}
		else {
			return;
		}
	}
	else {
		waveLeft = CANNON_WAVE_BULLET;
	}
	if (isShooting) {
		waveLeft--;
	}
	//isShooting = false;
}

void CCannon::UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
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
	CCollision::GetInstance()->Process(this, coObjects, dt);
}

void CCannon::RenderBullet()
{
	for (int i = 0; i < waveContainer.size(); i++) {
		for (int j = 0; j < waveContainer[i].size(); j++) {
			waveContainer[i][j]->Render();
		}
	}
}
