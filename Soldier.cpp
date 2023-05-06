#include "Soldier.h"

CSoldier::CSoldier() :CGameObject() {

}
CSoldier::CSoldier(float x, float y) :CGameObject(x, y) {
	isLaying = false;
	isShooting = false;
	maxVx = SOLDIER_RUN_SPEED;
	maxVy = 0.0f;
	gunx = x;
	guny = y;
}
void CSoldier::Update(DWORD dt) {
	x += vx * dt;
	y += vy * dt;

	//DebugOutTitle(L"x = %f", this->x);
	vx = maxVx;
	if (y >= GROUND_Y) {
		vy = 0;
		y = GROUND_Y;
	}
	else {
		vy += SOLDIER_GRAVITY * dt;
	}
	if (vx > 0 && x > 290) this->SetState(SOLDIER_STATE_RUN_LEFT);
	if (vx < 0 && x < 10) this->SetState(SOLDIER_STATE_RUN_RIGHT);

	if (x > 73 && x < 77 || x > 223 && x < 227) this->SetState(SOLDIER_STATE_JUMP);
}
void CSoldier::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	if (vy != 0) {
		if (nx > 0) {
			ani = SOLDIER_ANI_JUMP_RIGHT;
		}
		else {
			ani = SOLDIER_ANI_JUMP_LEFT;
		}
	}
	else {
		if (isLaying) {
			if (nx > 0) {
				ani = SOLDIER_ANI_LAYDOWN_RIGHT;
			}
			else {
				ani = SOLDIER_ANI_LAYDOWN_LEFT;
			}
		}
		else {
			if (vx == 0) {
				if (nx > 0) {
					ani = SOLDIER_ANI_SHOOT_RIGHT;
				}
				else {
					ani = SOLDIER_ANI_SHOOT_LEFT;
				}
			}
			if (vx > 0) {
				ani = SOLDIER_ANI_RUN_RIGHT;
			}
			if (vx < 0) {
				ani = SOLDIER_ANI_RUN_LEFT;
			}
		}
	}
	float d = 0;
	if (isLaying)
		d = SOLDIER_LAY_HEIGHT_ADJUST;
	animations->Get(ani)->Render(x, y);
}
void CSoldier::SetState(int State) {
	switch (State) {
	case SOLDIER_STATE_RUN_RIGHT:
		maxVx = SOLDIER_RUN_SPEED;
		nx = 1;
		if (isLaying == true) {
			isLaying = false;
		}
		break;
	case SOLDIER_STATE_RUN_LEFT:
		maxVx = -SOLDIER_RUN_SPEED;
		nx = -1;
		if (isLaying == true) {
			isLaying = false;
		}
		break;
	case SOLDIER_STATE_JUMP:
		if (vy == 0) {
			vy = -SOLDIER_JUMP_SPEED_Y;
		}
		break;
	case SOLDIER_STATE_JUMP_RELEASE:
		if(vy < 0)
			vy += SOLDIER_JUMP_SPEED_Y / 2;
		break;
	case SOLDIER_STATE_SHOOT:
		isShooting = true;
		break;
	case SOLDIER_STATE_SHOOT_RELEASE:
		isShooting = false;
		break;
	case SOLDIER_STATE_LAYDOWN:
		isLaying = true;
		break;
	case SOLDIER_STATE_LAYDOWN_RELEASE:
		isLaying = false;
		break;
	}
	CGameObject::SetState(state);
}

void CSoldier::CreateBox(DWORD dt)
{
	if (isShooting) 
	{
		bbox.left = x - SOLDIER_BOX_SHOOT_WIDTH / 2;
		bbox.top = y - SOLDIER_BOX_SHOOT_HEIGHT / 2;
		bbox.right = x + SOLDIER_BOX_SHOOT_WIDTH / 2;
		bbox.bottom = y + SOLDIER_BOX_SHOOT_HEIGHT / 2;
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
	else if (isLaying)
	{
		bbox.left = x - SOLDIER_BOX_LAY_WIDTH / 2;
		bbox.top = y - SOLDIER_BOX_LAY_HEIGHT / 2;
		bbox.right = x + SOLDIER_BOX_LAY_WIDTH / 2;
		bbox.bottom = y + SOLDIER_BOX_LAY_HEIGHT / 2;
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
	else
	{
		bbox.left = x - SOLDIER_BOX_RUN_WIDTH / 2;
		bbox.top = y - SOLDIER_BOX_RUN_HEIGHT / 2;
		bbox.right = x + SOLDIER_BOX_RUN_WIDTH / 2;
		bbox.bottom = y + SOLDIER_BOX_RUN_HEIGHT / 2;
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
}

void CSoldier::NoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CSoldier::CollisionWith(LPCOLLISIONEVENT e)
{
}
