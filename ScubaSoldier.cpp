#include "ScubaSoldier.h"
#include "bill.h"
extern CBill* bill;

CScubaSoldier::CScubaSoldier(float x, float y) :CGameObject(x, y) {
	this->SetState(SCUBA_STATE_HIDING);
	timeleft = SCUBA_HIDING_TIME;
	isHiding = true;
	isShooting = false;
}

void CScubaSoldier::watchBill()
{
	float Bill_x, Bill_y;
	bill->GetPosition(Bill_x, Bill_y);
	if (!isActivated) {
		if (Bill_y > this->y) {
			isActivated = true;
		}
	}
}

void CScubaSoldier::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	
	watchBill();
	if (this->isExploded == true && this->timeleft < 0) {
		isDeleted = true;
		return;
	}
	if (timeleft > 0) {
		this->timeleft -= dt;
	}
	else {
		if (isActivated) {
			if(!isHiding){
				this->SetState(SCUBA_STATE_SHOOTING);
				isHiding = true;
			}
			else {
				this->SetState(SCUBA_STATE_HIDING);
				isHiding = false;
			}
			AddBullet();
		}
		else {
			return;
		}
	}
	UpdateBullet(dt, coObjects);
	//DebugOutTitle(L"state = %d, timeleft = %d", this->state, this->timeleft);
}

void CScubaSoldier::Render()
{
	if (!isActivated && !isHiding) {
		return;
	}
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	switch(this->state)
	{
	case SCUBA_STATE_HIDING:
		ani = SCUBA_ANI_HIDE_RIGHT;
		isExploded = false;
		break;
	case SCUBA_STATE_SHOOTING:
		ani = SCUBA_ANI_SHOOT_RIGHT;
		break;
	}
	if (isExploded) {
		ani = EXPLOSION_1_ANI;
	}
	animations->Get(ani)->Render(x, y);
	RenderBullet();
}

void CScubaSoldier::SetState(int state)
{
	switch (state)
	{
	case SCUBA_STATE_HIDING:
		timeleft = SCUBA_HIDING_TIME;
		isHiding = true;
		isShooting = false;
		break;
	case SCUBA_STATE_SHOOTING:
		timeleft = SCUBA_SHOOTING_TIME;
		isShooting = true;
		isHiding = false;
		break;
	case SCUBA_STATE_EXPLODE:
		isHiding = false;
		isExploded = true;
		timeleft = TIME_EXPLODE;
		break;
	}
	CGameObject::SetState(state);
}

void CScubaSoldier::CreateBox(DWORD dt)
{
	if (isHiding)
	{
		bbox.left = x - SCUBA_BOX_HIDE_WIDTH / 2;
		bbox.top = y - SCUBA_BOX_HIDE_HEIGHT / 2;
		bbox.right = x + SCUBA_BOX_HIDE_WIDTH / 2;
		bbox.bottom = y + SCUBA_BOX_HIDE_HEIGHT / 2;
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
	else
	{
		bbox.left = x - SCUBA_BOX_SHOOT_WIDTH / 2;
		bbox.top = y - SCUBA_BOX_SHOOT_HEIGHT / 2;
		bbox.right = x + SCUBA_BOX_SHOOT_WIDTH / 2;
		bbox.bottom = y + SCUBA_BOX_SHOOT_HEIGHT / 2;
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
	
}

void CScubaSoldier::NoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CScubaSoldier::CollisionWith(LPCOLLISIONEVENT e)
{
}

vector<LPBULLET> CScubaSoldier::ShootNormalBullet(int angle) {
	LPBULLETN bulletN;
	vector<LPBULLET> temp;
	bulletN = new CBulletN(x, y, angle, false);
	temp.push_back(bulletN);
	return temp;
}

void CScubaSoldier::AddBullet()
{
	if(this->state == SCUBA_STATE_SHOOTING)
		waveContainer.push_back(ShootNormalBullet(90));
}

void CScubaSoldier::UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
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
	//waveContainer.push_back(ShootNormalBullet(180));
	CCollision::GetInstance()->Process(this, coObjects, dt);
}

void CScubaSoldier::RenderBullet()
{
	for (int i = 0; i < waveContainer.size(); i++) {
		for (int j = 0; j < waveContainer[i].size(); j++) {
			waveContainer[i][j]->Render();
		}
	}
}