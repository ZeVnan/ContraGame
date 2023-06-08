#include "Boss1Shield.h"
CBoss1Shield::CBoss1Shield(float x, float y) :CGameObject(x, y) {
	HP = 500;
	timeLeft = 0;
}
void CBoss1Shield::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (isExploded == false) {
		if (HP <= 0) {
			SetState(BOSS1SHIELD_STATE_EXPLODE);
		}
	}
	else {
		timeLeft -= dt;
		if (timeLeft < 0) {
			SetState(BOSS1SHIELD_STATE_AFTER_EXPLODE);
		}
	}
	//DebugOutTitle(L"state = %d", state);
}
void CBoss1Shield::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	int d = 0;
	if (isExploded == false) {
		ani = BOSS1SHIELD_ANI_NORMAL;
	}
	else {
		if (state != BOSS1SHIELD_STATE_AFTER_EXPLODE) {
			ani = EXPLOSION_2_ANI;
		}
		else {
			ani = BOSS1SHIELD_ANI_AFTER_EXPLODE;
			d = 74;
		}
	}
	animations->Get(ani)->Render(x + d, y);
	if (state == BOSS1SHIELD_STATE_AFTER_EXPLODE)
		animations->Get(ARROW_ANI)->Render(x + 160, y);
	//RenderBox();
}
void CBoss1Shield::SetState(int state) {
	switch (state) {
	case BOSS1SHIELD_STATE_NORMAL:
		
		break;
	case BOSS1SHIELD_STATE_EXPLODE:
		isExploded = true;
		timeLeft = 3 * TIME_EXPLODE;
		break;
	case BOSS1SHIELD_STATE_AFTER_EXPLODE:

		break;
	}
	CGameObject::SetState(state);
}
void CBoss1Shield::CreateBox(DWORD dt) {
	bbox.left = x - BOSS1SHIELD_BOX_WIDTH / 2;
	bbox.top = y + BOSS1SHIELD_BOX_HEIGHT / 2;
	bbox.right = x + BOSS1SHIELD_BOX_WIDTH / 2;
	bbox.bottom = y - BOSS1SHIELD_BOX_HEIGHT / 2;
	bbox.vpf_x = 0;
	bbox.vpf_y = 0;
}
void CBoss1Shield::NoCollision(DWORD dt) {

}
void CBoss1Shield::CollisionWith(LPCOLLISIONEVENT e) {

}