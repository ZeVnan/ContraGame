#include "Fire.h"
CFire::CFire(float x, float y) :CGameObject(x, y) {
	timeLeft = FIRE_TIME / 2;
	vx = FIRE_SPEED;
	turn = false;
}
void CFire::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(FIRE_ANI)->Render(x, y);
}
void CFire::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (timeLeft > 0) {
		timeLeft -= dt;
		if (turn) {
			this->x += vx * dt;
		}
		else {
			this->x -= vx * dt;
		}

	}
	else {
		turn = ~turn;
		timeLeft = FIRE_TIME;
	}
}

void CFire::CreateBox(DWORD dt) {
	bbox.left = (x - FIRE_BOX_WIDTH / 2);
	bbox.top = (y + FIRE_BOX_HEIGHT / 2);
	bbox.right = (x + FIRE_BOX_WIDTH / 2);
	bbox.bottom = (y - FIRE_BOX_HEIGHT / 2);
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = 0;
}