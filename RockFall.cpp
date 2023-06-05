#include "RockFall.h"
#include "Bill.h"
#include "Grass.h"
extern CBill* bill;

CRockFall::CRockFall(float x, float y) : CGameObject(x, y)
{
	isFalling = false;
	isActivated = false;
	timeLeft = ROCKFALL_READY_TIME;
	vy = 0;
}

BOOLEAN CRockFall::outOfScreen()
{
	float cx, cy, cw, ch;
	CGame::GetInstance()->GetCamera()->GetCamPos(cx, cy);
	cw = CGame::GetInstance()->GetCamera()->GetCamWidth();
	ch = CGame::GetInstance()->GetCamera()->GetCamHeight();
	if (x < (cx - cw / 2) || x >(cx + cw / 2) || y < (cy - ch / 2) || y >(cy + ch / 2))
		return true;
	return false;
}

void CRockFall::watchBill()
{
	float Bill_x, Bill_y;
	bill->GetPosition(Bill_x, Bill_y);
	if (!isActivated) {
		if (abs(Bill_y - this->y) <= ROCKFALL_ACTIVE_RADIUS) {
			isActivated = true;
		}
	}
}

void CRockFall::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	watchBill();
	if (!isActivated) {
		return;
	}
	this->SetState(ROCKFALL_STATE_NORMAL);
	if (timeLeft >= 0) {
		timeLeft -= dt;
	}
	if(timeLeft < 0) {
			this->SetState(ROCKFALL_STATE_FALLING);
			vy += ROCKFALL_GRAVITY * dt;
			y -= vy * dt;
	}
	CCollision::GetInstance()->Process(this, coObjects, dt);
}

void CRockFall::Render()
{
	if (!isActivated) {
		return;
	}
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;

	switch (this->state) {
		case ROCKFALL_STATE_NORMAL:
			ani = ROCKFALL_ANI_NORMAL;
			break;
		case ROCKFALL_STATE_FALLING:
			ani = ROCKFALL_ANI_FALLING;
			break;
	}
	animations->Get(ani)->Render(x, y);
	RenderBox();
}

void CRockFall::SetState(int state)
{
	switch (state) {
		case ROCKFALL_STATE_NORMAL:
			vy = 0;
			break;
		case ROCKFALL_STATE_FALLING:
			vy = ROCKFALL_SPEED_Y;
			break;
	}
	CGameObject::SetState(state);
}

void CRockFall::CreateBox(DWORD dt)
{
	bbox.left = x - ROCKFALL_BBOX_WIDTH / 2;
	bbox.top = y - ROCKFALL_BBOX_HEIGHT / 2;
	bbox.right = x + ROCKFALL_BBOX_WIDTH / 2;
	bbox.bottom = y + ROCKFALL_BBOX_HEIGHT / 2;
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}

void CRockFall::NoCollision(DWORD dt)
{
	vy += ay * dt;
	y += vy * dt;
}

void CRockFall::CollisionWith(LPCOLLISIONEVENT e)
{
	if (dynamic_cast<LPGRASS>(e->dest_obj)) {
		CollisionWithGrass(e);
	}
	if (dynamic_cast<LPBILL>(e->dest_obj)) {
		CollisionWithBill(e);
	}
}

void CRockFall::CollisionWithGrass(LPCOLLISIONEVENT e)
{
	e->src_obj->Delete();
	//DebugOutTitle(L"Collision with grass");
}

void CRockFall::CollisionWithBill(LPCOLLISIONEVENT e)
{
	if ((LPBILL(e->dest_obj))->IsDiving() == true ||
		(LPBILL(e->dest_obj))->IsVulnerable() == false ||
		(LPBILL(e->dest_obj))->IsDead() == true)
		return;
	e->src_obj->Delete();
	(LPBILL(e->dest_obj))->SetState(BILL_STATE_DYING_RIGHT);
}
