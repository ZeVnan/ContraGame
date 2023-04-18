#include "Bill.h"
CBill::CBill() :CGameObject() {

}
CBill::CBill(float x, float y) :CGameObject(x, y) {
	isLaying = false;
	isShooting = false;
	isOnPlatform = false;
	ny = 0;
	maxVx = 0.0f;
	maxVy = 0.0f;
	gunx = x;
	guny = y;
	bulletType = BULLET_ANI_NORMAL;
	waveLeft = BILL_WAVE_BULLET_NORMAL;

	bulletMtime = 0;
}
void CBill::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vx = maxVx;
	vy += BILL_GRAVITY * dt;
	if (vx < 0 && x < 10) x = 10;

	if (bulletMtime > 0)
		bulletMtime -= dt;
	else
		bulletMtime = 0;
	UpdateBullet(dt);
	int a = 0;
	for (int i = 0; i < waveContainer.size(); i++) {
		a += waveContainer[i].size();
	}
	isOnPlatform = false;
	CCollision::GetInstance()->Process(this, coObjects, dt);
	//DebugOutTitle(L"vx = %f, vy = %f", vx, vy);
	//DebugOutTitle(L"%d", isOnPlatform);
}
void CBill::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	if (vy != 0) {
		if (nx > 0) {
			ani = BILL_ANI_JUMP_RIGHT;
			gunx = x;
			guny = y;
		}
		else {
			ani = BILL_ANI_JUMP_LEFT;
			gunx = x;
			guny = y;
		}
	}
	else {
		if (isLaying) {
			if (nx > 0) {
				ani = BILL_ANI_LAYDOWN_RIGHT;
				gunx = x + 15.0f;
				guny = y - 10.0f;
			}
			else {
				ani = BILL_ANI_LAYDOWN_LEFT;
				gunx = x - 15.0f;
				guny = y - 10.0f;
			}
		}
		else {
			if (vx == 0) {
				if (ny == 1) {
					if (nx > 0) {
						ani = BILL_ANI_SHOOT_UP_RIGHT;
						gunx = x + 4.0f;
						guny = y + 30.0f;
					}
					else {
						ani = BILL_ANI_SHOOT_UP_LEFT;
						gunx = x - 4.0f;
						guny = y + 30.0f;
					}
				}
				if (ny == 0){
					if (nx > 0) {
						ani = BILL_ANI_NORMAL_RIGHT;
						gunx = x + 10.0f;
						guny = y + 4.5f;
					}	
					else {
						ani = BILL_ANI_NORMAL_LEFT;
						gunx = x - 10.0f;
						guny = y + 4.5f;
					}
						
				}
			}
			else {
				if (vx > 0) {
					if (ny == 0) {
						if (isShooting == true) {
							ani = BILL_ANI_SHOOT_RIGHT;
							gunx = x + 10.0f;
							guny = y + 4.5f;
						}
						else {
							ani = BILL_ANI_RUN_RIGHT;
							gunx = x + 10.0f;
							guny = y + 4.5f;
						}
					}
					if (ny == 1) {
						ani = BILL_ANI_SHOOT_UPRIGHT;
						gunx = x + 10.0f;
						guny = y + 17.0f;
					}
					if (ny == -1) {
						ani = BILL_ANI_SHOOT_DOWNRIGHT;
						gunx = x + 10.0f;
						guny = y - 5.0f;
					}
				}	
				else {
					if (ny == 0){
						if (isShooting == true) {
							ani = BILL_ANI_SHOOT_LEFT;
							gunx = x - 10.0f;
							guny = y + 4.5f;
						}
						else {
							ani = BILL_ANI_RUN_LEFT;
							gunx = x - 10.0f;
							guny = y + 4.5f;
						}
					}
					if (ny == 1) {
						ani = BILL_ANI_SHOOT_UPLEFT;
						gunx = x - 10.0f;
						guny = y + 17.0f;
					}
					if (ny == -1) {
						ani = BILL_ANI_SHOOT_DOWNLEFT;
						gunx = x - 10.0f;
						guny = y - 5.0f;
					}
				}
			}
		}
	}
	if (ani == -1) ani = BILL_ANI_NORMAL_RIGHT;

	float d = 0;
	if (isLaying)
		d = BILL_LAY_HEIGHT_ADJUST;
	if (ny == 1 && vx == 0)
		d = BILL_UP_HEIGHT_ADJUST;
	animations->Get(ani)->Render(x, y + d);
	RenderBullet();
	RenderBox();
}
void CBill::SetState(int state) {
	switch (state) {
	case BILL_STATE_RUN_RIGHT:
		maxVx = BILL_RUN_SPEED;
		nx = 1;
		if (isLaying == true) {
			isLaying = false;
		}
		break;
	case BILL_STATE_RUN_LEFT:
		maxVx = -BILL_RUN_SPEED;
		nx = -1;
		if (isLaying == true) {
			isLaying = false;
		}
		break;
	case BILL_STATE_JUMP:
		if (vy == 0) {
			vy = BILL_JUMP_SPEED_Y;
		}
		break;
	case BILL_STATE_DOWN:
		if (vy == 0) {
			if (vx == 0) {
				isLaying = true;
			}
		}
		ny = -1;
		break;
	case BILL_STATE_DOWN_RELEASE:
		if (vx == 0) {
			isLaying = false;
		}
		ny = 0;
		break;
	case BILL_STATE_UP:
		if (isLaying == true)
			break;
		ny = 1;
		break;
	case BILL_STATE_UP_RELEASE:
		ny = 0;
		break;
	case BILL_STATE_SHOOT:
		isShooting = true;
		break;
	case BILL_STATE_SHOOT_RELEASE:
		isShooting = false;
		break;
	case BILL_STATE_NORMAL:
		maxVx = 0;
		break;
	}
	CGameObject::SetState(state);
}

