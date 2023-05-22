#include "Boss1Gun.h"
CBoss1Gun::CBoss1Gun(float x, float y) :CGameObject(x, y) {
	HP = 300;
	timeLeft = 0;
}
void CBoss1Gun::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (isExploded == false) {
		timeLeft -= dt;
		if (timeLeft <= 0) {
			AddBullet();
			timeLeft = BOSS1GUN_TIME_SHOOT;
		}
		if (HP <= 0) {
			SetState(BOSS1GUN_STATE_EXPLODE);
		}
	}
	else {
		timeLeft -= dt;
		if (timeLeft <= 0) {
			isDeleted = true;
		}
	}
	UpdateBullet(dt, coObjects);
}
void CBoss1Gun::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani;
	if (isExploded == false) {
		ani = BOSS1GUN_ANI_NORMAL;
	}
	else {
		ani = EXPLOSION_2_ANI;
	}
	animations->Get(ani)->Render(x, y);
	RenderBox();
	RenderBullet();
}

void CBoss1Gun::SetState(int state) {
	switch (state) {
	case BOSS1GUN_STATE_NORMAL:

		break;
	case BOSS1GUN_STATE_EXPLODE:
		isExploded = true;
		timeLeft = 3 * TIME_EXPLODE;
		break;
	}
	CGameObject::SetState(state);
}
void CBoss1Gun::CreateBox(DWORD dt) {
	bbox.left = x - BOSS1GUN_BOX_WIDTH / 2;
	bbox.top = y - BOSS1GUN_BOX_HEIGHT / 2;
	bbox.right = x + BOSS1GUN_BOX_WIDTH / 2;
	bbox.bottom = y + BOSS1GUN_BOX_HEIGHT / 2;
	bbox.vpf_x = 0;
	bbox.vpf_y = 0;
}
void CBoss1Gun::NoCollision(DWORD dt) {

}
void CBoss1Gun::CollisionWith(LPCOLLISIONEVENT e) {

}

void CBoss1Gun::AddBullet() {
	bulletContainer.push_back(new CBulletBoss1(x, y, 180, false));
}
void CBoss1Gun::UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	for (int i = 0; i < bulletContainer.size(); i++) {
		if (bulletContainer[i]->outOfScreen() || bulletContainer[i]->IsDeleted()) {
			delete bulletContainer[i];
			bulletContainer.erase(bulletContainer.begin() + i);
		}
		else {
			bulletContainer[i]->Update(dt, coObjects);
		}
	}
}
void CBoss1Gun::RenderBullet() {
	for (int i = 0; i < bulletContainer.size(); i++) {
		bulletContainer[i]->Render();
	}
}