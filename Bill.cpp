#include "Bill.h"

void CBill::Update(DWORD dt) {
	x += vx * dt;
	y += vy * dt;

	vx = maxVx;
	if (y >= GROUND_Y) {
		vy = 0;
		y = GROUND_Y;
	}
	else {
		vy += BILL_GRAVITY * dt;
	}
	

	DebugOutTitle(L"bullets = %d", bullets.size());

	
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 10) x = 10;
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i]->outOfScreen())
			this->DelBullet();
		else
			bullets[i]->Update(dt);
	}
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
				guny = y + 10.0f;
			}
			else {
				ani = BILL_ANI_LAYDOWN_LEFT;
				gunx = x - 15.0f;
				guny = y + 10.0f;
			}
		}
		else {
			if (vx == 0) {
				if (ny == 1) {
					if (nx > 0) {
						ani = BILL_ANI_SHOT_UP_RIGHT;
						gunx = x + 4.0f;
						guny = y - 30.0f;
					}
					else {
						ani = BILL_ANI_SHOT_UP_LEFT;
						gunx = x - 4.0f;
						guny = y - 30.0f;
					}
				}
				if (ny == 0){
					if (nx > 0) {
						ani = BILL_ANI_NORMAL_RIGHT;
						gunx = x + 10.0f;
						guny = y - 4.5f;
					}	
					else {
						ani = BILL_ANI_NORMAL_LEFT;
						gunx = x - 10.0f;
						guny = y - 4.5f;
					}
						
				}
			}
			else {
				if (vx > 0) {
					if (ny == 0) {
						if (isShooting == true) {
							ani = BILL_ANI_SHOT_RIGHT;
							gunx = x + 10.0f;
							guny = y - 4.5f;
						}
						else {
							ani = BILL_ANI_RUN_RIGHT;
							gunx = x + 10.0f;
							guny = y - 4.5f;
						}
					}
					if (ny == 1) {
						ani = BILL_ANI_SHOT_UPRIGHT;
						gunx = x + 10.0f;
						guny = y - 17.0f;
					}
					if (ny == -1) {
						ani = BILL_ANI_SHOT_DOWNRIGHT;
						gunx = x + 10.0f;
						guny = y + 5.0f;
					}
				}	
				else {
					if (ny == 0){
						if (isShooting == true) {
							ani = BILL_ANI_SHOT_LEFT;
							gunx = x - 10.0f;
							guny = y - 4.5f;
						}
						else {
							ani = BILL_ANI_RUN_LEFT;
							gunx = x - 10.0f;
							guny = y - 4.5f;
						}
					}
					if (ny == 1) {
						ani = BILL_ANI_SHOT_UPLEFT;
						gunx = x - 10.0f;
						guny = y - 17.0f;
					}
					if (ny == -1) {
						ani = BILL_ANI_SHOT_DOWNLEFT;
						gunx = x - 10.0f;
						guny = y + 5.0f;
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
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Render();
	}
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
		if (y == GROUND_Y) {
			vy = -BILL_JUMP_SPEED_Y;
		}
		break;
	case BILL_STATE_JUMP_RELEASE:
		if (vy < 0)
			vy += BILL_JUMP_SPEED_Y / 2;
		break;
	case BILL_STATE_DOWN:
		if (y == GROUND_Y) {
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
	case BILL_STATE_SHOT:
		isShooting = true;
		break;
	case BILL_STATE_SHOT_RELEASE:
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
		this->SetState(BILL_STATE_SHOT);
		this->AddBullet();
		break;
	}
}
void CBill::KeyUp(int KeyCode) {
	switch (KeyCode) {
	case DIK_X:
		this->SetState(BILL_STATE_JUMP_RELEASE);
		break;
	case DIK_Z:
		this->SetState(BILL_STATE_SHOT_RELEASE);
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

void CBill::AddBullet() {
	
	LPBULLET bullet = new CBullet(this->gunx, this->guny, this->vx, this->vy, this->nx, this->ny, this->bulletType);
	this->bullets.push_back(bullet);
}
void CBill::DelBullet() {
	this->bullets.erase(bullets.begin());
}