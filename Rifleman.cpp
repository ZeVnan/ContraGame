#include "Rifleman.h"

Rifleman::Rifleman() {}

Rifleman::Rifleman(float x, float y) : CGameObject(x, y) {
	isShooting = true;
	isHiding = false;
	gunx = x;
	guny = y;
	ny = 0;
	nx = -1;
	this->state = RIFLEMAN_STATE_NORMAL;
	timeleft = RIFLEMAN_SWITCH_TIME;
}

void Rifleman::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	timeleft -= dt;
	if (this->isExploded == true && this->timeleft < 0) {
		isDeleted = true;
		return;
	}
	if (timeleft < 0) {
		switch (this->state) {
		case RIFLEMAN_STATE_NORMAL:
			this->SetState(RIFLEMAN_STATE_UP);
			timeleft = RIFLEMAN_SWITCH_TIME;
			break;
		case RIFLEMAN_STATE_UP:
			this->SetState(RIFLEMAN_STATE_DOWN);
			timeleft = RIFLEMAN_SWITCH_TIME;
			AddBullet();
			break;
		case RIFLEMAN_STATE_DOWN:
			this->SetState(RIFLEMAN_STATE_NORMAL);
			timeleft = RIFLEMAN_SWITCH_TIME;
			AddBullet();
			break;
		}
		AddBullet();
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
		else {
			ani = RIFLEMAN_ANI_HIDE_LEFT;
		}
	}
	else {
		if (nx > 0) {
			if (isShooting) {
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
			else
				ani = RIFLEMAN_ANI_NORMAL_RIGHT;
		}
		else {
			if (isShooting) {
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
			else
				ani = RIFLEMAN_ANI_NORMAL_LEFT;
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
		bbox.top = y - RIFLEMAN_BOX_HIDE_HEIGHT / 2;
		bbox.right = x + RIFLEMAN_BOX_HIDE_WIDTH / 2;
		bbox.bottom = y + RIFLEMAN_BOX_HIDE_HEIGHT / 2;
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
	else
	{
		bbox.left = x - RIFLEMAN_BOX_NORMAL_WIDTH / 2;
		bbox.top = y - RIFLEMAN_BOX_NORMAL_HEIGHT / 2;
		bbox.right = x + RIFLEMAN_BOX_NORMAL_WIDTH / 2;
		bbox.bottom = y + RIFLEMAN_BOX_NORMAL_HEIGHT / 2;
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
