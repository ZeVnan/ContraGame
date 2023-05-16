#include "Cannon.h"

CCannon::CCannon() {}
CCannon::CCannon(float x, float y) : CGameObject(x, y) {
	isShooting = false;
	isAppear = true;
	this->state = CANNON_STATE_APPEAR;
	timeLeft = CANNON_APPEAR_TIME;
	HP = 100;
}

void CCannon::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (this->HP <= 0 && this->isExploded == false) {
		this->SetState(CANNON_STATE_EXPLODE);
	}
	this->timeLeft -= dt;
	if (this->isExploded == true && this->timeLeft < 0) {
		isDeleted = true;
		return;
	}
	if (timeLeft > 0) {
		timeLeft -= dt;
	}
	else {
		switch (state) {
		case CANNON_STATE_APPEAR:
			this->SetState(CANNON_STATE_LEFT);
			timeLeft = CANNON_SWITCH_TIME;
			break;
		case CANNON_STATE_LEFT:
			this->SetState(CANNON_STATE_LEFT_30);
			timeLeft = CANNON_SWITCH_TIME;
			break;
		case CANNON_STATE_LEFT_30:
			this->SetState(CANNON_STATE_LEFT_60);
			timeLeft = CANNON_SWITCH_TIME;
			break;
		case CANNON_STATE_LEFT_60:
			this->SetState(CANNON_STATE_LEFT);
			timeLeft = CANNON_SWITCH_TIME;
			break;
		}
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
		isShooting = true;
		waveContainer.push_back(ShootNormalBullet(180));
		break;
	case CANNON_STATE_LEFT_60:
		isShooting = true;
		waveContainer.push_back(ShootNormalBullet(150));
		break;
	case CANNON_STATE_LEFT_30:
		isShooting = true;
		waveContainer.push_back(ShootNormalBullet(120));
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
	bbox.left = (x - CANNON_BOX_WIDTH / 2);
	bbox.top = (y - CANNON_BOX_HEIGHT / 2);
	bbox.right = (x + CANNON_BOX_WIDTH / 2);
	bbox.bottom = (y + CANNON_BOX_HEIGHT / 2);
	x += 0;
	y += 0;
}

void CCannon::NoCollision(DWORD dt) {
	x += 0;
	y += 0;
}
void CCannon::CollisionWith(LPCOLLISIONEVENT e) {

	//Cannon explodes by Bill's bullets

}

vector<LPBULLET> CCannon::ShootNormalBullet(int angle) {
	LPBULLETN bulletN = new CBulletN(x, y, angle, false);
	vector<LPBULLET> temp;
	temp.push_back(bulletN);
	return temp;
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
}

void CCannon::RenderBullet()
{
	for (int i = 0; i < waveContainer.size(); i++) {
		for (int j = 0; j < waveContainer[i].size(); j++) {
			waveContainer[i][j]->Render();
		}
	}
}