void CBill::KeyDown(int KeyCode) {
	switch (KeyCode) {
	case DIK_X:
		this->SetState(BILL_STATE_JUMP);
		break;
	case DIK_Z:
		this->SetState(BILL_STATE_SHOOT);
		this->AddBullet(false);
		break;
	case DIK_1:
		this->SetBulletType(BULLET_ANI_NORMAL);
		break;
	case DIK_2:
		this->SetBulletType(BULLET_ANI_FLAME);
		break;
	case DIK_3:
		this->SetBulletType(BULLET_ANI_LASER);
		break;
	case DIK_4:
		this->SetBulletType(BULLET_ANI_SPREAD);
		break;
	case DIK_5:
		this->SetBulletType(BULLET_ANI_MACHINE);
		break;
	}
}
void CBill::KeyUp(int KeyCode) {
	switch (KeyCode) {
	case DIK_Z:
		this->SetState(BILL_STATE_SHOOT_RELEASE);
		break;
	case DIK_DOWN:
		this->SetState(BILL_STATE_DOWN_RELEASE);
		break;
	case DIK_UP:
		this->SetState(BILL_STATE_UP_RELEASE);
		break;
	case DIK_RIGHT:
		this->SetState(BILL_STATE_NORMAL);
		break;
	case DIK_LEFT:
		this->SetState(BILL_STATE_NORMAL);
		break;
	}
}
void CBill::KeyState(CGame* game) {
	BOOLEAN normal = true;
	if (game->IsKeyDown(DIK_Z)) {
		AddBullet(true);
	}
	if (game->IsKeyDown(DIK_DOWN))
	{
		this->SetState(BILL_STATE_DOWN);
		normal = false;
	}
	if (game->IsKeyDown(DIK_UP)) {
		this->SetState(BILL_STATE_UP);
		normal = false;
	}
	if (game->IsKeyDown(DIK_LEFT)){
		this->SetState(BILL_STATE_RUN_LEFT);
		normal = false;
	}
	if (game->IsKeyDown(DIK_RIGHT)){
		this->SetState(BILL_STATE_RUN_RIGHT);
		normal = false;
	}
	if (normal == true)
		this->SetState(BILL_STATE_NORMAL);
}

void CBill::CreateBox(DWORD dt) {
	bbox.left = x - BILL_BOX_NORMAL_WIDTH / 2;
	bbox.top = y - BILL_BOX_NORMAL_HEIGHT / 2;
	bbox.right= x + BILL_BOX_NORMAL_WIDTH / 2;
	bbox.bottom = y + BILL_BOX_NORMAL_HEIGHT / 2;
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}
void CBill::NoCollision(DWORD dt) {
	x += vx * dt;
	y += vy * dt;
}
void CBill::CollisionWith(LPCOLLISIONEVENT e) {
	if (e->normal_y != 0 && e->dest_obj->isBlocking())
	{
		vy = 0;
		if (e->normal_y > 0) isOnPlatform = true;
	}
	else
		if (e->normal_x != 0 && e->dest_obj->isBlocking())
		{
			//vx = 0;
			//DebugOutTitle(L"x = %f", e->dest_obj->GetBox().left);
		}
}

