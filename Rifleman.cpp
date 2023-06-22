#include "Rifleman.h"
#include "Bill.h"
extern int score;
extern CBill* bill;
Rifleman::Rifleman(float x, float y, bool isOnBush) : CGameObject(x, y) {
	if (isOnBush == true) {
		isHiding = true;
		isShooting = false;
	}
	else {
		isHiding = false;
		isShooting = true;
	}
	gunx = x;
	guny = y;
	ny = 0;
	nx = -1;
	angle = 180;
	this->state = RIFLEMAN_STATE_HIDE;
	timeleft = 0;
	waveLeft = 1;
	this->isOnBush = isOnBush;
}

void Rifleman::WatchBill() {

	float x, y;
	bill->GetPosition(x, y);

	float distance_to_Bill = sqrt((this->x - x) * (this->x - x) + (this->y - y) * (this->y - y));
	if (isOnBush == true) {
		if (isHiding == true) {
			if (distance_to_Bill <= RIFLEMAN_ACTIVE_RADIUS) {
				SetState(RIFLEMAN_STATE_EXPOSE);
			}
		}
		else {
			if (distance_to_Bill > RIFLEMAN_ACTIVE_RADIUS) {
				SetState(RIFLEMAN_STATE_HIDE);
			}
		}
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
	// check conditions
	if ((checking_degree >= 0 && checking_degree <= 15) || (checking_degree >= 360 && checking_degree <= 345)) {
		// 0 +-15
		ny = 0;
		nx = 1;
		angle = 0;
		gunx = this->x + 12;
		guny = this->y + 15;
	}
	if (checking_degree >= 165 && checking_degree <= 195) {
		//180 +- 15
		ny = 0;
		nx = -1;
		angle = 180;
		gunx = this->x - 12;
		guny = this->y + 15;
	}
	if (checking_degree >= 210 && checking_degree <= 240) {
		//225 +- 15
		ny = -1;
		nx = -1;
		angle = 225;
		gunx = this->x - 15;
		guny = this->y - 13;
	}
	if (checking_degree >= 120 && checking_degree <= 150) {
		//135 +- 15
		ny = 1;
		nx = -1;
		angle = 135;
		gunx = this->x - 15;
		guny = this->y + 30;
	}
	if (checking_degree >= 30 && checking_degree <= 60) {
		//45 +- 15
		ny = 1;
		nx = 1;
		angle = 45;
		gunx = this->x + 15;
		guny = this->y + 30;
	}
	if (checking_degree >= 300 && checking_degree <= 330) {
		//315 +- 15
		ny = -1;
		nx = 1;
		angle = 315;
		gunx = this->x + 15;
		guny = this->y - 13;
	}
	//DebugOutTitle(L"c_degree = %f", checking_degree);
}

void Rifleman::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	timeleft -= dt;
	if (this->isExploded == true && this->timeleft < 0) {
		isDeleted = true;
		return;
	}
	WatchBill();
	if (timeleft < 0 && isShooting == true) {
		AddBullet();
		timeleft = RIFLEMAN_RELOAD_TIME;
	}
	UpdateBullet(dt, coObjects);
}
void Rifleman::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	if (isHiding) {
		if (nx > 0) {
			ani = RIFLEMAN_ANI_HIDE_RIGHT;
		}
		else if (nx < 0) {
			ani = RIFLEMAN_ANI_HIDE_LEFT;
		}
	}
	else {
		if (nx > 0) {
			if (ny == 1) {
				ani = RIFLEMAN_ANI_AIM_UP_RIGHT;
			}
			if (ny == -1) {
				ani = RIFLEMAN_ANI_AIM_DOWN_RIGHT;
			}
			if (ny == 0) {
				ani = RIFLEMAN_ANI_SHOOT_RIGHT;
			}

		}
		else {
			if (ny == 1) {
				ani = RIFLEMAN_ANI_AIM_UP_LEFT;
			}
			if (ny == -1) {
				ani = RIFLEMAN_ANI_AIM_DOWN_LEFT;
			}
			if (ny == 0) {
				ani = RIFLEMAN_ANI_SHOOT_LEFT;
			}

		}
	}
	if (isExploded) {
		ani = EXPLOSION_1_ANI;
	}
	animations->Get(ani)->Render(x, y);
	RenderBullet();
	//RenderBox();
}
void Rifleman::SetState(int state) {
	switch (state) {
	case RIFLEMAN_STATE_HIDE:
		isShooting = false;
		isHiding = true;
		break;
	case RIFLEMAN_STATE_EXPOSE:
		isHiding = false;
		isShooting = true;
		break;
	case RIFLEMAN_STATE_EXPLODE:
		isShooting = false;
		isHiding = false;
		isExploded = true;
		timeleft = TIME_EXPLODE;
		score += 30;
		break;
	}
	CGameObject::SetState(state);
}
LPBULLET Rifleman::ShootNormalBullet(float angle) {
	LPBULLETN bulletN = new CBulletN(gunx, guny, angle, false);
	return bulletN;
}
void Rifleman::AddBullet() {
	bullets.push_back(ShootNormalBullet(angle));
}
void Rifleman::UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
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
void Rifleman::RenderBullet() {
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Render();
	}
}

void Rifleman::CreateBox(DWORD dt)
{
	if (isHiding)
	{
		bbox.left = x - RIFLEMAN_BOX_HIDE_WIDTH / 2;
		bbox.top = y + RIFLEMAN_BOX_HIDE_HEIGHT / 2;
		bbox.right = x + RIFLEMAN_BOX_HIDE_WIDTH / 2;
		bbox.bottom = y - RIFLEMAN_BOX_HIDE_HEIGHT / 2;
	}
	else
	{
		bbox.left = x - RIFLEMAN_BOX_NORMAL_WIDTH / 2;
		bbox.top = y + RIFLEMAN_BOX_NORMAL_HEIGHT / 2;
		bbox.right = x + RIFLEMAN_BOX_NORMAL_WIDTH / 2;
		bbox.bottom = y - RIFLEMAN_BOX_NORMAL_HEIGHT / 2;
	}
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}
void Rifleman::NoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}
void Rifleman::CollisionWith(LPCOLLISIONEVENT e)
{
}
