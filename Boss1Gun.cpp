#include "Boss1Gun.h"
CBoss1Gun::CBoss1Gun(float x, float y) :CGameObject(x, y) {
	HP = 300;
	timeLeft = 0;
}
void CBoss1Gun::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (isExploded == false) {
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
	//RenderBox();
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