int CBill::CalculateAngle() {
	if (vx > 0) {
		if (ny == 1)
			return 45;
		if (ny == -1)
			return 315;
		if (ny == 0)
			return 0;
	}
	if (vx < 0) {
		if (ny == 1)
			return 135;
		if (ny == -1)
			return 225;
		if (ny == 0)
			return 180;
	}
	if (vx == 0) {
		if (ny == 1)
			return 90;
		if (ny == 0) {
			if (nx == 1)
				return 0;
			else
				return 180;
		}
		if (ny == -1) {
			if (vy != 0) {
				return 270;
			}
			else {
				if (nx == 1)
					return 0;
				else
					return 180;
			}
		}
	}
}
void CBill::AddBullet(BOOLEAN KeyState) {
	if (KeyState == true) {
		if (waveLeft > 0 && bulletType == BULLET_ANI_MACHINE && bulletMtime == 0) {
			waveContainer.push_back(ShootMachineBullet(CalculateAngle()));
			waveLeft--;
			bulletMtime = BULLET_M_TIME;
		}
	}
	else {
		if (waveLeft > 0) {
			int fired = false;
			switch (bulletType) {
			case BULLET_ANI_SPREAD:
				waveContainer.push_back(ShootSpreadBullet(CalculateAngle()));
				fired = true;
				break;
			case BULLET_ANI_LASER:
				waveContainer.push_back(ShootLaserBullet(CalculateAngle()));
				fired = true;
				break;
			case BULLET_ANI_FLAME:
				waveContainer.push_back(ShootFlameBullet(CalculateAngle()));
				fired = true;
				break;
			case BULLET_ANI_NORMAL:
				waveContainer.push_back(ShootNormalBullet(CalculateAngle()));
				fired = true;
				break;
			case BULLET_ANI_MACHINE:
				if (bulletMtime == 0) {
					waveContainer.push_back(ShootMachineBullet(CalculateAngle()));
					fired = true;
					bulletMtime = BULLET_M_TIME;
				}
				break;
			}
			if (fired == true)
				waveLeft--;
		}
		else {
			if (bulletType == BULLET_ANI_LASER) {
				waveContainer.clear();
				waveContainer.push_back(ShootLaserBullet(CalculateAngle()));
			}
		}
	}
}
vector<LPBULLET> CBill::ShootSpreadBullet(int angle) {
	LPBULLETS bulletS;
	vector<LPBULLET> temp;
	bulletS = new CBulletS(gunx, guny, angle);
	temp.push_back(bulletS);
	bulletS = new CBulletS(gunx, guny, angle - 15);
	temp.push_back(bulletS);
	bulletS = new CBulletS(gunx, guny, angle + 15);
	temp.push_back(bulletS);
	bulletS = new CBulletS(gunx, guny, angle - 30);
	temp.push_back(bulletS);
	bulletS = new CBulletS(gunx, guny, angle + 30);
	temp.push_back(bulletS);
	return temp;
}
vector<LPBULLET> CBill::ShootLaserBullet(int angle) {
	LPBULLETL bulletL;
	vector<LPBULLET> temp;
	bulletL = new CBulletL(gunx, guny, angle, 1);
	temp.push_back(bulletL);
	bulletL = new CBulletL(gunx, guny, angle, 2);
	temp.push_back(bulletL);
	bulletL = new CBulletL(gunx, guny, angle, 3);
	temp.push_back(bulletL);
	bulletL = new CBulletL(gunx, guny, angle, 4);
	temp.push_back(bulletL);
	return temp;
}
vector<LPBULLET> CBill::ShootFlameBullet(int angle) {
	LPBULLETF bulletF;
	vector<LPBULLET> temp;
	bulletF = new CBulletF(gunx, guny, angle);
	temp.push_back(bulletF);
	return temp;
}
vector<LPBULLET> CBill::ShootNormalBullet(int angle) {
	LPBULLETN bulletN = new CBulletN(gunx, guny, angle);
	vector<LPBULLET> temp;
	temp.push_back(bulletN);
	return temp;
}
vector<LPBULLET> CBill::ShootMachineBullet(int angle) {
	LPBULLETM bulletM = new CBulletM(gunx, guny, angle);
	vector <LPBULLET> temp;
	temp.push_back(bulletM);
	return temp;
}

void CBill::SetBulletType(int type) {
	switch (type) {
	case BULLET_ANI_NORMAL:
		waveLeft = BILL_WAVE_BULLET_NORMAL;
		break;
	case BULLET_ANI_LASER:
		waveLeft = BILL_WAVE_BULLET_LASER;
		break;
	case BULLET_ANI_FLAME:
		waveLeft = BILL_WAVE_BULLET_FLAME;
		break;
	case BULLET_ANI_SPREAD:
		waveLeft = BILL_WAVE_BULLET_SPREAD;
		break;
	case BULLET_ANI_MACHINE:
		waveLeft = BILL_WAVE_BULLET_MACHINE;
		break;
	}
	waveLeft -= waveContainer.size();
	this->bulletType = type;
}
void CBill::UpdateBullet(DWORD dt) {
	for (int i = 0; i < waveContainer.size(); i++) {
		if (waveContainer[i].size() > 0) {
			for (int j = 0; j < waveContainer[i].size(); j++) {
				if (waveContainer[i][j]->outOfScreen())
					waveContainer[i].erase(waveContainer[i].begin() + j);
				else
					waveContainer[i][j]->Update(dt);
			}
		}
		if (waveContainer[i].size() == 0) {
			waveContainer.erase(waveContainer.begin() + i);
			waveLeft++;
		}
	}
}
void CBill::RenderBullet() {
	for (int i = 0; i < waveContainer.size(); i++) {
		for (int j = 0; j < waveContainer[i].size(); j++) {
			waveContainer[i][j]->Render();
		}
	}
}
