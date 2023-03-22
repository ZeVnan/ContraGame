#include "Bill.h"

void CBill::Update(DWORD dt) {
	x += vx * dt;
	y += vy * dt;

	vy += BILL_GRAVITY * dt;
	vx = maxVx;

	if (abs(vx) > abs(maxVx))
		vx = maxVx;
	DebugOutTitle(L"updown = %d", this->updown);

	if (y > GROUND_Y) {
		vy = 0;
		y = GROUND_Y;
	}
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;
}
void CBill::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	if (y < GROUND_Y) {
		if (nx > 0)
			aniId = BILL_ANI_JUMP_RIGHT;
		else
			aniId = BILL_ANI_JUMP_LEFT;
	}
	else {
		if (isLaying) {
			if (nx > 0)
				aniId = BILL_ANI_LAYDOWN_RIGHT;
			else
				aniId = BILL_ANI_LAYDOWN_LEFT;
		}
		else {
			if (vx == 0) {
				if (updown == 1) {
					if (nx > 0)
						aniId = BILL_ANI_SHOT_UP_RIGHT;
					else
						aniId = BILL_ANI_SHOT_UP_LEFT;
				}
				if (updown == 0){
					if (nx > 0)
						aniId = BILL_ANI_NORMAL_RIGHT;
					else
						aniId = BILL_ANI_NORMAL_LEFT;
				}
			}
			else {
				if (vx > 0) {
					if (updown == 0) {
						if (isShooting == true)
							aniId = BILL_ANI_SHOT_RIGHT;
						else
							aniId = BILL_ANI_RUN_RIGHT;
					}
					if (updown == 1)
						aniId = BILL_ANI_SHOT_UPRIGHT;
					if (updown == -1)
						aniId = BILL_ANI_SHOT_DOWNRIGHT;
				}	
				else {
					if (updown == 0){
						if (isShooting == true)
							aniId = BILL_ANI_SHOT_LEFT;
						else
							aniId = BILL_ANI_RUN_LEFT;
					}
					if (updown == 1)
						aniId = BILL_ANI_SHOT_UPLEFT;
					if (updown == -1)
						aniId = BILL_ANI_SHOT_DOWNLEFT;
				}
					
			}
		}
	}
	if (aniId == -1) aniId = BILL_ANI_NORMAL_RIGHT;

	float d = 0;
	if (isLaying)
		d = BILL_LAY_HEIGHT_ADJUST;
	animations->Get(aniId)->Render(x, y + d);
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
		updown = -1;
		break;
	case BILL_STATE_DOWN_RELEASE:
		if (vx == 0) {
			isLaying = false;
		}
		updown = 0;
		break;
	case BILL_STATE_UP:
		updown = 1;
		break;
	case BILL_STATE_UP_RELEASE:
		updown = 0;
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