#include "Cannon.h"
#include "Bill.h"

extern CBill* bill;
extern int score;
CCannon::CCannon(float x, float y) : CGameObject(x, y) {
	isShooting = false;
	isAppear = false;
	isActivated = false;
	isExploded = false;
	timeLeft = CANNON_APPEAR_TIME;
	HP = 100;
	//DebugOutTitle(L"x = %f, y = %f", this->x, this->y);
}

void CCannon::WatchBill() {
	float Bill_x, Bill_y;
	bill->GetPosition(Bill_x, Bill_y);
	float distance = sqrt((this->x - Bill_x) * (this->x - Bill_x) + (this->y - Bill_y) * (this->y - Bill_y));
	if (isActivated == true) {
		if (distance > CANNON_ACTIVE_RADIUS  || this->x < Bill_x || this->y > Bill_y) {
			isActivated = false;
		}
	}
	else {
		if (distance < CANNON_ACTIVE_RADIUS && this->x >= Bill_x && this->y <= Bill_y) {
			isActivated = true;
		}
	}
	//DebugOutTitle(L"Cannon_x = %f, Bill_x = %f, Bill_y = %f,", this->x, Bill_x, Bill_y);
}

int CCannon::CalculateBillAngle() {
	const float PI = 3.14159f;
	float x, y;
	bill->GetPosition(x, y);
	float res = atan(abs(this->y - y) / abs(this->x - x)) * 180 / PI;
	if (x >= this->x) {
		if (y >= this->y) {
			//not change
		}
		else {
			res = 270 + (90 - res);
		}
	}
	else {
		if (y >= this->y) {
			res = 90 + (90 - res);
		}
		else {
			res = 180 + res;
		}
	}
	if (y < this->y) { 
		return CANNON_STATE_180;
	}
	if (abs(180 - res) < abs(150 - res)) {
		return CANNON_STATE_180;
	}
	else if (abs(150 - res) < abs(120 - res)) {
		return CANNON_STATE_150;
	}
	else {
		return CANNON_STATE_120;
	}
}

void CCannon::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	int shootTime = CANNON_SHOOT_TIME;
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
			if (!isAppear) {
				isAppear = true;
				this->SetState(CANNON_STATE_APPEAR);
			}
			else {
				this->SetState(CalculateBillAngle());
			}
		}
	}
	else {
		isShooting = false;
	}
	if (timeLeft > 0) {
		timeLeft -= dt;
	}
	else {
		if (waveLeft > 0) {
			timeLeft = CANNON_SHOOT_TIME; 
			waveLeft--;
			AddBullet();
		}
		else {
			timeLeft = CANNON_RELOAD_TIME;
			waveLeft = CANNON_WAVE_BULLET;
		}
	}
	CCollision::GetInstance()->Process(this, coObjects, dt);
	UpdateBullet(dt, coObjects);
	DebugOutTitle(L"timeLeft = %d", timeLeft);
}

void CCannon::Render() {
	if (isActivated == false && isAppear == false) {
		return;
	}
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;

	switch (this->state) {
	case CANNON_STATE_APPEAR:
		ani = CANNON_ANI_APPEAR;
		break;
	case CANNON_STATE_180:
		ani = CANNON_ANI_180;
		break;
	case CANNON_STATE_150:
		ani = CANNON_ANI_150;
		break;
	case CANNON_STATE_120:
		ani = CANNON_ANI_120;
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
	case CANNON_STATE_180:
		if (isActivated) {
			isShooting = true;
		}
		else {
			isShooting = false;
		}
		break;
	case CANNON_STATE_150:
		if (isActivated) {
			isShooting = true;
		}
		else {
			isShooting = false;
		}
		break;
	case CANNON_STATE_120:
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
		score += 40;
		break;
	}
	CGameObject::SetState(state);
}

void CCannon::CreateBox(DWORD dt) {
	bbox.left = x - CANNON_BOX_WIDTH / 2;
	bbox.top = y + CANNON_BOX_HEIGHT / 2;
	bbox.right = x + CANNON_BOX_WIDTH / 2;
	bbox.bottom = y - CANNON_BOX_HEIGHT / 2;
}

void CCannon::NoCollision(DWORD dt) {
		
}
void CCannon::CollisionWith(LPCOLLISIONEVENT e) {

	//Cannon explodes by Bill's bullets

}

LPBULLET CCannon::ShootNormalBullet(float angle) {
	LPBULLETN bulletN;
	bulletN = new CBulletN(x, y, angle, false);
	return bulletN;
}

void CCannon::AddBullet() {
	if (isShooting == true) {
		if (this->state == CANNON_STATE_180) {
			bullets.push_back(ShootNormalBullet(180));
		}
		else if (this->state == CANNON_STATE_150) {
			bullets.push_back(ShootNormalBullet(150));
		}
		else if (this->state == CANNON_STATE_120) {
			bullets.push_back(ShootNormalBullet(120));
		}
	}
}

void CCannon::UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	for (int i = 0; i < (int)bullets.size(); i++) {
		if (bullets[i]->outOfScreen() || bullets[i]->IsDeleted()) {
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
		else {
			bullets[i]->Update(dt, coObjects);
		}
	}
}

void CCannon::RenderBullet()
{
	for (int i = 0; i < (int) bullets.size(); i++) {
		bullets[i]->Render();
	}
}
