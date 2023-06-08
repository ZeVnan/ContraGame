#include "Soldier.h"


CSoldier::CSoldier(float x, float y) :CGameObject(x, y) {
	isLaying = false;
	isShooting = false;
	isOnPlatform = true;
	isDropping = false;
	isJumping = false;
	this->SetState(SOLDIER_STATE_RUN_LEFT);
	maxVx = SOLDIER_RUN_SPEED;
	maxVy = SOLDIER_GRAVITY;
	gunx = x;
	guny = y;
}
void CSoldier::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	timeleft -= dt;
	if (this->isExploded == true && this->timeleft < 0) {
		isDeleted = true;
		return;
	}

	if (this->state == SOLDIER_STATE_EXPLODE) {
		vy = 0;
	}
	else {
		vy += SOLDIER_GRAVITY * dt;
		CCollision::GetInstance()->Process(this, coObjects, dt);
	}

	if (this->state == SOLDIER_STATE_RUN_LEFT) {
		x += vx * dt;
	}
	else if (this->state == SOLDIER_STATE_JUMP) {
		//this->SetState(SOLDIER_STATE_JUMP_RELEASE);
	}


	//DebugOutTitle(L"timeleft = %f", this->timeleft);
}
void CSoldier::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;


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
		else if (vx > 0) {
			ani = SOLDIER_ANI_RUN_RIGHT;
		}
		else if (vx < 0) {
			ani = SOLDIER_ANI_RUN_LEFT;
		}
	}
	if (vy != 0) {
		if (nx > 0) {
			ani = SOLDIER_ANI_JUMP_RIGHT;
		}
		else {
			ani = SOLDIER_ANI_JUMP_LEFT;
		}
	}

	float d = 0;
	if (isLaying)
		d = SOLDIER_LAY_HEIGHT_ADJUST;
	if (isExploded) {
		ani = EXPLOSION_1_ANI;
	}

	animations->Get(ani)->Render(x, y);
	RenderBox();
}
void CSoldier::SetState(int State) {
	switch (State) {
	case SOLDIER_STATE_ON_LAND:
		isOnPlatform = true;
		isJumping = false;
		vy = 0;
		break;
	case SOLDIER_STATE_RUN_RIGHT:
		vx = SOLDIER_RUN_SPEED;
		nx = 1;
		if (isLaying == true) {
			isLaying = false;
		}
		break;
	case SOLDIER_STATE_RUN_LEFT:
		isOnPlatform = true;
		vx = -SOLDIER_RUN_SPEED;
		nx = -1;
		if (isLaying == true) {
			isLaying = false;
		}
		break;
	case SOLDIER_STATE_JUMP:
		vy = SOLDIER_JUMP_SPEED_Y;
		isOnPlatform = false;
		isJumping = true;
		break;
	case SOLDIER_STATE_JUMP_RELEASE:
		vy = -SOLDIER_GRAVITY;
		if (vy < 0)
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
		vx = 0;
		vy = 0;
		break;
	case SOLDIER_STATE_LAYDOWN_RELEASE:
		isLaying = false;
		break;
	case SOLDIER_STATE_EXPLODE:
		isExploded = true;
		isShooting = false;
		isLaying = false;
		isDropping = false;
		isJumping = false;
		timeleft = TIME_EXPLODE;
		break;
	}
	CGameObject::SetState(State);
}

void CSoldier::CreateBox(DWORD dt)
{
	if (isShooting)
	{
		bbox.left = x - SOLDIER_BOX_SHOOT_WIDTH / 2;
		bbox.top = y + SOLDIER_BOX_SHOOT_HEIGHT / 2;
		bbox.right = x + SOLDIER_BOX_SHOOT_WIDTH / 2;
		bbox.bottom = y - SOLDIER_BOX_SHOOT_HEIGHT / 2;
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
	else if (isLaying)
	{
		bbox.left = x - SOLDIER_BOX_LAY_WIDTH / 2;
		bbox.top = y + SOLDIER_BOX_LAY_HEIGHT / 2;
		bbox.right = x + SOLDIER_BOX_LAY_WIDTH / 2;
		bbox.bottom = y - SOLDIER_BOX_LAY_HEIGHT / 2;
		bbox.vpf_x = vx * dt;
		bbox.vpf_y = vy * dt;
	}
	else {
		bbox.left = x - SOLDIER_BOX_RUN_WIDTH / 2;
		bbox.top = y + SOLDIER_BOX_RUN_HEIGHT / 2;
		bbox.right = x + SOLDIER_BOX_RUN_WIDTH / 2;
		bbox.bottom = y - SOLDIER_BOX_RUN_HEIGHT / 2;
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
	if (dynamic_cast<LPGRASS>(e->dest_obj)) {
		CollisionWithGrass(e);
	}
	else if (dynamic_cast<LPWATER>(e->dest_obj)) {
		CollisionWithWater(e);
	}
	else if (dynamic_cast<LPTRIGGERBOX>(e->dest_obj)) {
		CollisionWithTriggerBox(e);
	}
}
void CSoldier::CollisionWithGrass(LPCOLLISIONEVENT e)
{
	if (e->normal_x != 0) {
		//this->x += e->time * this->GetBox().vpf_x;
		this->x += this->GetBox().vpf_x;
	}
	else if (e->normal_y != 0) {
		if (e->normal_y > 0) {
			if (isDropping == false) {
				//support change bbox
				if (isJumping == true) {
					isJumping = false;
					y += 15.0f;

					this->y += e->time * bbox.vpf_y;
					SetState(SOLDIER_STATE_ON_LAND);
				}
				else {
					vy = 0;
					this->y += e->time * this->GetBox().vpf_y;
				}
			}
			else {
				this->y += this->GetBox().vpf_y;
			}
		}
	}
}
void CSoldier::CollisionWithWater(LPCOLLISIONEVENT e) {
	this->SetState(SOLDIER_STATE_EXPLODE);
}
void CSoldier::CollisionWithTriggerBox(LPCOLLISIONEVENT e) {
	if (dynamic_cast<LPTRIGGERBOX>(e->dest_obj)->getType() == 1) {
		this->SetState(SOLDIER_STATE_JUMP);
	}
	else if (dynamic_cast<LPTRIGGERBOX>(e->dest_obj)->getType() == 2) {
		this->SetState(SOLDIER_STATE_SHOOT);
	}
	else if (dynamic_cast<LPTRIGGERBOX>(e->dest_obj)->getType() == 3) {
		this->SetState(SOLDIER_STATE_LAYDOWN);
	}
}