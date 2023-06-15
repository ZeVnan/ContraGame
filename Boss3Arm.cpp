#include "Boss3Arm.h"
#include "Bill.h"
extern CBill* bill;
extern int score;
CBoss3Arm::CBoss3Arm(float x, float y, float startAngle) :CGameObject(x, y) {
	HP = 150;
	timeLeft = BOSS3ARM_TIME_SWITCH;
	vr = BOSS3ARM_SPEED_R;
	state = BOSS3ARM_STATE_TURN_LEFT;
	countToShoot = 3;
	float radian = 3.14159 / 180 * startAngle;
	for (int i = 0; i < 5; i++) {
		Boss3ArmPart temp;
		temp.x = x + cos(radian) * i * BOSS3ARM_RADIUS_BASE;
		temp.y = y + sin(radian) * i * BOSS3ARM_RADIUS_BASE;
		temp.angle = startAngle;
		temp.number = i;
		if (i == 4) temp.type = true;
		else temp.type = false;
		parts.push_back(temp);
	}
}
void CBoss3Arm::CalculatePosition(float& x, float& y, float angle, int number) {
	float radian = 3.14159 / 180 * angle;
	x = this->x + cos(radian) * number * BOSS3ARM_RADIUS_BASE;
	y = this->y + sin(radian) * number * BOSS3ARM_RADIUS_BASE;
}
void CBoss3Arm::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (isExploded == false) {
		if (HP <= 0) {
			SetState(BOSS3ARM_STATE_EXPLODE);
		}
		else {
			for (int i = 1; i < parts.size(); i++) {
				if (i == 1) {
					float peri = parts[i].number * BOSS3ARM_RADIUS_BASE * 2 * 3.14159;
					float move_angle = (vr * dt) / peri * 360;
					parts[i].angle += move_angle;
					CalculatePosition(parts[i].x, parts[i].y, parts[i].angle, parts[i].number);
				}
				else {
					if (parts[i - 1].angle - parts[i].angle > 15) {
						parts[i].angle = parts[i - 1].angle - 15;
					}
					if (parts[i].angle - parts[i - 1].angle > 15) {
						parts[i].angle = parts[i - 1].angle + 15;
					}
					CalculatePosition(parts[i].x, parts[i].y, parts[i].angle, parts[i].number);
				}
			}
		}
	}
	
	if (timeLeft > 0) {
		timeLeft -= dt;
	}
	else {
		if (isExploded == false) {
			int a = rand() % 2;
			if (a == 0) {
				SetState(BOSS3ARM_STATE_TURN_LEFT);
			}
			else {
				SetState(BOSS3ARM_STATE_TURN_RIGHT);
			}
			if (countToShoot == 0) {
				AddBullet();
				countToShoot = 3;
			}
			else {
				countToShoot--;
			}
		}
		else {
			isDeleted = true;
		}
	}
	UpdateBullet(dt, coObjects);
}
void CBoss3Arm::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	for (int i = 0; i < parts.size(); i++) {
		if (isExploded == true) {
			animations->Get(EXPLOSION_2_ANI)->Render(parts[i].x, parts[i].y);
			continue;
		}
		if (parts[i].type == false) {
			animations->Get(BOSS3ARM_ANI_ARM)->Render(parts[i].x, parts[i].y);
		}
		else {
			animations->Get(BOSS3ARM_ANI_HAND)->Render(parts[i].x, parts[i].y);
		}
	}
	RenderBullet();
}
void CBoss3Arm::SetState(int state) {
	switch (state) {
	case BOSS3ARM_STATE_TURN_LEFT:
		vr = BOSS3ARM_SPEED_R;
		timeLeft = BOSS3ARM_TIME_SWITCH;
		break;
	case BOSS3ARM_STATE_TURN_RIGHT:
		vr = -BOSS3ARM_SPEED_R;
		timeLeft = BOSS3ARM_TIME_SWITCH;
		break;
	case BOSS3ARM_STATE_EXPLODE:
		isExploded = true;
		vr = 0;
		timeLeft = TIME_EXPLODE;
		score += 50;
		break;
	}
	CGameObject::SetState(state);
}

void CBoss3Arm::CreateBox(DWORD dt) {
	bbox.left = parts[4].x - BOSS3ARM_BOX_WIDTH / 2;
	bbox.top = parts[4].y + BOSS3ARM_BOX_HEIGHT / 2;
	bbox.right = parts[4].x + BOSS3ARM_BOX_WIDTH / 2;
	bbox.bottom = parts[4].y - BOSS3ARM_BOX_HEIGHT / 2;
	float vr_degree = parts[4].angle + 90;
	float vr_rad = 3.14159 / 180 * vr_degree;
	bbox.vpf_x = (cos(vr_rad) * vr * 4) * dt;
	bbox.vpf_y = (sin(vr_rad) * vr * 4) * dt;
}
void CBoss3Arm::NoCollision(DWORD dt) {

}
void CBoss3Arm::CollisionWith(LPCOLLISIONEVENT e) {

}

void CBoss3Arm::AddBullet() {
	float bill_x, bill_y;
	bill->GetPosition(bill_x, bill_y);
	float angle = atan(abs(parts[4].y - bill_y) / abs(parts[4].x - bill_x)) * 180 / 3.14159;
	if (bill_x >= parts[4].x) {
		if (bill_y >= parts[4].y) {
			//not change
		}
		else {
			angle = 270 + (90 - angle);
		}
	}
	else {
		if (bill_y >= parts[4].y) {
			angle = 90 + (90 - angle);
		}
		else {
			angle = 180 + angle;
		}
	}
	bullets.push_back(new CBulletBoss3(parts[4].x, parts[4].y, angle, false));
}
void CBoss3Arm::UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
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
void CBoss3Arm::RenderBullet() {
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Render();
	}
}