#include "Rifleman.h"

Rifleman::Rifleman(float x, float y) : CGameObject(x, y) {
	isShooting = false;
	isHiding = false;
	isActivated = false;
	gunx = x;
	guny = y;
	ny = 0;
	nx = -1;
	this->state = RIFLEMAN_STATE_NORMAL;
	timeleft = 0;
	waveLeft = 1;
}

void Rifleman::WatchBill() {

	float x, y;
	bill->GetPosition(x, y);

	float distance_to_Bill = sqrt((this->x - x) * (this->x - x) + (this->y - y) * (this->y - y));
	if (distance_to_Bill <= RIFLEMAN_ACTIVE_RADIUS) {
		isShooting = true;
		isActivated = true;
	}

	float tan = abs(this->y - y) / abs(this->x - x);// get angle's tan value
	float degree = atan(tan) * 180.0 / M_PI;// transfer to angle degree
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
	}
	if (checking_degree >= 165 && checking_degree <= 195) {
		//180 +- 15
		ny = 0;
		nx = -1;
	}
	if (checking_degree >= 210 && checking_degree <= 240) {
		//225 +- 15
		ny = -1;
		nx = -1;
	}
	if (checking_degree >= 120 && checking_degree <= 150) {
		//135 +- 15
		ny = 1;
		nx = -1;
	}
	if (checking_degree >= 30 && checking_degree <= 60) {
		//45 +- 15
		ny = 1;
		nx = 1;
	}
	if (checking_degree >= 300 && checking_degree <= 330) {
		//315 +- 15
		ny = -1;
		nx = 1;
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
}
void Rifleman::SetState(int state) {
	switch (state) {
	case RIFLEMAN_STATE_NORMAL:
		ny = 0;
		break;
	case RIFLEMAN_STATE_LEFT:
		nx = -1;
		break;
	case RIFLEMAN_STATE_RIGHT:
		nx = 1;
		break;
	case RIFLEMAN_STATE_UP:
		ny = 1;
		break;
	case RIFLEMAN_STATE_DOWN:
		ny = -1;
		break;
	case RIFLEMAN_STATE_HIDING:
		isShooting = false;
		isHiding = true;
		break;
	case RIFLEMAN_STATE_SHOOT:
		isShooting = true;
		break;
	case RIFLEMAN_STATE_SHOOT_RELEASE:
		isShooting = true;
		break;
	case RIFLEMAN_STATE_EXPOSE:
		isHiding = false;
		break;
	case RIFLEMAN_STATE_EXPLODE:
		isShooting = false;
		isHiding = false;
		isExploded = true;
		timeleft = TIME_EXPLODE;
		break;
	}
	CGameObject::SetState(state);
}

int Rifleman::CalculateAngle() {
	if (nx == 1) {
		if (ny == 1)
			return 45;
		if (ny == -1)
			return 315;
		if (ny == 0)
			return 0;
	}
	else {
		if (ny == 1)
			return 135;
		if (ny == -1)
			return 225;
		if (ny == 0)
			return 180;
	}
}
vector<LPBULLET> Rifleman::ShootNormalBullet(int angle) {
	LPBULLETN bulletN = new CBulletN(x, y, angle, false);
	vector<LPBULLET> temp;
	temp.push_back(bulletN);
	return temp;
}
void Rifleman::AddBullet() {
	waveContainer.push_back(ShootNormalBullet(CalculateAngle()));
}
void Rifleman::UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
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
void Rifleman::RenderBullet() {
	for (int i = 0; i < waveContainer.size(); i++) {
		for (int j = 0; j < waveContainer[i].size(); j++) {
			waveContainer[i][j]->Render();
		}
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
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
	else
	{
		bbox.left = x - RIFLEMAN_BOX_NORMAL_WIDTH / 2;
		bbox.top = y + RIFLEMAN_BOX_NORMAL_HEIGHT / 2;
		bbox.right = x + RIFLEMAN_BOX_NORMAL_WIDTH / 2;
		bbox.bottom = y - RIFLEMAN_BOX_NORMAL_HEIGHT / 2;
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
}
void Rifleman::NoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}
void Rifleman::CollisionWith(LPCOLLISIONEVENT e)
{
}
