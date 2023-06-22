#include "Soldier.h"
#include "Bill.h"
#include "Grass.h"
#include "TriggerBox.h"
#include "Water.h"
#include "BridgePart.h"
#include "Bridge.h"
#include "RockFly.h"
extern LPBILL bill;
extern int score;
CSoldier::CSoldier(float x, float y) :CGameObject(x, y) {
	isLaying = false;
	isShooting = false;
	isOnPlatform = true;
	isJumping = false;
	isActivated = false;
	isDropping = false;
	isInScreenYet = false;
	gunx = x;
	guny = y;
	timeleft = 0;
	nx = -1;
}

void CSoldier::watchBill() {
	float x, y;
	bill->GetPosition(x, y);
	float distance = (float)sqrt(pow(x - this->x, 2) + pow(y - this->y, 2));
	if (distance <= SOLDIER_ACTIVE_RADIUS) {
		if (x < this->x) {
			SetState(SOLDIER_STATE_RUN_LEFT);
		}
		else {
			SetState(SOLDIER_STATE_RUN_RIGHT);
		}
		isActivated = true;
	}
}

bool CSoldier::OutOfScreen() {
	float cx, cy, cw, ch;
	CGame::GetInstance()->GetCamera()->GetCamPos(cx, cy);
	cw = CGame::GetInstance()->GetCamera()->GetCamWidth();
	ch = CGame::GetInstance()->GetCamera()->GetCamHeight();
	if (x < (cx - cw / 2) || x >(cx + cw / 2) || y < (cy - ch / 2))
		return true;
	isInScreenYet = true;
	return false;
}

void CSoldier::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (isActivated == false)
		watchBill();
	if (OutOfScreen() == true && isActivated == true && isInScreenYet == true) {
		isDeleted = true;
		return;
	}
	if (timeleft > 0) {
		timeleft -= dt;
	}
	if (this->isExploded == true) {
		if (this->timeleft <= 0) {
			isDeleted = true;
			return;
		}	
	}
	else {
		if (isShooting == true && timeleft <= 0) {
			SetState(SOLDIER_STATE_SHOOT_RELEASE);
			if (nx > 0)
				SetState(SOLDIER_STATE_RUN_RIGHT);
			else
				SetState(SOLDIER_STATE_RUN_LEFT);
		}
		vy += SOLDIER_GRAVITY * dt;
		CCollision::GetInstance()->Process(this, coObjects, dt);
		isDropping = false;
	}
	UpdateBullet(dt, coObjects);
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
	RenderBullet();
	//RenderBox();
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
	case SOLDIER_STATE_DROP:
		isDropping = true;
		break;
	case SOLDIER_STATE_SHOOT:
		isShooting = true;
		vx = 0;
		timeleft = 500;
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
		isJumping = false;
		timeleft = TIME_EXPLODE;
		score += 30;
		break;
	}
	CGameObject::SetState(State);
}

void CSoldier::CreateBox(DWORD dt)
{
	bbox.left = x - SOLDIER_BOX_RUN_WIDTH / 2;
	bbox.top = y + SOLDIER_BOX_RUN_HEIGHT / 2;
	bbox.right = x + SOLDIER_BOX_RUN_WIDTH / 2;
	bbox.bottom = y - SOLDIER_BOX_RUN_HEIGHT / 2;
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
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
	else if (dynamic_cast<LPBRIDGEPART>(e->dest_obj)) {
		CollisionWithBridge(e);
	}
	else if (dynamic_cast<LPROCKFLY>(e->dest_obj)) {
		CollisionWithRockFly(e);
	}
}
void CSoldier::CollisionWithGrass(LPCOLLISIONEVENT e)
{
	if (e->normal_x != 0) {
		this->x += bbox.vpf_x;
	}
	else if (e->normal_y != 0) {
		if (e->normal_y > 0) {
			if (isDropping == false) {
				SetState(SOLDIER_STATE_ON_LAND);
				this->y += e->time * bbox.vpf_y;
			}
			else {
				this->y += bbox.vpf_y;
			}
		}
		else {
			this->y += bbox.vpf_y;
		}
	}
}
void CSoldier::CollisionWithRockFly(LPCOLLISIONEVENT e) {
	if (e->normal_x != 0) {
		this->x += bbox.vpf_x;
	}
	else if (e->normal_y != 0) {
		if (e->normal_y > 0) {
			if (isDropping == false) {
				SetState(SOLDIER_STATE_ON_LAND);
				this->y += e->time * bbox.vpf_y;
			}
			else {
				this->y += bbox.vpf_y;
			}
		}
		else {
			this->y += bbox.vpf_y;
		}
	}
}
void CSoldier::CollisionWithWater(LPCOLLISIONEVENT e) {
	this->SetState(SOLDIER_STATE_EXPLODE);
}
void CSoldier::CollisionWithTriggerBox(LPCOLLISIONEVENT e) {
	if (OutOfScreen() == true)
		return;
	if (dynamic_cast<LPTRIGGERBOX>(e->dest_obj)->getType() == 1) {
		this->SetState(SOLDIER_STATE_JUMP);
	}
	else if (dynamic_cast<LPTRIGGERBOX>(e->dest_obj)->getType() == 2) {
		this->SetState(SOLDIER_STATE_SHOOT);
		AddBullet();
	}
	else if (dynamic_cast<LPTRIGGERBOX>(e->dest_obj)->getType() == 3) {
		this->SetState(SOLDIER_STATE_DROP);
	}
}
void CSoldier::CollisionWithBridge(LPCOLLISIONEVENT e) {
	if (e->normal_x != 0) {
		this->x += this->GetBox().vpf_x;
	}
	else if (e->normal_y != 0) {
		if (e->normal_y > 0) {
			SetState(SOLDIER_STATE_ON_LAND);
			this->y += e->time * this->GetBox().vpf_y;
		}
		else {
			this->y += this->GetBox().vpf_y;
		}
	}
}

void CSoldier::AddBullet() {
	if (nx > 0) {
		bullets.push_back(new CBulletN(x - 5, y + 18, 0, false));
	}
	else {
		bullets.push_back(new CBulletN(x + 5, y + 18, 180, false));
	}
}
void CSoldier::UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
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
void CSoldier::RenderBullet() {
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Render();
	}
}